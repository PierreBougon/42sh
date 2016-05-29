/*
** execute.c for execute in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 13:27:57 2016 marel_m
** Last update Sun May 29 15:37:17 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"
#include "fptrtab.h"

int	no_separator(t_sh *sh, t_node *tree, UNUSED t_node *tree_bis)
{
  sh->exec->type = tree->type;
  if ((sh->exec->arg = my_str_to_word_tab(tree->arg, ' ')) == NULL
      || (sh->exec->exec = strdup(sh->exec->arg[0])) == NULL)
    return (1);
  return (0);
}

t_act	*init_tab_act()
{
  t_act	*tab;

  if ((tab = malloc(sizeof(t_act) * MAX_ACT)) == NULL)
    return (NULL);
  tab[NOTHING].act = NO_ONE;
  tab[NOTHING].ft_act = &no_separator;
  tab[REDIR_R].act = REDIR_RIGHT;
  tab[REDIR_R].ft_act = &redirection_right;
  tab[REDIR_L].act = REDIR_LEFT;
  tab[REDIR_L].ft_act = &redirection_left;
  tab[REDIR_RR].act = DOUBLE_REDIR_RIGHT;
  tab[REDIR_RR].ft_act = &double_redirection_right;
  return (tab);
}

int	act_for_which_sep(t_sh *sh, UNUSED t_list_sh *list, t_node *tree)
{
  int	i;
  t_act	*fptrtab;

  if (tree->arg != NULL)
    {
      if ((fptrtab = init_tab_act()) == NULL)
	return (1);
      i = -1;
      while (++i < 4)
	if (tree->type == fptrtab[i].act && i == 0)
	  {
	    if (fptrtab[i].ft_act(sh, tree, tree))
	      return (1);
	  }
	else if (tree->type == fptrtab[i].act)
	  {
	    if (fptrtab[i].ft_act(sh, tree->left, tree->right))
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

int	loop_execute(t_sh *sh, t_list_sh **tmp, int *i)
{
  if (sh->exec->stop == 0 && (*tmp)->type == DOUBLE_PIPE)
    while ((*tmp)->type == DOUBLE_PIPE)
      {
	(*tmp) = (*tmp)->next;
	(*i)++;
      }
  else if (sh->exec->stop == 1 && (*tmp)->type == DOUBLE_AND)
    while ((*tmp)->type == DOUBLE_AND)
      {
	(*tmp) = (*tmp)->next;
	(*i)++;
      }
  else
    (*tmp) = (*tmp)->next;
  (*i)++;
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
      if (check_which_config(sh, tmp, tmp->node)
	  || loop_execute(sh, &tmp, &i))
	return (1);
    }
  free_struct(sh);
  return (0);
}
