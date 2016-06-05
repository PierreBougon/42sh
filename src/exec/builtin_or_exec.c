/*
** bultin_or_exec.c for builtin_or_exec in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 17:16:18 2016 marel_m
** Last update Sun Jun  5 15:23:23 2016 Poc
*/

#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "42s.h"

int	action_redir(t_sh *sh, int pipe_nb)
{
  if (sh->exec->fd[0][1] != -1 && !pipe_nb)
    {
      if (dup2(sh->exec->fd[0][1], 1) == -1)
      	return (1);
    }
  if (sh->exec->fd[0][0] != -1)
    {
      if (pipe_nb)
	{
	  if (dup2(sh->exec->fd[0][0], sh->exec->fd[pipe_nb][0]) == -1)
	    return (1);
	}
      else if (dup2(sh->exec->fd[0][0], 0) == -1)
	return (1);
    }
  return (0);
}

int	close_all(int **fd)
{
  int	i;

  i = 1;
  if (fd[0][1] != -1)
    close (fd[0][1]);
  if (fd[0][0] != -1)
    close (fd[0][0]);
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

int	wait_func(t_pid *pid, t_sh *sh)
{
  int	status;

  status = 0;
  while (pid)
    {
      waitpid(pid->pid, &status, WUNTRACED);
      signal_gest(status, sh, pid->pid, 0);
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
