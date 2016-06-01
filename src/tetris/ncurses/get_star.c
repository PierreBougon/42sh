/*
** get_star.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris/srcs/ncurses
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Mar 10 15:48:51 2016 Mathieu Sauvau
** Last update Thu Mar 10 15:49:11 2016 Mathieu Sauvau
*/

#include "tetris.h"

int		get_last_star_on_y(t_tetri *tetri)
{
  int		x;
  int		y;

  y = tetri->max;
  while (--y >= 0)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  if (tetri->tetrimino[y][x] == '*')
	    return (y);
	}
    }
  return (0);
}

int		get_first_star_on_x(t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  if (tetri->tetrimino[x][y] == '*')
	    return (y + 1);
	}
    }
  return (0);
}

int		get_last_star_on_x(t_tetri *tetri)
{
  int		x;
  int		y;

  x = tetri->max;
  while (--x >= 0)
    {
      y = -1;
      while (++y < tetri->max)
	{
	  if (tetri->tetrimino[y][x] == '*')
	    return (x);
	}
    }
  return (0);
}
