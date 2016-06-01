/*
** display_debug_key.c for display_debug_key in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
** 
** Made by maud marel
** Login   <marel_m@epitech.net>
** 
** Started on  Mon Mar  7 13:26:56 2016 maud marel
** Last update Tue Mar  8 17:21:11 2016 maud marel
*/

#include "tetris.h"

void	check_if_space(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 27)
	my_putstr("^E");
      else if (str[i] == ' ')
	my_putstr("(space)");
      else
	my_putchar(str[i]);
      i++;
    }
  my_putchar('\n');
}

void	display_key(t_tetris *tetris)
{
  my_putstr("Key Left : ");
  check_if_space(tetris->options->left);
  my_putstr("Key Right : ");
  check_if_space(tetris->options->right);
  my_putstr("Key Turn : ");
  check_if_space(tetris->options->turn);
  my_putstr("Key Drop : ");
  check_if_space(tetris->options->drop);
  my_putstr("Key Quit : ");
  check_if_space(tetris->options->quit);
  my_putstr("Key Pause : ");
  check_if_space(tetris->options->pause);
}
