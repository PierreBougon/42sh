/*
** execute.c for execute in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 13:27:57 2016 marel_m
** Last update Wed May 18 18:44:37 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>
#include "42s.h"

int	no_separator(t_sh *sh, t_node *tree)
{
  sh->exec->arg = my_str_to_word_tab(tree->arg, ' ');
  sh->exec->exec = strdup(sh->exec->arg[0]);
  return (0);
}

int	act_for_which_sep(t_sh *sh, UNUSED t_list_sh *list, t_node *tree)
{
  if (tree->arg != NULL)
    {
      if (tree->type == NO_ONE)
	no_separator(sh, tree);
      builtin_or_exec(sh);
    }
  return (0);
}

int	check_which_config(t_sh *sh, t_list_sh *list, t_node *tree)
{
  if (tree)
    {
      act_for_which_sep(sh, list, tree);
      if (tree->left && tree->left->arg)
	act_for_which_sep(sh, list, tree->left);
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
      check_which_config(sh, tmp, tmp->node);
    }
  return (0);
}
