/*
** clear.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 27 17:10:04 2016 Mathieu Sauvau
** Last update Thu Jun  2 11:42:40 2016 Mathieu Sauvau
*/

#include <stdio.h>
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

  i = *pos;
  while ((*str)[--i] && (*str)[i] == ' ')
    {
      cursor_backward(1);
      --*pos;
    }
  while ((*str)[i] && (*str)[i--] != ' ')
    {
      cursor_backward(1);
      --*pos;
    }
  fflush(stdout);
}

void	ctrl_right(char **str, int *pos,
		   UNUSED t_head *history, UNUSED int *i_history)
{
  int	i;

  i = *pos;
  while ((*str)[++i] && (*str)[i] == ' ')
    {
      cursor_forward(1);
      ++*pos;
    }
  while ((*str)[i] && (*str)[i++] != ' ')
    {
      cursor_forward(1);
      ++*pos;
    }
  fflush(stdout);
}
