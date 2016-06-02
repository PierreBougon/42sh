/*
** init_options.c for init_options in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 19:30:09 2016 maud marel
** Last update Wed Jun  1 21:35:21 2016 bougon_p
*/

#include "tetris.h"
#include <curses.h>
#include <term.h>

int	init_direct(t_tetris *tetris)
{
  int	i;
  int	ret;

  i = setupterm(NULL, 0, &ret);
  if (i == ERR)
    display_help_error();
  if ((tetris->options->left = my_strdup(tigetstr("kcub1"))) == NULL
      || (tetris->options->right = my_strdup(tigetstr("kcuf1"))) == NULL
      || (tetris->options->turn = my_strdup(tigetstr("kcuu1"))) == NULL
      || (tetris->options->drop = my_strdup(tigetstr("kcud1"))) == NULL
      || (tetris->options->quit = my_strdup("q")) == NULL
      || (tetris->options->pause = my_strdup(" ")) == NULL)
    return (-1);
  return (0);
}

int	init_tetris(t_tetris *tetris)
{

  if ((tetris->options = malloc(sizeof(t_options))) == NULL)
    return (-1);
  tetris->options->level = 1;
  tetris->options->row = 22;
  tetris->options->col = 12;
  tetris->options->hide_next = 0;
  if (init_direct(tetris) == -1)
    return (-1);
  return (0);
}
