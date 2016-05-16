/*
** create_list.c for create_list in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Mon May 16 09:55:21 2016 marel_m
** Last update Mon May 16 10:39:28 2016 marel_m
*/

#include <stdlib.h>
#include "42s.h"

int		create_list(t_sh *sh)
{
  t_list_sh	*new;

  if ((new = malloc(sizeof(t_list_sh))) == NULL)
    return (1);
  sh->root = new;
  new->prev = new;
  new->next = new;
  sh->lenght = 1;
  return (0);
}

t_list_sh	*add_list_after(t_sh *sh)
{
  t_list_sh	*new;

  if ((new = malloc(sizeof(t_list_sh))) == NULL)
    return (NULL);
  if (sh->root != NULL)
    {
      new->prev = sh->root->prev;
      new->next = sh->root;
      sh->root->prev->next = new;
      sh->root->prev = new;
    }
      sh->lenght++;
  return (new);
}
