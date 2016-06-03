/*
** bultin_or_exec.c for builtin_or_exec in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 17:16:18 2016 marel_m
** Last update Sat Jun  4 00:19:38 2016 bougon_p
*/

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "42s.h"

void    signal_gest_init(char *ref[11])
{
  ref[0] = "Hangup";
  ref[1] = "";
  ref[2] = "Quit";
  ref[3] = "Illegal instruction";
  ref[4] = "Trace/breakpoint trap";
  ref[5] = "Aborted";
  ref[6] = "Bus Error";
  ref[7] = "Floating point exception";
  ref[8] = "";
  ref[9] = "";
  ref[10] = "Segmentation Fault";
}


int     signal_gest(int status, t_sh *sh, pid_t pid)
{
  char  *ref[11];
  int   index;

  if (zsig)
    job_list = update_job_list(job_list, sh->exec->exec, pid);
  zsig = false;
  signal_gest_init(ref);
  if (WIFSIGNALED(status))
    {
      index = (WTERMSIG(status) - 1);
      index %= 11;
      printf("%s", ref[index]);
      if (WCOREDUMP(status))
	printf(" (core dumped)\n");
      return (1);
    }
  return (0);
}


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

int	action(t_sh *sh)
{
  pid_t	pid;
  pid_t	pgid;
  int	status;

  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
    {
      if (action_redir(sh))
	return (1);
      printf("Fork done\n");
      pgid = getpgid(0);
      setpgid(0, pgid + 1);
      if (execve(sh->exec->good_path, sh->exec->arg, sh->env->env) == -1)
	{
	  printf("Execve failed\n");
	  exit(1);
	}
    }
  else if (pid != 0 && sh->exec->fd[0][0] == 0 && sh->exec->fd[0][1] == 1)
    {
      need_check = true;
      if (waitpid(pid, &status, WUNTRACED) == -1)
      	return (1);
      need_check = false;
      if (signal_gest(status, sh, pid))
	{
	  sh->exit = status;
	  sh->exec->stop = 1;
	}
    }
  if (sh->exec->fd[0][0] != 0)
    {
      if (close(sh->exec->fd[0][0]) == -1
  	  || waitpid(pid, &status, 0) == -1)
	return (1);
    }
  else if (sh->exec->fd[0][1] != 1)
    {
      if (close(sh->exec->fd[0][1]) == -1
  	  || waitpid(pid, &status, 0) == -1)
	return (1);
    }
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
  free(sh->exec->good_path);
  return (0);
}
