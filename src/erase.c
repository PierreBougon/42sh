/*
** erase.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 13 12:31:02 2016 Mathieu Sauvau
** Last update Tue May 31 17:59:28 2016 Mathieu Sauvau
*/

#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

void		edit_str(char **str, int *pos, int del)
{
  char		*start;
  char		*end;

  start = strdup(*str);
  if (!del)
    start[*pos - 1] = 0;
  start[*pos] = 0;
  if (!del)
    end = strdup(*str + *pos);
  else
    end = strdup(*str + *pos + 1);
  //printf("\nstart %s \n end %s\n", start, end);
  free(*str);
  if (!(*str = malloc(strlen(start) + strlen(end) + 1)))
    return ;
  *str = strcpy(*str, start);
  strcat(*str, end);
}

void		backspace(char **str, int *pos,
			  UNUSED t_head *history,
			  UNUSED int *i_history)
{
  if (*pos > 0)
    {
      edit_str(str, pos, 0);
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
      write(1, "\r", 1);
      write(1, history->prompt, strlen(history->prompt));
      write(1, *str, strlen(*str));
      cursor_restore();
      fflush(stdout);
    }
}

void		del(char **str, int *pos,
		    UNUSED t_head *history,
		    UNUSED int *i_history)
{
  if ((*str) && *pos < (int)strlen(*str))
    {
      edit_str(str, pos, 1);
      cursor_save();
      cursor_forward(strlen(*str) - *pos);
      cursor_backward(1);
      cursor_erase(strlen(*str) + 1);
      cursor_restore();
      cursor_save();
      fflush(stdout);
      write(1, "\r", 1);
      write(1, history->prompt, strlen(history->prompt));
      write(1, *str, strlen(*str));
      cursor_restore();
      fflush(stdout);
    }
}
