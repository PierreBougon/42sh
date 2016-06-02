/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:39:59 2016 maud marel
** Last update Thu Jun  2 15:48:53 2016 bougon_p
*/

#include <time.h>
#include <stdlib.h>
#include "tetris.h"

bool		launch_all(t_tetris *tetris)
{
  if (!init_ncurses() && !check_window(tetris))
    return (false);
  init_score(tetris);
  tetris->start_time = time(0);
  if ((tetris->wscore = create_newwin(15, 22, 5, 0)) == NULL
      || (tetris->wnext = create_newwin(7, 15, 0,
					tetris->options->col + 35)) == NULL)
    return (false);
  show_score(tetris->wscore, tetris);
  if ((tetris->board = init_board(tetris)) == NULL)
    return (false);
  if ((tetris->wgame
       = create_newwin(tetris->options->row,
		       tetris->options->col, 0, 30)) == NULL)
    return (false);
  start_loop(tetris);
  return (true);
}

int		main()
{
  t_tetris	tetris;

  if (check_tetriminos(&tetris) == -1)
    return (-1);
  init_tetris(&tetris);
  verif_size_all(&tetris);
  srand(time(0));
  tetris.list_tetri = get_valid_tetri(tetris.list_tetri);
  if (!launch_all(&tetris))
    return (1);
  endwin();
  tfree_struct(&tetris);
  keypad(stdscr, false);
  printf("%s", tigetstr("smkx"));
  fflush(stdout);
  return (0);
}
