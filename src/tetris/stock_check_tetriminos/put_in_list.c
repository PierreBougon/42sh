/*
** put_in_list.c for put_in_list in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Mar  2 11:47:01 2016 maud marel
** Last update Wed Jun  1 23:19:36 2016 bougon_p
*/

#include "tetris.h"

int		tcreate_list(t_tetris *tetris)
{
  t_list_tetri  *new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    return (-1);
  new->prev = new;
  new->next = new;
  tetris->list_tetri = new;
  return (0);
}

t_list_tetri	*tadd_list_after(t_list_tetri *old)
{
  t_list_tetri  *new;

  if ((new = malloc(sizeof(t_list_tetri))) == NULL)
    return (NULL);
  new->prev = old->prev;
  new->next = old;
  old->prev->next = new;
  old->prev = new;
  return (new);
}

t_list_tetri	*which_order(t_tetris *tetris, char *str)
{
  t_list_tetri	*new;
  t_list_tetri	*tmp;

  tmp = tetris->list_tetri->next;
  while (tmp != tetris->list_tetri && my_strcmp(str, tmp->tetrimino->name) > 0)
    tmp = tmp->next;
  if ((new = tadd_list_after(tmp)) == NULL)
    return (NULL);
  return (new);
}
