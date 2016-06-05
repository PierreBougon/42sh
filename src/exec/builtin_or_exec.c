/*
** bultin_or_exec.c for builtin_or_exec in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 17:16:18 2016 marel_m
** Last update Sat Jun  4 23:42:02 2016 Poc
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

int     signal_gest(int status, t_sh *sh, pid_t pid, bool stock)
{
  char  *ref[11];
  int   index;

  change_read_mode(0, 100, 1);
  if (zsig && !WIFEXITED(status) && stock)
    job_list = update_job_list(job_list, sh->exec->exec, pid);
  else if (job_list && job_list->prev->state == FG
  	   && last_fg && !zsig)
    job_list = erase_job(job_list->prev, job_list);
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

int	close_all(int **fd)
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
      close_all(sh->exec->fd);
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
      need_check = true;
      if (waitpid(pid, &status, WUNTRACED) == -1)
      	return (1);
      need_check = false;
      if (signal_gest(status, sh, pid, true))
      	{
      	  sh->exit = status;
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
