/*
** check_empty.c for chek_empty in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_tetris
**
** Made by Marel la plus belle <3
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar 20 23:16:07 2016 Marel la plus belle <3
** Last update Sun Mar 20 23:23:39 2016 Marel la plus belle <3
*/

#include "tetris.h"

int		check_empty(t_tetris *tetris, char *str)
{
  t_list_tetri	*new;

  tetris->list_tetri->nb_error++;
  if ((new = which_order(tetris, str)) == NULL)
    return (-1);
  if ((new->tetrimino = malloc(sizeof(t_tetri))) == NULL)
    return (-1);
  if ((new->tetrimino->name = malloc(sizeof(char)
				     * my_strlen(str) + 1)) == NULL)
    return (-1);
  my_strcpy(new->tetrimino->name, str);
  new->tetrimino->width = 0;
  return (0);
}
