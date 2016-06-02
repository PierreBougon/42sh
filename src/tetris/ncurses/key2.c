/*
** key2.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Mar  8 17:47:24 2016 Mathieu Sauvau
** Last update Thu Mar 17 11:36:51 2016 Mathieu Sauvau
*/

#include "tetris.h"

void			rotate(t_tetris *data, t_tetri *tetri)
{
  if (tetri->y + tetri->width < data->options->row - 2)
    rotate_tetri(tetri, data);
}

void			drop(t_tetris *data, UNUSED t_tetri *tetri)
{
  if (!data->pause)
    data->i += 5;
}

void			quit(t_tetris *data, UNUSED t_tetri *tetri)
{
  data->quit = true;
}

void			do_pause(t_tetris *data, UNUSED t_tetri *tetri)
{
  data->pause = !data->pause;
}

void		reset_buffer(char *buffer)
{
  int		i;

  i = -1;
  while (++i < 10)
    buffer[i] = 0;
}
