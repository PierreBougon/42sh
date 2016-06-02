/*
** cpy_tetri.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Wed Mar  9 14:11:11 2016 Mathieu Sauvau
** Last update Wed Jun  1 21:41:46 2016 bougon_p
*/

#include "tetris.h"

t_tetri		*cpy_tetri(t_tetri *tetri)
{
  t_tetri	*new_tetri;
  int		x;
  int		y;

  if ((new_tetri = malloc(sizeof(t_tetri))) == NULL
      || (new_tetri->tetrimino = malloc(sizeof(char *) * tetri->max)) == NULL)
      return (NULL);
  new_tetri->max = tetri->max;
  new_tetri->height = tetri->height;
  new_tetri->width = tetri->width;
  new_tetri->color = tetri->color;
  new_tetri->x = tetri->x;
  new_tetri->y = tetri->y;
  new_tetri->name = tetri->name;
  y = -1;
  while (++y < new_tetri->max)
    {
      x = -1;
      if ((new_tetri->tetrimino[y] = malloc(sizeof(char)
					    * tetri->max)) == NULL)
  	return (NULL);
      while (++x < new_tetri->max)
      	new_tetri->tetrimino[y][x] = tetri->tetrimino[y][x];
    }
  return (new_tetri);
}

int		max_tetri(t_list_tetri *list_tetri)
{
  t_list_tetri	*elem;
  int		n;

  elem = list_tetri->next;
  n = 0;
  while (elem != list_tetri)
    {
      ++n;
      elem = elem->next;
    }
  return (n);
}

t_tetri		*random_tetri(t_list_tetri *list_tetri, int nb_tetri)
{
  t_list_tetri	*elem;
  t_tetri	*result;
  int		r;
  int		n;

  elem = list_tetri->next;
  n = -1;
  r = rand() % nb_tetri;
  while (elem != list_tetri && ++n != r)
    elem = elem->next;
  result = cpy_tetri(elem->tetrimino);
  return (result);
}

t_tetri		*init_first_loop(t_tetris *tetris)
{
  t_tetri	*tetri;

  tetris->nb_tetri = max_tetri(tetris->list_tetri);
  tetri = random_tetri(tetris->list_tetri, tetris->nb_tetri);
  tetri->x = tetris->options->col / 2 - tetri->width / 2;
  tetri->y = 0;
  mode_canon(0, 0, 0);
  return (tetri);
}
