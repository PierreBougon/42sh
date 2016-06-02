/*
** display_help.c for display_help in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:53:52 2016 maud marel
** Last update Mon Mar  7 13:35:22 2016 maud marel
*/

#include "tetris.h"

void	display_space(int i)
{
  while (++i < 25)
    my_putchar(' ');
}

void	display_help_end()
{
  my_putstr("  -kd --key-drop={K}");
  display_space(19);
  my_putstr("Set default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}");
  display_space(19);
  my_putstr("Quit program when press key K\n");
  my_putstr("  -kp --key-pause={K}");
  display_space(20);
  my_putstr("Pause and restart game when press key K\n");
  my_putstr("  --map-size={row,col}");
  display_space(21);
  my_putstr("Set game size at row, col\n");
  my_putstr("  -w --without-next");
  display_space(18);
  my_putstr("Hide next tetrimino\n");
  my_putstr("  -d --debug");
  display_space(11);
  my_putstr("Debug mode\n");
}

void	display_help(char *str)
{
  my_putstr("Usage: ");
  my_putstr(str);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("  --help");
  display_space(7);
  my_putstr("Display this help\n");
  my_putstr("  -l --level={num}");
  display_space(17);
  my_putstr("Start Tetris at level num\n");
  my_putstr("  -kl --key-left={K}");
  display_space(19);
  my_putstr("Move tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}");
  display_space(20);
  my_putstr("Move tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}");
  display_space(19);
  my_putstr("Turn tetrimino with key K\n");
  display_help_end();
  exit(1);
}
