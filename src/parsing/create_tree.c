/*
** create_tree.c for create_tree in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Mon May 16 18:06:10 2016 marel_m
** Last update Sat Jun  4 15:11:23 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "fptrtab.h"
#include "42s.h"

t_node		*one_node(char *arg, t_type type)
{
  t_node	*new;

  if ((new = malloc(sizeof(t_node))) == NULL
      || memset(new, 0, sizeof(t_node)) == NULL)
    return (NULL);
  new->type = type;
  if (arg != NULL)
    {
      if ((new->arg = strdup(arg)) == NULL)
	return (NULL);
    }
  else
    new->arg = NULL;
  return (new);
}

t_node		*last_node(t_node *new, char *arg_l, t_type type)
{
  if ((new->arg = strdup(arg_l)) == NULL
      || (new->left = one_node(NULL, type)) == NULL
      || (new->right = one_node(NULL, type)) == NULL)
    return (NULL);
  return (new);
}

int		check_good_node_arg(t_node *new, t_type type)
{
  t_arg_act	*fptrtab;
  int		i;

  if ((fptrtab = init_tab_arg_sep()) == NULL)
    return (1);
  i = -1;
  while (++i < MAX_ACT)
    if (type == fptrtab[i].arg_act)
      {
	if (fptrtab[i].ft_arg_act(&new->arg))
	  return (free(fptrtab), 1);
	return (free(fptrtab), 0);
      }
  return (free(fptrtab), 0);
}

t_node		*new_node(char *arg_l, char *arg_r, t_type type)
{
  t_node	*new;

  if ((new = malloc(sizeof(t_node))) == NULL
      || memset(new, 0, sizeof(t_node)) == NULL)
    return (NULL);
  new->type = type;
  if (type == NO_ONE)
    return (last_node(new, arg_l, type));
  if (check_prior(arg_l) == 0)
    {
      if (check_good_node_arg(new, type))
	return (NULL);
    }
  else
    new->arg = NULL;
  if ((new->left = one_node(arg_l, type)) == NULL)
    return (NULL);
  if (check_prior(arg_r) == 0)
    if ((new->right = one_node(arg_r, type)) == NULL)
      return (NULL);
  return (new);
}

t_node		**insert_node(t_node **tree, char *arg_l, char *arg_r,
			      t_type type)
{
  t_node	*new;

  if (arg_l == NULL || arg_r == NULL)
    return (NULL);
  if (!(*tree))
    {
      if ((new = new_node(arg_l, arg_r, type)) == NULL)
	return (NULL);
      *tree = new;
      return (tree);
    }
  if ((insert_node(&(*tree)->right, arg_l, arg_r, type)) == NULL)
    return (NULL);
  return (tree);
}
