/*
** bultin_or_exec.c for builtin_or_exec in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 17:16:18 2016 marel_m
** Last update Sat Jun  4 23:25:58 2016 Poc
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "42s.h"

int	action_redir(t_sh *sh)
{
  if (sh->exec->fd[0][1] != 1)
    {
      if (dup2(sh->exec->fd[0][1], 1) == -1)
  	return (1);
    }
  if (sh->exec->fd[0][0] != 0)
    {
      if (dup2(sh->exec->fd[0][0], 0) == -1)
  	return (1);
    }
  return (0);
}

int	close_all(int **fd, int max)
{
  int	i;

  i = 1;
  while (fd[i])
    {
      close(fd[i][0]);
      close(fd[i][1]);
      free(fd[i]);
      i++;
    }
  free(fd);
  return (0);
}

int	wait_func(t_pid *pid)
{
  int	status;
  t_pid	*tmp;

  tmp = pid;
  status = 0;
  while (pid)
    {
      waitpid(pid->pid, &status, 0);
      pid = pid->next;
    }
  return (0);
}

int	close_all_last_pipe(int **pipe, int pos)
{
  int	i;

  i = 1;
  while (pipe[i])
    {
      if (i != pos)
	{
	  close(pipe[pos][0]);
	  close(pipe[pos][1]);
	}
      i++;
    }
  return (0);
}

int	action(t_sh *sh)
{
  pid_t	pid;
  int	status;

  if ((pid = fork()) == -1)
    return (1);
  if (pid != 0)
    {
      close_all(sh->exec->fd, sh->actual_pipe);
      if (waitpid(pid, &status, 0) == -1)
	return (1);
      wait_func(sh->list);
      clear_list(sh->list);
      sh->list = NULL;
    }
  if (pid == 0)
    {
      close(sh->exec->fd[sh->actual_pipe][0]);
      dup2(sh->exec->fd[sh->actual_pipe][1], 1);
      if (action_redir(sh))
	return (1);
      if (execve(sh->exec->good_path, sh->exec->arg, sh->env->env) == -1)
	exit(1);
      exit(1);
    }
  else if (pid == 0 && sh->exec->fd[0][0] == 0 && sh->exec->fd[0][1] == 1)
    {
      if (WIFSIGNALED(status))
	{
	  write(2, "Segmentation fault\n", 19);
	  sh->exit = 1;
	  sh->exec->stop = 1;
	}
    }
  /* if (sh->exec->fd[0][0] != 0) */
  /*   { */
  /*     if (close(sh->exec->fd[0][0]) == -1 */
  /* 	  || waitpid(pid, &status, 0) == -1) */
  /* 	return (1); */
  /*   } */
  /* else if (sh->exec->fd[0][1] != 1) */
  /*   { */
  /*     if (close(sh->exec->fd[0][1]) == -1 */
  /* 	  || waitpid(pid, &status, 0) == -1) */
  /* 	return (1); */
  /*   } */
  return (0);
}

int	exec(t_sh *sh)
{
  int	i;

  sh->exec->good_path = NULL;
  if ((i = check_good_path(sh)) == 1)
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
