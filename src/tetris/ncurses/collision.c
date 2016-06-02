/*
** collision.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:35:45 2016 Mathieu Sauvau
** Last update Sun Mar 20 13:18:05 2016 Mathieu Sauvau
*/

#include "tetris.h"

bool		space_occupied_down(t_tetris *data, t_tetri *tetri)
{
  int		x;
  int		y;
  int		last_star;

  y = -1;
  last_star = get_last_star_on_y(tetri);
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  if (tetri->y + y >= data->options->row - 2
	      && last_star == tetri->max - 1)
	    return (true);
	  if (tetri->y >= 0
	      && tetri->tetrimino[y][x] == '*'
	      && data->board[y + tetri->y][x + tetri->x - 1] != 0)
	    return (true);
	}
    }
  return (false);
}

bool		space_occupied_right(t_tetris *data, t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	if (tetri->y >= 0 && tetri->tetrimino[y][x] == '*'
	    && data->board[y + tetri->y - 1][x + tetri->x] != 0)
	  return (true);
    }
  return (false);
}

bool		space_occupied_left(t_tetris *data, t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  if (tetri->y >= 0 && tetri->tetrimino[y][x] == '*'
	      && data->board[y + tetri->y - 1][x + tetri->x - 2] != 0)
	    return (true);
	}
    }
  return (false);
}
