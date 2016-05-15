/*
** erase.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 13 12:31:02 2016 Mathieu Sauvau
** Last update Fri May 13 19:22:27 2016 Mathieu Sauvau
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
			  UNUSED t_head *history)
{
  if (*pos > 0)
    {
      edit_str(str, pos);
      --*pos;
      CURSOR_SAVE;
      CURSOR_FORWARD(strlen(*str) - *pos);
      CURSOR_BACKWARD(1);
      ERASE(1);
      CURSOR_RESTORE;
      CURSOR_BACKWARD(1);
      ERASE(1);
      CURSOR_SAVE;
      fflush(stdout);
      write(1, "\rhey ->", 7);
      write(1, *str, strlen(*str));
      CURSOR_RESTORE;
      fflush(stdout);
    }
}
