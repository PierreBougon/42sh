/*
** key.c for tetris in /home/sauvau_m/rendu/PSU_2015_tetris
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue Mar  8 17:46:35 2016 Mathieu Sauvau
** Last update Wed Jun  1 23:15:31 2016 bougon_p
*/

#include <unistd.h>
#include "tetris.h"

void			tmove_left(t_tetris *data, t_tetri *tetri)
{
  if (can_move_left(data, tetri) && !data->moved)
    {
      tetri->x -= 1;
      data->moved = true;
    }
}

void			tmove_right(t_tetris *data, t_tetri *tetri)
{
  if (can_move_right(data, tetri) && !data->moved)
    {
      tetri->x += 1;
      data->moved = true;
    }
}

t_key_fct		*get_fct_key(t_tetris *tetris)
{
  t_key_fct		*tab;

  if ((tab = malloc(sizeof(t_check_opt_simp) * MAX_CHECK_OPT_SIMP)) == NULL)
    exit(1);
  tab[LEFT_S].key = tetris->options->left;
  tab[LEFT_S].ft_simp = &tmove_left;
  tab[RIGHT_S].key = tetris->options->right;
  tab[RIGHT_S].ft_simp = &tmove_right;
  tab[TURN_S].key = tetris->options->turn;
  tab[TURN_S].ft_simp = &rotate;
  tab[DROP_S].key = tetris->options->drop;
  tab[DROP_S].ft_simp = &drop;
  tab[QUIT_S].key = tetris->options->quit;
  tab[QUIT_S].ft_simp = &quit;
  tab[PAUSE_S].key = tetris->options->pause;
  tab[PAUSE_S].ft_simp = &do_pause;
  return (tab);
}

void		read_key(t_tetris *data, t_tetri *tetri)
{
  char		buffer[10];
  int		r;

  reset_buffer(buffer);
  r = read(0, buffer, 10);
  if (r > 0)
    key(data, buffer, tetri);
  if (!data->pause)
    data->i += data->speed;
}

int			key(t_tetris *tetris,
			    char *buffer, t_tetri *tetri)
{
  int			i;

  i = 0;
  while (++i < MAX_CHECK_OPT_SIMP)
    {
      if (my_strcmp(buffer, tetris->key_tab[i].key) == 0)
	{
	  tetris->key_tab[i].ft_simp(tetris, tetri);
	  return (0);
	}
    }
  return (1);
}
