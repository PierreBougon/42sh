/*
** history.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 13 17:39:20 2016 Mathieu Sauvau
** Last update Wed May 18 15:17:28 2016 Mathieu Sauvau
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
      write(1, "\rhey ->", 7);
      write(1, *str, strlen(*str));
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
      write(1, "\rhey ->", 7);
      write(1, *str, strlen(*str));
    }
}
