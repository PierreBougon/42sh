/*
** main_loop.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:43:17 2016 Mathieu Sauvau
** Last update Wed Jun  1 21:47:47 2016 bougon_p
*/

#include <termios.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>
#include "tetris.h"

void		done(t_tetris *tetris,
		     t_tetri **tetri, t_tetri **next)
{
  if (!can_move_down(tetris, *tetri))
    {
      update_board(tetris, (*tetri));
      line_completion(tetris, tetris->wgame);
      free_tetri(*tetri);
      *tetri = *next;
      (*tetri)->x = tetris->options->col / 2 - (*tetri)->width / 2;
      (*tetri)->y = 0;
      *next = random_tetri(tetris->list_tetri, tetris->nb_tetri);
    }
  if (!can_move_down(tetris, *tetri))
    {
      recup_high_score(tetris);
      you_loose(tetris);
      clear_board(tetris);
      tetris->high_score = tetris->score;
      tetris->score = 0;
      mode_canon(1, 0, 0);
    }
}

void		do_(WINDOW *game, t_tetris *tetris, t_tetri *tetri)
{
  if (tetris->i > 8)
    {
      if (can_move_down(tetris, tetri))
	tetri->y += 1;
      print_game(game, tetris, tetri);
      tetris->moved = false;
      tetris->i = 0;
    }
  usleep(1);
}

void		last_call(WINDOW *game, t_tetris *tetris,
			  t_tetri *tetri)
{
  while (tetris->i < 20)
    {
      read_key(tetris, tetri);
      print_game(game, tetris, tetri);
    }
}

void		main_loop(t_tetris *tetris, t_tetri *tetri, t_tetri *next)
{
  tetris->save_time = 0;
  while (true)
    {
      if (!can_move_down(tetris, tetri))
	{
	  last_call(tetris->wgame, tetris, tetri);
	  done(tetris, &tetri, &next);
	  if (tetris->options->hide_next == 0)
	    show_next(tetris->wnext, next);
	}
      if (!tetris->pause)
	tetris->time = time(0) - tetris->start_time - tetris->save_time;
      else
	tetris->save_time = time(0) - tetris->start_time - tetris->time;

      show_score(tetris->wscore, tetris);
      read_key(tetris, tetri);
      if (tetris->quit)
	break;
      do_(tetris->wgame, tetris, tetri);
    }
}

void		start_loop(t_tetris *tetris)
{
  t_tetri	*tetri;
  t_tetri	*next;

  tetri = init_first_loop(tetris);
  tetris->key_tab = get_fct_key(tetris);
  next = random_tetri(tetris->list_tetri, tetris->nb_tetri);
  if (tetris->options->hide_next == 0)
    show_next(tetris->wnext, next);
  main_loop(tetris, tetri, next);
}
