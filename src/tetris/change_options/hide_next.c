/*
** hide_next.c for hide_next in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Mar  5 09:08:25 2016 maud marel
** Last update Tue Mar  8 15:43:45 2016 maud marel
*/

#include "tetris.h"

bool	hide_next(t_tetris *tetris, char *str)
{
  if (my_strcmp(str, "-w") == 0 || my_strcmp(str, "--without-next") == 0)
    tetris->options->hide_next = 1;
  else
    {
      my_putstr_error("Wrong argument : ");
      my_putstr_error(str);
      my_putstr_error("\n\n");
      display_help_error();
    }
  return (true);
}
