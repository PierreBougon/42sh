/*
** clear.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 27 17:10:04 2016 Mathieu Sauvau
** Last update Sat Jun  4 22:37:41 2016 marel_m
*/

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <term.h>
#include <string.h>
#include "42s.h"

void	clear_scr(char **str, UNUSED int *pos,
		  t_head *history, UNUSED int *i_history)
{
  char	*s;

  if ((s = tigetstr("clear")) != (char *)-1)
    printf("%s", s);
  printf("%s%s", history->prompt, *str);
  cursor_backward(strlen(*str));
  cursor_forward(strlen(*str));
  fflush(stdout);
}

void	ctrl_left(char **str, int *pos,
		  UNUSED t_head *history, UNUSED int *i_history)
{
  int	i;

  if (*str && str[0])
    {
      i = *pos;
      while (--i >= 0 && (*str)[i] && (*str)[i] == ' ')
	{
	  cursor_backward(1);
	  --*pos;
	}
      while (i >= 0 && (*str)[i] && (*str)[i--] != ' ')
	{
	  cursor_backward(1);
	  --*pos;
	}
      fflush(stdout);
    }
}

void	ctrl_right(char **str, int *pos,
		   UNUSED t_head *history, UNUSED int *i_history)
{
  int	i;

  if (*str && str[0])
    {
      i = *pos;
      if (i == (int)strlen(*str))
	return ;
      while ((*str)[++i] && (*str)[i] == ' ')
	  {
	    cursor_forward(1);
	    ++*pos;
	  }
	while ((*str)[i] && (*str)[i] != ' ')
	  {
	    cursor_forward(1);
	    ++*pos;
	    ++i;
	  }
	cursor_forward(1);
	++*pos;
	fflush(stdout);
    }
}

void	ctrl_k(char **str, int *pos,
	       t_head *history, UNUSED int *i_history)
{
  char	*start;

  if (*str && *(str)[0] != 0)
    {
      if (!(start = strdup(*str)))
	  return ;
      start[*pos] = 0;
      cursor_erase(strlen(*str));
      fflush(stdout);
      if (history->cpy_buf)
	free(history->cpy_buf);
      if (!(history->cpy_buf = strdup(*str + *pos)))
	return ;
      free(*str);
      if (!(*str = strdup(start)))
	return ;
      free(start);
    }
}

void	ctrl_y(char **str, int *pos,
	       t_head *history, UNUSED int *i_history)
{
  char	*start;
  char	*end;

   if (history->cpy_buf)
    {
      if (!(start = strdup(*str)))
	  return ;
      start[*pos] = 0;
      if ((end = strdup(*str + *pos)) == NULL ||
	  (*str = realloc(*str, strlen(*str) + strlen(history->cpy_buf) + 1)) == NULL)
	return ;
      strcpy(*str, start);
      strcat(*str, history->cpy_buf);
      strcat(*str, end);
      printf("\r%s%s", history->prompt, *str);
      cursor_backward(strlen(end));
      *pos += strlen(history->cpy_buf);
      if ((*pos) == (int)strlen(*str))
      	cursor_forward(1);
      fflush(stdout);
      free(start);
      free(end);
    }
}
