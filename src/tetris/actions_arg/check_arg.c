/*
** check_arg.c for check_arg in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:40:47 2016 maud marel
** Last update Thu Mar 10 20:05:58 2016 
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

t_check_opt	*init_tab_comp_arg()
{
  t_check_opt	*tab;

  if ((tab = malloc(sizeof(t_check_opt) * MAX_CHECK_OPT)) == NULL)
    return (NULL);
  tab[LEVEL].opt = "--level=";
  tab[LEVEL].ft_com = &change_level;
  tab[LEFT].opt = "--key-left=";
  tab[LEFT].ft_com = &change_key_left;
  tab[RIGHT].opt = "--key-right=";
  tab[RIGHT].ft_com = &change_key_right;
  tab[TURN].opt = "--key-turn=";
  tab[TURN].ft_com = &change_key_turn;
  tab[DROP].opt = "--key-drop=";
  tab[DROP].ft_com = &change_key_drop;
  tab[QUIT].opt = "--key-quit=";
  tab[QUIT].ft_com = &change_key_quit;
  tab[PAUSE].opt = "--key-pause=";
  tab[PAUSE].ft_com = &change_key_pause;
  tab[SIZE].opt = "--map-size=";
  tab[SIZE].ft_com = &change_map_size;
  tab[NEXT].opt = "-w";
  tab[NEXT].ft_com = &hide_next;
  tab[NEXT_S].opt = "--without-next";
  tab[NEXT_S].ft_com = &hide_next;
  return (tab);
}

int		check_complex_arg(t_tetris *tetris, char *str)
{
  int		i;
  t_check_opt	*fptrtab;

  i = -1;
  if ((fptrtab = init_tab_comp_arg()) == NULL)
    return (-1);
  while (++i < MAX_CHECK_OPT)
    if (my_strncmp(fptrtab[i].opt, str, my_strlen(fptrtab[i].opt)) == 0)
      {
	if (!(fptrtab[i].ft_com(tetris, str)))
	  return (-1);
	return (0);
      }
  return (1);
}

t_check_opt_simp	*init_tab_simp_arg()
{
  t_check_opt_simp	*tab;

  if ((tab = malloc(sizeof(t_check_opt_simp) * MAX_CHECK_OPT_SIMP)) == NULL)
    return (NULL);
  tab[LEVEL_S].opt = "-l";
  tab[LEVEL_S].ft_simp = &change_level_simp;
  tab[LEFT_S].opt = "-kl";
  tab[LEFT_S].ft_simp = &change_key_left_simp;
  tab[RIGHT_S].opt = "-kr";
  tab[RIGHT_S].ft_simp = &change_key_right_simp;
  tab[TURN_S].opt = "-kt";
  tab[TURN_S].ft_simp = &change_key_turn_simp;
  tab[DROP_S].opt = "-kd";
  tab[DROP_S].ft_simp = &change_key_drop_simp;
  tab[QUIT_S].opt = "-kq";
  tab[QUIT_S].ft_simp = &change_key_quit_simp;
  tab[PAUSE_S].opt = "-kp";
  tab[PAUSE_S].ft_simp = &change_key_pause_simp;
  return (tab);
}

int			check_simp_arg(t_tetris *tetris, char *str, char *new)
{
  int			i;
  t_check_opt_simp	*fptrtab;

  i = -1;
  if (new == NULL)
    {
      write(2, "Wrong arguments\n\n", 17);
      display_help_error();
    }
  if ((fptrtab = init_tab_simp_arg()) == NULL)
    return (-1);
  while (++i < MAX_CHECK_OPT_SIMP)
    if (my_strcmp(fptrtab[i].opt, str) == 0)
      {
	if (!(fptrtab[i].ft_simp(tetris, new)))
	  return (-1);
	return (0);
      }
  return (1);
}
