/*
** execute.c for execute in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 13:27:57 2016 marel_m
** Last update Sun Jun  5 17:21:55 2016 Poc
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "42s.h"
#include "fptrtab.h"

void		malloc_pipes(int **fd, int nb)
{
  int		j;

  j = 0;
  while (j < nb)
    {
      if ((fd[j] = malloc(sizeof(int) * 2)) == NULL)
	exit(1);
      if (j > 0)
	pipe(fd[j]);
      else
	{
	  fd[j][0] = -1;
	  fd[j][1] = -1;
	}
      j++;
    }
  fd[j] = NULL;
}

int		execute_each_act(t_sh *sh)
{
  int		i;
  t_list_sh	*tmp;

  if ((sh->exec = malloc(sizeof(t_exec))) == NULL)
    return (1);
  i = 0;
  tmp = sh->root->next;
  while (i < sh->lenght - 1)
    {
      sh->actual_pipe = 0;
      sh->exec->good_path = NULL;
      if ((sh->exec->fd = malloc(sizeof(int *) * (tmp->nb + 1))) == NULL)
	exit(1);
      malloc_pipes(sh->exec->fd, tmp->nb);
      if (check_which_config(sh, tmp, tmp->node) == 1)
	return (1);
      loop_execute(sh, &tmp, &i);
    }
  free_list(sh);
  my_free((void **)&(sh)->root);
  my_free((void **)&(sh->exec));
  return (0);
}
