/*
** free_struct.c for free_struct
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar  6 15:15:50 2016
** Last update Wed Jun  1 23:16:55 2016 bougon_p
*/

#include "tetris.h"

void	free_tetri(t_tetri *tetri)
{
  int	i;

  i = 0;
  if (tetri)
    {
      if (tetri->width != 0)
	{
	  while (i < tetri->max)
	    {
	      free(tetri->tetrimino[i]);
	      i++;
	    }
	  free(tetri->tetrimino);
	}
      free(tetri);
    }
}

void			free_list_tetri(t_tetris *tetris)
{
  t_list_tetri		*tmp;
  t_list_tetri		*tmp2;

  tmp2 = tetris->list_tetri->next;
  while (tmp2 != tetris->list_tetri)
    {
      tmp = tmp2;
      tmp2 = tmp->next;
      free_tetri(tmp->tetrimino);
      free(tmp);
    }
  free(tetris->list_tetri);
}

void			free_board(t_tetris *tetris)
{
  int			y;

  y = -1;
  while (++y < tetris->options->row - 2)
    free(tetris->board[y]);
  free(tetris->board);
}

void			tfree_struct(t_tetris *tetris)
{
  free_list_tetri(tetris);
  delwin(tetris->wgame);
  delwin(tetris->wscore);
  delwin(tetris->wnext);
  free_board(tetris);
  free_options(tetris);
  free(tetris->key_tab);
}
