/*
** create_tree.c for create_tree in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Mon May 16 18:06:10 2016 marel_m
** Last update Mon May 16 22:05:46 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"

t_node		*one_node(char *arg, t_type type)
{
  t_node	*new;

  if ((new = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  new->left = NULL;
  new->right = NULL;
  new->type = type;
  if (arg != NULL)
    if ((new->arg = strdup(arg)) == NULL)
      return (NULL);
  return (new);
}

t_node		*new_node(char *arg_l, char *arg_r, t_type type)
{
  t_node	*new;

  if ((new = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  new->left = one_node(arg_l, type);
  new->right = one_node(arg_r, type);
  new->type = type;
  new->arg = NULL;
  return (new);
}

t_node		**insert_node(t_node **tree, char *arg_l, char *arg_r,
			      t_type type)
{
  t_node	*new;

  if (!(*tree))
    {
      if ((new = new_node(arg_l, arg_r, type)) == NULL)
	return (NULL);
      *tree = new;
      return (tree);
    }
  insert_node(&(*tree)->right, arg_l, arg_r, type);
  return (tree);
}

void            print_tab_arg_dir(char *arg, t_type type)
{
  if (arg)
    printf("%s %d\n", arg, type);
}

void            print_tree(t_node *tree)
{
  if (tree)
    {
      print_tab_arg_dir(tree->arg, tree->type);
      print_tree(tree->left);
      print_tree(tree->right);
    }
}
