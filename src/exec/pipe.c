/*
** pipe.c for pipe in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu May 26 13:16:31 2016 marel_m
** Last update Thu Jun  2 17:32:33 2016 Poc
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "42s.h"

void	show_pipe(int *pipe)
{
  char	buffer[10400];

  read(pipe[0], buffer,  10400);
  printf("%s\n", buffer);
}

int	execute_first_pipe(t_sh *sh)
{
  /* close (sh->exec->fd[0][1]); */
  printf("%d\n%d\n", sh->exec->fd[0][0], sh->exec->fd[1][1]);
  dup2(sh->exec->fd[0][0], 0);
  dup2(sh->exec->fd[1][0], 0);
  if (execve(sh->exec->good_path, sh->exec->arg, sh->env->env) == -1)
    printf("CACAOUETTE\n");
  exit (1);
  printf("oups\n");
  sh = sh;
  return (0);
}

int	execute_in_son(t_sh *sh)
{
  sh = sh;
  return (0);
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
  if ((chid = fork()) == -1)
    return (1);
  if (chid == 0)
    {
      if (!sh->actual_pipe && execute_first_pipe(sh))
	exit (1);
      else if (sh->actual_pipe && execute_in_son(sh))
	exit (1);
      exit (1);
    }
  /* show_pipe(sh->exec->fd[0]); */
  sh->actual_pipe++;
  return (0);
}
