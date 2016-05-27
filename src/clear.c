/*
** clear.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 27 17:10:04 2016 Mathieu Sauvau
** Last update Fri May 27 18:55:52 2016 Mathieu Sauvau
*/

#include <stdio.h>
#include <ncurses.h>
#include <term.h>
#include "42s.h"

void	clear_scr(char **str, int *pos, t_head *history, int *i_history)
{
  char	*str;

  if ((str = tigetstr("clear")) != (char *)-1)
    printf("%s", str);
  fflush(stdout);
}
