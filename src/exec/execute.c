/*
** execute.c for execute in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 13:27:57 2016 marel_m
** Last update Wed Jun  1 13:15:13 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"
#include "fptrtab.h"

t_act	*init_tab_act()
{
  t_act	*tab;

  if ((tab = malloc(sizeof(t_act) * MAX_ACT)) == NULL
      || (tab[REDIR_RR].act = strdup(">>")) == NULL
      || (tab[REDIR_R].act = strdup(">")) == NULL
      || (tab[REDIR_L].act = strdup("<")) == NULL)
    return (NULL);
  tab[REDIR_RR].ft_act = &double_redirection_right;
  tab[REDIR_R].ft_act = &redirection_right;
  tab[REDIR_L].ft_act = &redirection_left;
  return (tab);
}

int	act_for_each_sep(t_sh *sh, t_node *tree, t_act *fptrtab)
{
  int	i;
  int	ret;

  i = -1;
  if (tree == NULL || tree->arg == NULL)
    return (1);
  while (++i < 3)
    if (strncmp(tree->arg, fptrtab[i].act, strlen(fptrtab[i].act)) == 0)
      {
	if ((ret = fptrtab[i].ft_act(sh, tree->left)) != 0)
	  return (ret);
	return (0);
      }
  sh->exec->type = tree->type;
  if ((sh->exec->arg = my_str_to_word_tab(tree->arg, ' ')) == NULL
      || sh->exec->arg[0] == NULL
      || (sh->exec->exec = strdup(sh->exec->arg[0])) == NULL)
    return (1);
  if ((ret = builtin_or_exec(sh)) != 0)
    return (ret);
  return (0);
}

int	check_which_config(t_sh *sh, t_list_sh *list, t_node *tree)
{
  t_act	*fptrtab;
  int	i;
  int	ret;

  if ((fptrtab = init_tab_act()) == NULL)
    return (1);
  i = -1;
  while (++i < list->nb)
    {
      sh->exec->stop = 0;
      if ((ret = act_for_each_sep(sh, tree, fptrtab)) != 0)
	return (free_tab_act(fptrtab), ret);
      if (tree->right)
	tree = tree->right;
    }
  free_tab_act(fptrtab);
  return (0);
}

void	loop_execute(t_sh *sh, t_list_sh **tmp, int *i)
{
  if (sh->exec->stop == 0 && (*tmp)->type == DOUBLE_PIPE)
    while ((*tmp)->type == DOUBLE_PIPE || (*tmp)->type == DOUBLE_AND)
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
}

int		execute_each_act(t_sh *sh)
{
  int		i;
  int		j;
  t_list_sh	*tmp;

  if ((sh->exec = malloc(sizeof(t_exec))) == NULL)
    return (1);
  i = 0;
  tmp = sh->root->next;
  while (i < sh->lenght - 1)
    {
      if ((sh->exec->fd = malloc(sizeof(int *) * (tmp->nb))) == NULL)
	return (1);
      j = -1;
      while (++j < tmp->nb)
	{
	  if ((sh->exec->fd[j] = malloc(sizeof(int) * 2)) == NULL)
	    return (1);
	  sh->exec->fd[j][0] = 1;
	  sh->exec->fd[j][1] = 1;
	}
      if (check_which_config(sh, tmp, tmp->node) == 1)
	return (1);
      loop_execute(sh, &tmp, &i);
    }
  return (free_struct(sh), 0);
}
