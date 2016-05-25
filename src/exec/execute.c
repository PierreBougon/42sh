 /*
** execute.c for execute in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 13:27:57 2016 marel_m
** Last update Tue May 24 13:28:06 2016 marel_m
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

int	no_separator(t_sh *sh, t_node *tree)
{
  sh->exec->type = tree->type;
  if ((sh->exec->arg = my_str_to_word_tab(tree->arg, ' ')) == NULL
      || (sh->exec->exec = strdup(sh->exec->arg[0])) == NULL)
    return (1);
  return (0);
}

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

int	act_for_which_sep(t_sh *sh, UNUSED t_list_sh *list, t_node *tree)
{
  if (tree->arg != NULL)
    {
      if (tree->type == NO_ONE)
	{
	  if (no_separator(sh, tree))
	    return (1);
	}
      else if (tree->type == REDIR_RIGHT)
	{
	  if (redirection_right(sh, tree->left, tree->right))
	    return (1);
	}
      else if (tree->type == REDIR_LEFT)
	{
	  if (redirection_left(sh, tree->left, tree->right))
	    return (1);
	}
      else if (tree->type == DOUBLE_REDIR_RIGHT)
	{
	  if (double_redirection_right(sh, tree->left, tree->right))
	    return (1);
	}
      if (builtin_or_exec(sh))
	return (1);
    }
  return (0);
}

int	check_which_config(t_sh *sh, t_list_sh *list, t_node *tree)
{
  sh->exec->fd = 1;
  while (tree)
    {
      sh->exec->stop = 0;
      if (act_for_which_sep(sh, list, tree))
	return (1);
      free_exec(sh->exec);
      if (tree->right->right != NULL)
	tree = tree->right->right;
      else
	return (0);
    }
  return (0);
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
      if (check_which_config(sh, tmp, tmp->node))
	return (1);
      if (sh->exec->stop == 0 && tmp->type == DOUBLE_PIPE)
	while (tmp->type == DOUBLE_PIPE)
	  {
	    tmp = tmp->next;
	    i++;
	  }
      else if (sh->exec->stop == 1 && tmp->type == DOUBLE_AND)
	while (tmp->type == DOUBLE_AND)
	  {
	    tmp = tmp->next;
	    i++;
	  }
      else
	tmp = tmp->next;
      i++;
    }
  free_struct(sh);
  return (0);
}
