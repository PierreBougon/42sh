/*
** history.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 13 17:39:20 2016 Mathieu Sauvau
** Last update Sat May 14 12:25:58 2016 Mathieu Sauvau
*/

#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

void		push_front_history(t_head *history, char *str)
{
  t_history	*new;

  if(!str || !str[0] ||
     (new = malloc(sizeof(t_history))) == NULL)
    return ;
  new->str = strdup(str);
  new->prev = NULL;
  new->next = history->first;
  if (history->first)
    history->first->prev = new;
  else
    history->last = new;
  history->first = new;
}

void		free_history(t_history *history)
{
  if (history)
    {
      free_history(history->next);
      free(history->str);
      free(history);
    }
}

void		print_history(t_history *history)
{
  if (history)
    {
      print_history(history->next);
      printf("%s\n", history->str);
    }
  printf("\n");
}

char			*seek_prev_history(t_history *history, char *str)
{
  static t_history	*save;

  if (!history)
    return (NULL);
  if (!str || !str[0])
    return (history->str);
  if (!save)
    save = history;
  while (history)
    {
      if (strcmp(history->str, str) == 0)
	{
	  if (history->next)
	    {
	      save = history->next;
	      return (history->next->str);
	    }
	  return (history->str);
	}
      history = history->next;
    }
  return (save->str);
}

char			*seek_next_history(t_history *history, char *str)
{
  if (!history || !str || !str[0])
    return (NULL);
  while (history)
    {
      if (strcmp(history->str, str) == 0)
	{
	  if (history->prev)
	    return (history->prev->str);
	  return (history->str);
	}
      history = history->next;
    }
  return (NULL);
}

void		history_up(char **str, int *pos,
			   t_head *history)
{
  char		*h;

  CURSOR_BACKWARD(strlen(*str) + 10);
  ERASE(strlen(*str) + 10);
  if (history && history->first)
    {
      if ((h = seek_prev_history(history->first, *str)))
	{
	  free(*str);
	  *str = strdup(h);
	}
      *pos = strlen(*str);
      fflush(stdout);
      write(1, "\rhey ->", 7);
      write(1, *str, strlen(*str));
    }
}

void		history_down(char **str, int *pos,
			     t_head *history)
{

  char		*h;

  CURSOR_BACKWARD(strlen(*str) + 10);
  ERASE(strlen(*str) + 10);
  if (history && history->first)
    {
      if ((h = seek_next_history(history->first, *str)))
	{
	  free(*str);
	  *str = strdup(h);
	}
      *pos = strlen(*str);
      fflush(stdout);
      write(1, "\rhey ->", 7);
      write(1, *str, strlen(*str));
    }
}
