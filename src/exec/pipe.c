/*
** pipe.c for pipe in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu May 26 13:16:31 2016 marel_m
** Last update Sun Jun  5 03:27:08 2016 Poc
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "42s.h"

void	close_all_first_pipe(int **fd, int target)
{
  int	i;

  i = 1;
  while (fd[i])
    {
      if (i != target)
	{
	  close(fd[i][1]);
	  close(fd[i][0]);
	}
      i++;
    }
}

void	execute_first_pipe(t_sh *sh)
{
  close(sh->exec->fd[1][1]);
  close_all_first_pipe(sh->exec->fd, 1);
  if (sh->exec->fd[0][1] != -1)
    dup2(sh->exec->fd[0][1], 1);
  dup2(sh->exec->fd[1][0], 0);
  if ((check_builtin(sh)) == -3)
    execve(sh->exec->good_path, sh->exec->arg, sh->env->env);
  exit(1);
}

void	close_all_execute_in_son(int **fd, int target, int next_target)
{
  int	i;

  i = 1;
  while (fd[i])
    {
      if (i == target)
	close(fd[i][0]);
      else if (i == next_target)
	close(fd[i][1]);
      else
	{
	  close(fd[i][1]);
	  close(fd[i][0]);
	}
      i++;
    }
}

int	execute_in_son(t_sh *sh)
{
  close_all_execute_in_son(sh->exec->fd, sh->actual_pipe, sh->actual_pipe + 1);
  close(sh->exec->fd[sh->actual_pipe + 1][1]);
  close(sh->exec->fd[sh->actual_pipe][0]);
  dup2(sh->exec->fd[sh->actual_pipe + 1][0], 0);
  dup2(sh->exec->fd[sh->actual_pipe][1], 1);
  if ((check_builtin(sh)) == -3)
    execve(sh->exec->good_path, sh->exec->arg, sh->env->env);
  exit(1);
}

int	pipes(t_sh *sh, t_node *node)
{
  int		chid;

  sh->is_pipe = true;
  sh->exec->type = node->type;
  sh->exec->arg = my_str_to_word_tab(node->arg, ' ');
  sh->exec->exec = strdup(sh->exec->arg[0]);
  check_good_path(sh);
  if ((chid = fork()) == -1)
    return (1);
  if (!chid)
    {
      if (sh->actual_pipe == 0)
	{
	  execute_first_pipe(sh);
	  close(sh->exec->fd[1][0]);
	  exit (1);
	}
      else
	{
	  execute_in_son(sh);
	  close(sh->exec->fd[sh->actual_pipe + 1][0]);
	  close(sh->exec->fd[sh->actual_pipe + 1][1]);
	  exit (1);
	}
      exit (1);
    }
  add_to_back(&sh->list, chid);
  sh->actual_pipe++;
  return (0);
}
