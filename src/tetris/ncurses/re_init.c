/*
** re_init.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu Mar 17 12:07:07 2016 Mathieu Sauvau
** Last update Fri Mar 18 13:13:44 2016 Mathieu Sauvau
*/

#include <unistd.h>
#include "tetris.h"

void	you_loose(t_tetris *data)
{
  char	buffer[10];

  werase(data->wgame);
  mvwprintw(stdscr, data->options->row / 2,
	    data->options->col / 2 - 4 + 30, "You Loose");
  mvwprintw(stdscr, data->options->row / 2 + 1,
	    data->options->col / 2 - 11 + 30, "Press a key to try again");
  wrefresh(data->wgame);
  wrefresh(stdscr);
  mode_canon(0, 0, 1);
  read(0, buffer, 10);
  werase(stdscr);
  show_logo(stdscr);
  wrefresh(stdscr);
}

void	clear_board(t_tetris *data)
{
  int	x;
  int	y;

  y = -1;
  while (++y < data->options->row - 2)
    {
      x = -1;
      while (++x < data->options->col - 2)
	data->board[y][x] = 0;
    }
}
