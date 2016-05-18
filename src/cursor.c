/*
** cursor.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon May 16 14:21:37 2016 Mathieu Sauvau
** Last update Mon May 16 15:25:56 2016 Mathieu Sauvau
*/

#include <stdio.h>
#include <ncurses.h>
#include <term.h>
#include "42s.h"

void	cursor_backward(int x)
{
  char	*str;

  str = NULL;
  if ((str = (tigetstr("cub"))))
    {
      if ((str = tiparm(str, x)))
	printf("%s", str);
    }
}

void	cursor_forward(int x)
{
  char	*str;

  str = NULL;
  if ((str = (tigetstr("cuf"))))
    {
      if ((str = tiparm(str, x)))
	printf("%s", str);
    }
}

void	cursor_erase(int x)
{
  char	*str;

  str = NULL;
  if ((str = (tigetstr("ech"))))
    {
      if ((str = tiparm(str, x)))
	printf("%s", str);
    }
}

void	cursor_save()
{
  char	*str;

  if ((str = tigetstr("sc")))
    printf("%s", str);
}

void	cursor_restore()
{
  char	*str;

  str = NULL;
  if ((str = tigetstr("rc")))
    printf("%s", str);
}
