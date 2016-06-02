/*
** verif_size_all.c for verif_size_all in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar  4 21:14:35 2016 maud marel
** Last update Thu Mar 10 16:24:11 2016 Mathieu Sauvau
*/

#include <stdlib.h>
#include "tetris.h"

void	verif_size_all(t_tetris *tetris)
{
  t_list_tetri	*elem_next;

  elem_next = tetris->list_tetri->next;
  while (elem_next != tetris->list_tetri)
    {
      if (elem_next->tetrimino->width != 0)
	if (elem_next->tetrimino->height > tetris->options->row - 2
	    || elem_next->tetrimino->width > tetris->options->col - 2)
	  {
	    my_putstr_error("Size tetrimino too big for the board\n\n");
	    display_help_error();
	    exit(1);
	  }
      elem_next = elem_next->next;
    }
}
