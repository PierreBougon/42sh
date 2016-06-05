/*
** bultin_or_exec.c for builtin_or_exec in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 17:16:18 2016 marel_m
** Last update Sun Jun  5 16:15:39 2016 Poc
*/

#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "42s.h"

int	father_action(t_sh *sh, int pid)
{
  int	status;
  char	*str;

  close_all(sh->exec->fd);
  if (pid != 0)
    {
      g_need_check = true;
      if (waitpid(pid, &status, WUNTRACED) == -1)
      	return (1);
      g_need_check = false;
      if (signal_gest(status, sh, pid, true))
	{
	  sh->exit = status;
	  sh->exec->stop = 1;
	}
    }
  wait_func(sh->list, sh);
  clear_list(sh->list);
  sh->list = NULL;
  if ((str = tigetstr("smkx")) != (char *)-1)
    {
      printf("%s", str);
      fflush(stdout);
    }
  return (change_read_mode(0, 100, 1), 0);
}

int	last_action(t_sh *sh, int pid)
{
  int	status;

  g_need_check = true;
  if (waitpid(pid, &status, WUNTRACED) == -1)
    return (1);
  g_need_check = false;
  if (signal_gest(status, sh, pid, true))
    {
      sh->exit = status;
      sh->exec->stop = 1;
    }
  return (0);
}

int	action(t_sh *sh)
{
  pid_t	pid;

  if ((pid = fork()) == -1)
    return (1);
  if (pid != 0 && father_action(sh, pid))
    return (1);
  if (pid == 0)
    {
      if (action_redir(sh, sh->actual_pipe))
      	  return (1);
      if (sh->exec->fd[0][0] != -1)
	dup2(sh->exec->fd[0][0], 0);
      if (sh->actual_pipe && sh->exec->fd[sh->actual_pipe])
	dup2(sh->exec->fd[sh->actual_pipe][1], 1);
      if ((check_builtin(sh)) == -3)
	{
	  change_read_mode(1, 0, 0);
	  execve(sh->exec->good_path, sh->exec->arg, sh->env->env);
	}
      exit(1);
    }
  else if (pid == 0 && sh->exec->fd[0][0] == -1 && sh->exec->fd[0][1] == -1)
    if (last_action(sh, pid))
      return (1);
  return (0);
}

int	exec(t_sh *sh)
{
  sh->exec->good_path = NULL;
  if (check_good_path(sh) == 1)
    return (1);
  if (action(sh))
    return (1);
  return (0);
}

int	builtin_or_exec(t_sh *sh)
{
  int	ret;

  if ((ret = check_builtin(sh)) == -3)
    {
      if ((ret = exec(sh)) != 0)
	return (ret);
    }
  else
    return (ret);
  return (0);
}
