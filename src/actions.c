/*
** actions.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu May 12 16:33:46 2016 Mathieu Sauvau
** Last update Fri May 13 19:22:15 2016 Mathieu Sauvau
*/

#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

void		move_left(UNUSED char **str, int *pos,
			  UNUSED t_head *history)
{
  if (*pos > 0)
    {
     CURSOR_BACKWARD(1);
      --*pos;
      fflush(stdout);
    }
}

void		move_right(char **str, int *pos,
			   UNUSED t_head *history)
{
  if (*pos < (int)strlen(*str))
    {
      CURSOR_FORWARD(1);
      ++*pos;
      fflush(stdout);
    }
}

void		debut(char **str, int *pos,
		      UNUSED t_head *history)
{
  int		len;

  if (*pos > 0)
    {
      len = strlen(*str);
      CURSOR_BACKWARD(*pos);
      *pos = 0;
      fflush(stdout);
    }
}

void		end(char **str, int *pos,
		    UNUSED t_head *history)
{
  int		len;

  len = strlen(*str);
  if (*pos < len)
    {
      CURSOR_FORWARD(len - *pos);
      *pos = len;
      fflush(stdout);
    }
}
