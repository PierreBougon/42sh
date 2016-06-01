/*
** double_left.c for azd in /home/debrau_c/Documents/cours/PSU/PSU_2015_42sh/src
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Wed Jun  1 20:57:19 2016 debrau_c
** Last update Wed Jun  1 21:07:29 2016 debrau_c
*/

#include <stdio.h>
#include "42s.h"

int	double_redir_left(UNUSED t_sh *sh, t_node *node)
{
  printf("arg : %s\n", node->arg);
  printf("type : %d\n", node->type);
  printf("left : %p\tright : %p\n", node->left, node->right);
  return (0);
}
