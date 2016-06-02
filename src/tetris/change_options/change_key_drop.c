/*
** change_key_drop.c for change_key_drop in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sun Feb 28 18:55:33 2016 maud marel
** Last update Tue Mar  8 15:37:37 2016 maud marel
*/

#include "tetris.h"

bool	change_key_drop(t_tetris *tetris, char *str)
{
  int	i;
  int	j;

  i = 0;
  while (str && str[i] != '=')
    i++;
  i++;
  if (i == my_strlen(str))
    wrong_options(str);
  if ((tetris->options->drop = malloc(sizeof(char)
				      * my_strlen(str) - (i + 1))) == NULL)
    return (false);
  j = 0;
  while (str[i] != '\0')
    {
      tetris->options->drop[j] = str[i];
      i++;
      j++;
    }
  tetris->options->drop[j] = '\0';
  return (true);
}

bool	change_key_drop_simp(t_tetris *tetris, char *str)
{
  if ((tetris->options->drop = my_strdup(str)) == NULL)
    return (false);
  return (true);
}
