/*
** mecanich.c for  in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:40:29 2016 Mathieu Sauvau
** Last update Thu Mar 10 16:05:18 2016 Mathieu Sauvau
*/

#include <unistd.h>
#include "tetris.h"

void		update_board(t_tetris *tetris, t_tetri *tetri)
{
  int		x;
  int		y;
  int		pos_x;
  int		pos_y;

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  if (tetri->tetrimino[y][x] == '*')
	    {
	      pos_x = x + tetri->x - 1;
	      pos_y = y + tetri->y - 1;
	      tetris->board[pos_y][pos_x] = tetri->color;
	    }
	}
    }
}

void		clear_line(t_tetris *data, int line)
{
  int		x;

  x = -1;
  while (++x < data->options->col - 2)
    data->board[line][x] = 0;
}

void		fall(WINDOW *game, t_tetris *data)
{
  int		x;
  int		y;

  y = data->options->row - 2;
  while (--y >= 0)
    {
      x = data->options->col - 2;
      while (--x >= 0)
	{
	  if (y - 1 > 0
	      && data->board[y][x] == 0)
	    {
	      data->board[y][x] = data->board[y - 1][x];
	      data->board[y - 1][x] = 0;
	    }
	}
      usleep(100);
      wrefresh(game);
    }
}

void	update_level(t_tetris *data, WINDOW *game,
		     int *combo, int y)
{
  *combo += (*combo) * (*combo);
  ++data->lines;
  if (data->lines % 10 == 0)
    {
      ++data->level;
      data->speed = (float)(data->level) / (float)(1500);
    }
  clear_line(data, y);
  fall(game, data);
  data->score += (*combo) * 5;
}

void		line_completion(t_tetris *data, WINDOW *game)
{
  int		x;
  int		y;
  bool		is_complete;
  int		combo;

  y = -1;
  combo = 1;
  while (++y < data->options->row - 2)
    {
      x = -1;
      is_complete = true;
      while (++x < data->options->col - 2)
	{
	  if (data->board[y][x] == 0)
	    {
	      is_complete = false;
	      break;
	    }
	}
      if (is_complete)
	update_level(data, game, &combo, y);
    }
}
