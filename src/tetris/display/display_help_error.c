/*
** display_help_error.c for display_help_error in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar  4 21:38:07 2016 maud marel
** Last update Sat Mar  5 09:15:28 2016 maud marel
*/

#include "tetris.h"

void	display_space_error(int i)
{
  while (++i < 25)
    my_putchar_error(' ');
}

void	display_help_end_error()
{
  my_putstr_error("  -kd --key-drop={K}");
  display_space_error(19);
  my_putstr_error("Set default DROP on key K\n");
  my_putstr_error("  -kq --key-quit={K}");
  display_space_error(19);
  my_putstr_error("Quit program when press key K\n");
  my_putstr_error("  -kp --key-pause={K}");
  display_space_error(20);
  my_putstr_error("Pause and restart game when press key K\n");
  my_putstr_error("  --map-size={row,col}");
  display_space_error(21);
  my_putstr_error("Set game size at row, col\n");
  my_putstr_error("  -w --without-next");
  display_space_error(18);
  my_putstr_error("Hide next tetrimino\n");
  my_putstr_error("  -d --debug");
  display_space_error(11);
  my_putstr_error("Debug mode\n");
}

void	display_help_error()
{
  my_putstr_error("Usage: ./tetris [options]\n");
  my_putstr_error("Options:\n");
  my_putstr_error("  --help");
  display_space_error(7);
  my_putstr_error("Display this help\n");
  my_putstr_error("  -l --level={num}");
  display_space_error(17);
  my_putstr_error("Start Tetris at level num\n");
  my_putstr_error("  -kl --key-left={K}");
  display_space_error(19);
  my_putstr_error("Move tetrimino on LEFT with key K\n");
  my_putstr_error("  -kr --key-right={K}");
  display_space_error(20);
  my_putstr_error("Move tetrimino on RIGHT with key K\n");
  my_putstr_error("  -kt --key-turn={K}");
  display_space_error(19);
  my_putstr_error("Turn tetrimino with key K\n");
  display_help_end_error();
  exit(1);
}
