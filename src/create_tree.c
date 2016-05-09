/*
** create_tree.c for create_tree in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh/parsing
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat Apr 30 22:42:59 2016 marel_m
** Last update Mon May  9 14:16:48 2016 marel_m
*/

#include "42sh.h"

int		create_tree(t_sh *sh)
{
  t_node	*new;

  if ((new = malloc(sizeof(t_node))) == NULL)
    return (1);
  sh->tree = new;
  new->left = new;
  new->right = new;
  return (0);
}
