/*
** clear.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 27 17:10:04 2016 Mathieu Sauvau
** Last update Mon May 30 11:03:41 2016 Mathieu Sauvau
*/

#include <stdio.h>
#include <ncurses.h>
#include <term.h>
#include "42s.h"

void	clear_scr(UNUSED char **str, UNUSED int *pos,
		  UNUSED t_head *history, UNUSED int *i_history)
{
  char	*s;

  if ((s = tigetstr("clear")) != (char *)-1)
    printf("%s", s);
  fflush(stdout);
}
