/*
** erase.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 13 12:31:02 2016 Mathieu Sauvau
** Last update Mon May 16 15:13:55 2016 Mathieu Sauvau
*/

#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

void		edit_str(char **str, int *pos)
{
  char		*start;
  char		*end;

  start = strdup(*str);
  start[*pos - 1] = 0;
  start[*pos] = 0;
  end = strdup(*str + *pos);
  free(*str);
  *str = strdup(start);
  strcat(*str, end);
}

void		backspace(char **str, int *pos,
			  UNUSED t_head *history,
			  UNUSED int *i_history)
{
  if (*pos > 0)
    {
      edit_str(str, pos);
      --*pos;
      cursor_save();
      cursor_forward(strlen(*str) - *pos);
      cursor_backward(1);
      cursor_erase(1);
      cursor_restore();
      cursor_backward(1);
      cursor_erase(1);
      cursor_save();
      fflush(stdout);
      write(1, "\rhey ->", 7);
      write(1, *str, strlen(*str));
      cursor_restore();
      fflush(stdout);
    }
}
