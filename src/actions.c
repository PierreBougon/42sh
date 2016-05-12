/*
** actions.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu May 12 16:33:46 2016 Mathieu Sauvau
** Last update Thu May 12 20:43:57 2016 Mathieu Sauvau
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

void		move_left(UNUSED char **str, int *pos)
{
  if (*pos > 0)
    {
      CURSOR_BACKWARD(1);
      --*pos;
      fflush(stdout);
    }
}

void		move_right(char **str, int *pos)
{
  if (*pos < (int)strlen(*str))
    {
      CURSOR_FORWARD(1);
      ++*pos;
      fflush(stdout);
    }
}

void		debut(char **str, int *pos)
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

void		end(char **str, int *pos)
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

void		backspace(char **str, int *pos)
{
  char		*start;
  char		*end;
  int		i;
  int		j;

  start = strdup(*str);
  start[*pos - 1] = 0;
  start[*pos] = 0;
  end = strdup(*str + *pos);
  free(*str);
  *str = strdup(start);
  strcat(*str, end);
  /* printf("START %s\n", start); */
  /* printf("END %s\n", end); */
  --*pos;
  write(1, "\r", 1);
  printf("%c[2K", 27);
  fflush(stdout);
  write(1, "hey ->", 6);
  write(1, *str, strlen(*str));
  /* printf("\r%s", *str); */
  free(start);
}
