/*
** stock_tetrimino.c for stock_tetrimino in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar  3 14:33:13 2016 maud marel
** Last update Fri Jun  3 18:58:00 2016 marel_m
*/

#include "tetris.h"

int	check_big_one(t_list_tetri *tetris)
{
  if (tetris->tetrimino->height > tetris->tetrimino->width)
    return (tetris->tetrimino->height);
  return (tetris->tetrimino->width);
}

int	check_line(t_list_tetri *tetris, char *file)
{
  int	i;
  int	w;

  i = -1;
  w = 0;
  while (file[++i] != '\0')
    {
      if (i < tetris->tetrimino->width)
	{
	  if (file[i] != ' ' && file[i] != '*')
	    {
	      tetris->tetrimino->width = 0;
	      return (-1);
	    }
	  w++;
	}
      else
	if (file[i] != ' ')
	  {
	    tetris->tetrimino->width = 0;
	    return (-1);
	  }
    }
  return (w);
}

int	copy_tetri(t_list_tetri *tetris, int h, char *file, int w)
{
  int   i;
  int	n;

  if ((n = check_line(tetris, file)) == -1)
    return (-1);
  if (n > w)
    w = n;
  if ((tetris->tetrimino->tetrimino[h] = malloc(sizeof(char)
  						   * (tetris->tetrimino->max
  						      + 1))) == NULL)
    return (-2);
  i = -1;
  while (++i < tetris->tetrimino->max)
    tetris->tetrimino->tetrimino[h][i] = 0;
  i = -1;
  while (++i < w)
    tetris->tetrimino->tetrimino[h][i] = file[i];
  tetris->tetrimino->tetrimino[h][i] = '\0';
  return (w);
}

int	complete_form(t_list_tetri *tetris, int h)
{
  int	i;

  while (h < tetris->tetrimino->max)
    {
      i = -1;
      while (++i < tetris->tetrimino->max)
	tetris->tetrimino->tetrimino[h][i] = 0;
      h++;
    }
  return (0);
}

int	check_form(t_list_tetri *tetris, int fd)
{
  char  *file;
  int   h;
  int	w;

  h = 0;
  w = 0;
  tetris->tetrimino->max = check_big_one(tetris);
  if ((tetris->tetrimino->tetrimino = malloc(sizeof(char*)
					     * tetris->tetrimino->max)) == NULL)
    return (-1);
  while ((file = get_next_line(fd)) != NULL)
    {
      if ((w = copy_tetri(tetris, h++, file, w)) == -1)
	return (free(file), 1);
      else if (w == -2)
	return (free(file), -1);
      free(file);
    }
  if (w != tetris->tetrimino->width || h != tetris->tetrimino->height)
    return (tetris->tetrimino->width = 0, 1);
  if (complete_form(tetris, h) == -1)
    return (-1);
  return (0);
}
