/*
** bang.c for bang in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Tue May 31 17:40:17 2016 Poc
** Last update Wed Jun  1 12:01:00 2016 Poc
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "42s.h"

int		go_up(t_history *head, int i, char **str)
{
  while (i > 0)
    {
      head = head->next;
      i--;
    }
  free(*str);
  if ((*str = strdup(head->str)) == NULL)
    exit (1);
  return (0);
}

int		go_down(t_history *head, int i, char **str)
{
  while (i < 0)
    {
      head = head->prev;
      i++;
    }
  free(*str);
  if ((*str = strdup(head->str)) == NULL)
    exit (1);
  return (0);
}

int		bang(char **str, t_head *hist)
{
  int		i;

  if ((*str)[0] != '!')
    return (0);
  i = 0;
  i = atoi((*str) + 1);
  if (i > 0)
    go_up(hist->first, i - 1, str);
  else if (i < 0)
    go_down(hist->last, i, str);
  else
    {
      write(2, "Event not found, dont input a NULL value\n", 41);
      return (1);
    }
  return (0);
}
