/*
** create_tree.c for minishell2 in /home/sauvau_m/rendu/PSU_2015_minishell2
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Mar 29 11:56:22 2016 Mathieu Sauvau
** Last update Sat May 14 16:41:15 2016 marel_m
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "42s.h"

t_node		*new_node(char *arg, t_type type)
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

t_node		**insert_node(t_node **tree, char *arg, t_type type, t_dir dir)
{
  t_node	*new;

  if (!(*tree))
    {
      if ((new = new_node(arg, type)) == NULL)
  	return (NULL);
      *tree = new;
      return (tree);
    }
  if (dir == LEFT)
    insert_node(&(*tree)->left, arg, type, dir);
  else if (dir == RIGHT)
    insert_node(&(*tree)->right, arg, type, dir);
  return (tree);
}

void		deltree(t_node *tree)
{
  if (tree)
    {
      if (tree->arg)
      	free(tree->arg);
      deltree(tree->left);
      deltree(tree->right);
      free(tree);
    }
}

void		print_tab_arg_dir(char *arg, t_type type)
{
  if (arg)
    printf("%s %d\n", arg, type);
  printf("\n");
}

void		print_tree(t_node *tree)
{
  if (tree)
    {
      print_tab_arg_dir(tree->arg, tree->type);
      print_tree(tree->left);
      print_tree(tree->right);
    }
}
