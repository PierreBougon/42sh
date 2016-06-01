/*
** purge_tetri.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:46:31 2016 Mathieu Sauvau
** Last update Thu Mar 10 16:29:20 2016 Mathieu Sauvau
*/

#include "tetris.h"

t_list_tetri	*get_valid_tetri(t_list_tetri *all_tetri)
{
  t_list_tetri	*valid;
  t_list_tetri	*tmp;

  valid = all_tetri->next;
  tmp = NULL;
  while (valid != all_tetri)
    {
      if (valid->tetrimino->width == 0)
	{
	  tmp = valid;
	  valid->prev->next = valid->next;
	  valid->next->prev = valid->prev;
	  free(tmp->tetrimino->name);
	  free(tmp->tetrimino);
	}
      valid = valid->next;
    }
  return (valid);
}

void		center_tetri(t_list_tetri *list_tetri)
{
  t_list_tetri	*elem_next;
  int		x;
  int		y;

  elem_next = list_tetri->next;
  while (elem_next != list_tetri)
    {
      y = -1;
      while (++y < elem_next->tetrimino->max)
	{
	  x = -1;
	  while (++x < elem_next->tetrimino->max)
	    {
	      if (elem_next->tetrimino->tetrimino[y][x] != '*')
		elem_next->tetrimino->tetrimino[y][x] = ' ';
	    }
	}
      elem_next = elem_next->next;
    }
}
