/*
** redirections.c for redirections in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 20 13:59:36 2016 marel_m
** Last update Sun May 29 20:40:55 2016 marel_m
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "42s.h"

int	redirection_right(t_sh *sh, t_node *tree)
{
  sh->exec->type = tree->type;
  if ((sh->exec->fd = open(tree->arg,
			   O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
    return (1);
  return (0);
}

int	redirection_left(t_sh *sh, t_node *tree)
{
  sh->exec->type = tree->type;
  if ((sh->exec->fd = open(tree->arg, O_RDONLY)) == -1)
    return (1);
  return (0);
}

int	double_redirection_right(t_sh *sh, t_node *tree)
{
  printf("toto\n");
  sh->exec->type = tree->type;
  if ((sh->exec->fd = open(tree->arg, O_CREAT | O_WRONLY | O_APPEND, 0644))
      == -1)
    return (1);
  return (0);
}
