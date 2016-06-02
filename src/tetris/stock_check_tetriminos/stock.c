/*
** stock.c for stock in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_bstetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Feb 23 17:01:48 2016 maud marel
** Last update Wed Jun  1 23:30:34 2016 bougon_p
*/

#include <unistd.h>
#include "tetris.h"

int	tstock_elem(t_list_tetri *tetris, int j, int i, char *f_l)
{
  if (j == 0)
    tetris->tetrimino->width = f_l[i] - 48;
  else if (j == 1)
    tetris->tetrimino->height = f_l[i] - 48;
  else
    {
      if (f_l[i] < '1' || f_l[i] > '7')
	return (1);
      tetris->tetrimino->color = f_l[i] - 48;
    }
  return (0);
}

int	check_info(char *f_l, t_list_tetri *tetris)
{
  int   i;
  int   j;
  int	k;

  i = -1;
  j = -1;
  while (++j < 3)
    {
      k = 0;
      while (f_l[++i] != ' ' && f_l[i] != '\0')
	{
	  if (f_l[i] < 48 || f_l[i] > 57 || k++ > 1
	      || tstock_elem(tetris, j, i, f_l) == 1)
	    {
	      tetris->tetrimino->width = 0;
	      return (1);
	    }
	}
      if ((f_l[i] == '\0' && j != 2) || (f_l[i] != '\0' && j == 2))
	{
	  tetris->tetrimino->width = 0;
	  return (1);
	}
    }
  return (0);
}

int		stock(char *file, t_tetris *tetris, int fd, char *name)
{
  t_list_tetri  *new;
  int		ret;
  int		nb;

  if ((new = which_order(tetris, name)) == NULL)
    return (-1);
  if ((new->tetrimino = malloc(sizeof(t_tetri))) == NULL)
    return (-1);
  if ((new->tetrimino->name = malloc(sizeof(char)
				     * my_strlen(name) + 1)) == NULL)
    return (-1);
  my_strcpy(new->tetrimino->name, name);
  if ((nb = check_info(file, new)) != 1)
    {
      if ((ret = check_form(new, fd)) == 1)
	return (tetris->list_tetri->nb_error++, 1);
      else if (ret == -1)
	return (-1);
    }
  if (nb == 1)
    tetris->list_tetri->nb_error++;
  return (0);
}
