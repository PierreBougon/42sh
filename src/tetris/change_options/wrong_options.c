/*
** wrong_options.c for wrong_options in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Mar  2 17:40:45 2016 maud marel
** Last update Mon Mar  7 13:36:43 2016 maud marel
*/

#include "tetris.h"

void	wrong_options(char *str)
{
  my_putstr_error("Wrong argument : ");
  my_putstr_error(str);
  my_putstr_error("\n\n");
  display_help_error();
  exit(1);
}
