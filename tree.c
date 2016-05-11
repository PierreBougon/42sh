/*
** create_tree.c for minishell2 in /home/sauvau_m/rendu/PSU_2015_minishell2
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Mar 29 11:56:22 2016 Mathieu Sauvau
** Last update Thu Mar 31 15:09:21 2016 Mathieu Sauvau
*/

#include "sh.h"

t_node		*new_node(char **arg, char type)
{
  t_node	*new;

  if ((new = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  new->left = NULL;
  new->right = NULL;
  new->type = type;
  new->arg = arg;
  return (new);
}

t_list_tree	*new_tree(t_node *tree)
{
  t_list_tree	*new;

  if ((new = malloc(sizeof(t_list_tree))) == NULL)
    return (NULL);
  new->next = NULL;
  new->tree = tree;
  return (new);
}

void	add_tree(t_list_tree **tree, t_list_tree *new)
{
  if (!*tree)
      *tree = new;
  else
    {
      new->next = *tree;
      (*tree) = new;
    }
}

t_node		**insert_node(t_node **tree, char **arg, char type, e_dir dir)
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
	free_tab_arg(tree->arg);
      deltree(tree->left);
      deltree(tree->right);
      free(tree);
    }
}

void		del_all_tree(t_list_tree *tree)
{
  t_list_tree	*tmp;

  while (tree)
    {
      tmp = tree;
      tree = tree->next;
      deltree(tmp->tree);
      free(tmp);
    }
}



void		print_tab_arg_dir(char **arg, char type, e_dir dir)
{
  int		i;

  i = -1;
  if (dir == RIGHT)
    my_printf("-- RIGHT -- :\n");
  else
    my_printf("-- LEFT -- :\n");
  if (arg)
    {
      while (arg[++i])
	my_printf("arg[%d] - %s\n", i, arg[i]);
    }
  else
    my_printf("TYPE %c\n", type);
  my_printf("\n");
}

void		print_tree(t_node *tree, e_dir dir)
{
  if (tree)
    {
      print_tab_arg_dir(tree->arg, tree->type, dir);
      print_tree(tree->left, LEFT);
      print_tree(tree->right, RIGHT);
    }
}

void		print_all_tree(t_list_tree *tree)
{
  int		i;

  i = 0;
  while (tree)
    {
      my_printf("-------- TREE %d -----------\n", i);
      print_tree(tree->tree, RIGHT);
      ++i;
      my_printf("-------------------------\n");
      tree = tree->next;
    }
}

/* void		invert_tree_list(t_list_tree *tree) */
/* { */
/*   t_list_tree	*invert; */

/*   while (tree) */
/*     { */
/*       invert */
/*       tree = tree->next; */
/*     } */
/* } */
