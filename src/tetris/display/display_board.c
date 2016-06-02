/*
** display_board.c for display_board in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 18 23:37:50 2016
** Last update Mon Mar 21 10:56:27 2016 Marel la plus belle <3
*/

#include "tetris.h"

WINDOW		*create_newwin(int height, int width, int starty, int startx)
{
  WINDOW	*local_win;

  local_win = newwin(height, width, starty, startx);
  wborder(local_win, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(local_win);
  return (local_win);
}

void		show_board(t_tetris *tetris)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetris->options->row - 2)
    {
      x = -1;
      while (++x < tetris->options->col - 2)
	mvprintw(y, x + 60, "%d", tetris->board[y][x]);
      printw("\n");
    }
}

void		show_tetri(t_tetri *tetri)
{
  int		x;
  int		y;

  y = -1;
  while (++y < tetri->max)
    {
      x = -1;
      while (++x < tetri->max);
    }
}

void		show_list_tetri(t_list_tetri *elem)
{
  t_list_tetri	*elem_next;

  elem_next = elem->next;
  while (elem_next != elem)
    {
      show_tetri(elem_next->tetrimino);
      elem_next = elem_next->next;
    }
}

void		show_logo(WINDOW *win)
{
  mvwprintw(win, 0, 0, "***  ** *** *** * ***\n");
  mvwprintw(win, 1, 0, " *   *   *  * *   *  \n");
  mvwprintw(win, 2, 0, " *   **  *   ** * ***\n");
  mvwprintw(win, 3, 0, " *   *   *  * * *   *\n");
  mvwprintw(win, 4, 0, " *   **  *  * * * ***\n");
  wrefresh(win);
}
