/*
** print_game.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:37:35 2016 Mathieu Sauvau
** Last update Thu Mar 10 16:06:06 2016 Mathieu Sauvau
*/

#include "tetris.h"

void	print_game(WINDOW *game, t_tetris *data, t_tetri *tetri)
{
  int	x;
  int	y;

  werase(game);
  y = -1;
  while (++y < data->options->row - 2)
    {
      x = -1;
      while (++x < data->options->col - 2)
  	{
  	    if (data->board[y][x] != 0)
  	      {
  		wattron(game, COLOR_PAIR(data->board[y][x]));
  		mvwprintw(game, y + 1, x + 1, "*\n");
  		wattroff(game, COLOR_PAIR(data->board[y][x]));
  	      }
  	}
    }
  wborder(game, '|', '|', '-', '-', '+', '+', '+', '+');
  print_tetri(game, tetri);
}

void		print_tetri(WINDOW *game, t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  wattron(game, COLOR_PAIR(tetri->color));
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max)
	{
	  if (tetri->tetrimino[y][x] == '*')
	    mvwprintw(game, tetri->y + y, tetri->x + x,
		      "%c", tetri->tetrimino[y][x]);
	}
    }
  wrefresh(game);
  wattroff(game, COLOR_PAIR(tetri->color));
}

void		show_next(WINDOW *wnext, t_tetri *next)
{
  werase(wnext);
  wborder(wnext, '|', '|', '-', '-', '+', '+', '+', '+');
  mvwprintw(wnext, 0, 1, "Next");
  next->x = 5;
  next->y = 2;
  print_tetri(wnext, next);
  wrefresh(wnext);
}

void		show_score(WINDOW *wscore, t_tetris *tetris)
{
  mvwprintw(wscore, 1, 1, "High Score");
  mvwprintw(wscore, 1, 15, "%d\n", tetris->high_score);
  mvwprintw(wscore, 2, 1, "Score");
  mvwprintw(wscore, 2, 15, "%d\n", tetris->score);
  mvwprintw(wscore, 4, 1, "Lines");
  mvwprintw(wscore, 4, 15, "%d\n", tetris->lines);
  mvwprintw(wscore, 5, 1, "Level");
  mvwprintw(wscore, 5, 15, "%d\n", tetris->level);
  mvwprintw(wscore, 7, 1, "Timer");
  mvwprintw(wscore, 7, 15, "%d:", tetris->time / 60);
  mvwprintw(wscore, 7, 17, "%.2d\n", tetris->time % 60);
  box(wscore, 0 , 0);
  wrefresh(wscore);
}
