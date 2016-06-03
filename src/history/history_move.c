/*
** history_move.c for history_move in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Jun  3 18:51:48 2016 marel_m
** Last update Fri Jun  3 18:54:23 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "42s.h"

char		*seek_prev_history(t_history *history, char *str,
				   int *i_history)
{
  int		i;

  i = -1;
  if (!history)
    return (NULL);
  if (!str || !str[0])
    return (history->str);
  while (++i < *i_history)
      history = history->next;
  if (history->next)
    {
      ++*i_history;
      return (history->next->str);
    }
  return (history->str);
}

char		*seek_next_history(t_history *history, char *str,
				   int *i_history)
{
  int		i;

  i = -1;
  if (!history || !str || !str[0])
    return (NULL);
  while (++i < *i_history)
      history = history->next;
  if (history->prev)
    {
      --*i_history;
      return (history->prev->str);
    }
  return (history->str);
}

void		history_up(char **str, int *pos,
			   t_head *history, int *i_history)
{
  char		*h;

  cursor_backward(strlen(*str) + 10);
  cursor_erase(strlen(*str) + 10);
  if (history && history->first)
    {
      if ((h = seek_prev_history(history->first, *str, i_history)))
	{
	  free(*str);
	  *str = strdup(h);
	}
      *pos = strlen(*str);
      fflush(stdout);
      printf("\r%s%s", history->prompt, *str);
      fflush(stdout);
    }
}

void		history_down(char **str, int *pos,
			     t_head *history, int *i_history)
{

  char		*h;

  cursor_backward(strlen(*str) + 10);
  cursor_erase(strlen(*str) + 10);
  if (history && history->first)
    {
      if ((h = seek_next_history(history->first, *str, i_history)))
	{
	  free(*str);
	  *str = strdup(h);
	}
      *pos = strlen(*str);
      fflush(stdout);
      printf("\r%s%s", history->prompt, *str);
      fflush(stdout);
    }
}
