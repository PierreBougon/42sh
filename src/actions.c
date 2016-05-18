/*
** actions.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu May 12 16:33:46 2016 Mathieu Sauvau
** Last update Mon May 16 16:00:36 2016 Mathieu Sauvau
*/

#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

void		move_left(UNUSED char **str, int *pos,
			  UNUSED t_head *history,
			  UNUSED int *i_history)
{
  if (*pos > 0)
    {
      cursor_backward(1);
      fflush(stdout);
      --*pos;
    }
}

void		move_right(char **str, int *pos,
			   UNUSED t_head *history,
			   UNUSED int *i_history)
{
  if (*pos < (int)strlen(*str))
    {
      cursor_forward(1);
      fflush(stdout);
      ++*pos;
    }
}

void		debut(char **str, int *pos,
		      UNUSED t_head *history,
		      UNUSED int *i_history)
{
  int		len;

  if (*pos > 0)
    {
      len = strlen(*str);
      cursor_backward(*pos);
      fflush(stdout);
      *pos = 0;
    }
}

void		end(char **str, int *pos,
		    UNUSED t_head *history,
		    UNUSED int *i_history)
{
  int		len;

  len = strlen(*str);
  if (*pos < len)
    {
      cursor_forward(len - *pos);
      fflush(stdout);
      *pos = len;
    }
}
