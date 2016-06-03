/*
** pipe.c for pipe in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu May 26 13:16:31 2016 marel_m
** Last update Fri Jun  3 17:36:31 2016 Poc
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "42s.h"

void	show_pipe(int *pipe)
{
  char	buffer[10400];

  printf("Showpipe\n");
  read(pipe[0], buffer,  10400);
  printf("|%s|\n", buffer);
}

int	execute_first_pipe(t_sh *sh)
{
  printf("Exectute first %d\n", sh->actual_pipe);
  printf("fd[1][0] = %d\n", sh->exec->fd[1][0]);
  close(sh->exec->fd[1][1]);
  dup2(sh->exec->fd[1][0], 0);
  if (execve(sh->exec->good_path, sh->exec->arg, sh->env->env) == -1)
    printf("CACAOUETTE\n");
  exit(1);
}

int	execute_in_son(t_sh *sh)
{
  printf("Exectue in son %d\n", sh->actual_pipe);
  printf("fd[%d][0] = %d\nfd[%d][1] = %d\n", sh->actual_pipe + 1, sh->exec->fd[sh->actual_pipe + 1][0], sh->actual_pipe, sh->exec->fd[sh->actual_pipe][1]);
  close(sh->exec->fd[sh->actual_pipe + 1][1]);
  close(sh->exec->fd[sh->actual_pipe][0]);
  dup2(sh->exec->fd[sh->actual_pipe + 1][0], 0);
  dup2(sh->exec->fd[sh->actual_pipe][1], 1);
  if (execve(sh->exec->good_path, sh->exec->arg, sh->env->env) == -1)
    printf("CACAOUETTE\n");
  exit (1);
}

int	pipes(t_sh *sh, t_node *node)
{
  int		chid;

  sh->exec->type = node->type;
  printf("\nnode->args = %s\n", node->arg);
  printf("actual_pipe = %d\n", sh->actual_pipe);
  sh->exec->arg = my_str_to_word_tab(node->arg, ' ');
  sh->exec->exec = strdup(sh->exec->arg[0]);
  check_good_path(sh);
  printf("check_good_path\n");
  if ((chid = fork()) == -1)
    return (1);
  if (chid == 0)
    {
      if (!sh->actual_pipe)
	{
	  if (execute_first_pipe(sh))
	    exit (1);
	  close(sh->exec->fd[1][0]);
	}
      else
	{
	  if (execute_in_son(sh))
	    exit (1);
	  close(sh->exec->fd[sh->actual_pipe][0]);
	}
      exit (1);
    }
  /* show_pipe(sh->exec->fd[0]); */
  sh->actual_pipe++;
  return (0);
}
