/*
** redirections.c for redirections in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 20 13:59:36 2016 marel_m
** Last update Sat Jun  4 21:26:41 2016 marel_m
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "42s.h"

int	redirection_right(t_sh *sh, t_node *tree)
{
  sh->exec->type = tree->type;
  if ((sh->exec->fd[0][1] = open(tree->arg,
				 O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
    return (1);
  return (0);
}

int	redirection_left(t_sh *sh, t_node *tree)
{
  sh->exec->type = tree->type;
  if ((sh->exec->fd[0][0] = open(tree->arg, O_RDONLY)) == -1)
    {
      write(2, tree->arg, strlen(tree->arg));
      write(2, ": No such file or directory.\n", 29);
      sh->exit = 1;
      return (-1);
    }
  return (0);
}

int	double_redirection_right(t_sh *sh, t_node *tree)
{
  sh->exec->type = tree->type;
  if ((sh->exec->fd[0][1] =
       open(tree->arg, O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1)
    return (1);
  return (0);
}
