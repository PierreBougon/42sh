/*
** movement.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Mar  6 18:33:26 2016 Mathieu Sauvau
** Last update Thu Mar 10 15:27:41 2016 Mathieu Sauvau
*/

#include "tetris.h"

bool		can_move_down(t_tetris *data, t_tetri *tetri)
{
  if (tetri->y + tetri->height > data->options->row - 2
      || space_occupied_down(data, tetri))
    return (false);
  return (true);
}

bool		can_move_left(t_tetris *data, t_tetri *tetri)
{
  int first_star;

  first_star = get_first_star_on_x(tetri);
  if (tetri->x - 1 < -first_star + 2
      || space_occupied_left(data, tetri))
    return (false);
  return (true);
}

bool		can_move_right(t_tetris *data, t_tetri *tetri)
{
  int		first_star;

  first_star = get_last_star_on_x(tetri);
  if (tetri->x + first_star >= data->options->col - 2
      || space_occupied_right(data, tetri))
    return (false);
  return (true);
}
