/*
** print_tree.c for print_tree in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 27 21:27:09 2016 marel_m
** Last update Fri May 27 21:28:05 2016 marel_m
*/

#include <stdio.h>
#include "42s.h"

void            print_tab_arg_dir(char *arg, t_type type)
{
  if (arg)
    printf("%s %d\n", arg, type);
  else
    printf("\n");
}

void            print_tree(t_node *tree)
{
  if (tree)
    {
      printf("node-> ");
      print_tab_arg_dir(tree->arg, tree->type);
      if (tree->left && tree->left->arg)
	{
	  printf("left-> ");
	  print_tab_arg_dir(tree->left->arg, tree->left->type);
	}
      print_tree(tree->right);
    }
}
