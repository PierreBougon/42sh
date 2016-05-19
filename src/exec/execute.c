/*
** execute.c for execute in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 13:27:57 2016 marel_m
** Last update Wed May 18 20:33:35 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>
#include "42s.h"

int	no_separator(t_sh *sh, t_node *tree)
{
  if ((sh->exec->arg = my_str_to_word_tab(tree->arg, ' ')) == NULL
      || (sh->exec->exec = strdup(sh->exec->arg[0])) == NULL)
    return (1);
  return (0);
}

int	act_for_which_sep(t_sh *sh, UNUSED t_list_sh *list, t_node *tree)
{
  if (tree->arg != NULL)
    {
      if (tree->type == NO_ONE)
	if (no_separator(sh, tree))
	  return (1);
      if (builtin_or_exec(sh))
	return (1);
    }
  return (0);
}

int	check_which_config(t_sh *sh, t_list_sh *list, t_node *tree)
{
  if (tree)
    {
      if (act_for_which_sep(sh, list, tree))
	return (1);
      if (tree->left && tree->left->arg)
	if (act_for_which_sep(sh, list, tree->left))
	  return (1);
      check_which_config(sh, list, tree->right);
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
  tmp = sh->root;
  while (i < sh->lenght - 1)
    {
      i++;
      tmp = tmp->next;
      if (check_which_config(sh, tmp, tmp->node))
	return (1);
    }
  return (0);
}
