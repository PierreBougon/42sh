/*
** rotate.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Mar 10 15:26:44 2016 Mathieu Sauvau
** Last update Thu Mar 10 15:27:21 2016 Mathieu Sauvau
*/

#include "tetris.h"

bool		check_space(t_tetri *tetri, char tetrimino[tetri->max][tetri->max],
			    t_tetris *tetris)
{
  int		x;
  int		y;
  int		first_star_x;
  int		last_star_x;

  y = -1;
  last_star_x = get_last_star_on_x(tetri);
  first_star_x = get_first_star_on_x(tetri);
  if (tetri->x + last_star_x > tetris->options->col - 2
      || tetri->x < -first_star_x + 2
      || tetri->y + tetri->height > tetris->options->row - 2)
    return (false);
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  if (tetri->y > 0 && tetrimino[y][x] == '*'
	      && tetris->board[y + tetri->y][x + tetri->x] != 0)
	    return (false);
	}
    }
  return (true);
}

void		cpy_tab_to_tetri(t_tetri *tetri,
				 char new_tab[tetri->max][tetri->max])
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	tetri->tetrimino[y][x] = new_tab[y][x];
    }
}

void		switch_w_h(t_tetri *tetri)
{
  int		tmp;

  tmp = tetri->width;
  tetri->width = tetri->height;
  tetri->height = tmp;
}

void		really_rotate(t_tetris *tetris, t_tetri *tetri,
			      char new[tetri->max][tetri->max],
			      char old[tetri->max][tetri->max])
{
  cpy_tab_to_tetri(tetri, new);
  if (!check_space(tetri, new, tetris))
    {
      switch_w_h(tetri);
      cpy_tab_to_tetri(tetri, old);
    }
}

t_tetri		*rotate_tetri(t_tetri *tetri, t_tetris *tetris)
{
  int		x;
  int		y;
  char		old[tetri->max][tetri->max];
  char		new[tetri->max][tetri->max];

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	old[y][x] = tetri->tetrimino[y][x];
    }
  y = -1;
  switch_w_h(tetri);
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	new[y][x] = tetri->tetrimino[tetri->max - x - 1][y];
    }
  really_rotate(tetris, tetri, new, old);
  return (tetri);
}
