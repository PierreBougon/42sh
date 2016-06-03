/*
** init_ncurses.c for init_ncurses in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Jun  3 19:35:24 2016 marel_m
** Last update Fri Jun  3 19:40:07 2016 marel_m
*/

#include <curses.h>
#include <term.h>
#include <string.h>
#include "42s.h"

int		init_actions_next(t_key_act actions[18])
{
  actions[0].fct = &move_left;
  actions[1].fct = &move_right;
  actions[2].fct = &debut;
  actions[3].fct = &end;
  actions[4].fct = &backspace;
  actions[5].fct = &backspace;
  actions[6].fct = &history_up;
  actions[7].fct = &history_down;
  actions[8].fct = &auto_complet;
  actions[9].fct = &clear_scr;
  actions[10].fct = &del;
  actions[11].fct = &backspace;
  actions[12].fct = &end;
  actions[13].fct = &debut;
  actions[14].fct = &ctrl_left;
  actions[15].fct = &ctrl_right;
  actions[16].fct = &ctrl_k;
  actions[17].fct = &ctrl_y;
  return (0);
}

void		init_arr_buff(char ar_l[7], char ar_r[7], char k[2], char y[2])
{
  ar_l[0] = 27;
  ar_r[0] = 27;
  ar_l[1] = 91;
  ar_r[1] = 91;
  ar_l[2] = 49;
  ar_r[2] = 49;
  ar_l[3] = 59;
  ar_r[3] = 59;
  ar_l[4] = 53;
  ar_r[4] = 53;
  ar_l[5] = 68;
  ar_r[5] = 67;
  ar_l[6] = 0;
  ar_r[6] = 0;
  k[0] = 11;
  k[1] = 0;
  y[0] = 25;
  y[1] = 0;
}

int		init_actions2(t_key_act actions[18])
{
  char		end[2];
  char		start[2];
  char		backs[2];
  char		ar_l[7];
  char		ar_r[7];
  char		k[2];
  char		y[2];

  backs[0] = 127;
  backs[1] = 0;
  end[0] = 5;
  end[1] = 0;
  start[0] = 1;
  start[1] = 0;
  init_arr_buff(ar_l, ar_r, k, y);
  if ((!(actions[11].key = strdup(&backs[0])) ||
       !(actions[12].key = strdup(end)) ||
       !(actions[13].key = strdup(start)) ||
       !(actions[14].key = strdup(ar_l)) ||
       !(actions[15].key = strdup(ar_r)) ||
       !(actions[16].key = strdup(k)) ||
       !(actions[17].key = strdup(y))))
    return (-1);
  return (init_actions_next(actions));
}

int		init_actions(t_key_act actions[18])
{
  char		*str;

  if ((str = tigetstr("kcub1")) == (char *)-1 ||
      !(actions[0].key = strdup(str)) ||
      (str = tigetstr("kcuf1")) == (char *)-1 ||
      !(actions[1].key = strdup(str)) ||
      (str = tigetstr("khome")) == (char *)-1 ||
      !(actions[2].key = strdup(str)) ||
      (str = tigetstr("kend")) == (char *)-1 ||
      !(actions[3].key = strdup(str)) ||
      (str = tigetstr("kbs")) == (char *)-1 ||
      !(actions[4].key = strdup(str)) ||
      (str = tigetstr("cub1")) == (char *)-1 ||
      !(actions[5].key = strdup(str)) ||
      (str = tigetstr("kcuu1")) == (char *)-1 ||
      !(actions[6].key = strdup(str)) ||
      (str = tigetstr("kcud1")) == (char *)-1 ||
      !(actions[7].key = strdup(str)) ||
      !(actions[8].key = strdup("\t")) ||
      !(actions[9].key = strdup("\f")) ||
      (str = tigetstr("kdch1")) == (char *)-1 ||
      !(actions[10].key = strdup(str)))
    return (-1);
  return (init_actions2(actions));
}
