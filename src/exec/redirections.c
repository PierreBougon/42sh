/*
** redirections.c for redirections in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 20 13:59:36 2016 marel_m
** Last update Thu May 26 17:40:44 2016 marel_m
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "42s.h"

int	redirection_right(t_sh *sh, t_node *tree_l, t_node *tree_r)
{
  sh->exec->type = tree_l->type;
  if ((sh->exec->arg = my_str_to_word_tab(tree_r->arg, ' ')) == NULL
      || (sh->exec->exec = strdup(sh->exec->arg[0])) == NULL)
    return (1);
  if ((sh->exec->fd = open(tree_l->arg,
			   O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
    return (1);
  return (0);
}

int	redirection_left(t_sh *sh, t_node *tree_l, t_node *tree_r)
{
  sh->exec->type = tree_l->type;
  if ((sh->exec->arg = my_str_to_word_tab(tree_r->arg, ' ')) == NULL
      || (sh->exec->exec = strdup(sh->exec->arg[0])) == NULL)
    return (1);
  if ((sh->exec->fd = open(tree_l->arg, O_RDONLY)) == -1)
    return (1);
  return (0);
}

int	double_redirection_right(t_sh *sh, t_node *tree_l, t_node *tree_r)
{
  sh->exec->type = tree_l->type;
  if ((sh->exec->arg = my_str_to_word_tab(tree_r->arg, ' ')) == NULL
      || (sh->exec->exec = strdup(sh->exec->arg[0])) == NULL)
    return (1);
  if ((sh->exec->fd = open(tree_l->arg, O_CREAT | O_WRONLY | O_APPEND, 0644))
      == -1)
    return (1);
  return (0);
}
