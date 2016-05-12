/*
** actions.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Thu May 12 16:33:46 2016 Mathieu Sauvau
** Last update Thu May 12 17:00:04 2016 Mathieu Sauvau
*/

#include <stdio.h>
#include <string.h>
#include "42s.h"

void		move_left(UNUSED char *str, int *pos)
{
  CURSOR_BACKWARD(1);
  fflush(stdout);
}

void		move_right(UNUSED char *str, int *pos)
{
  CURSOR_FORWARD(1);
  fflush(stdout);
}

void		debut(char *str, int *pos)
{
  CURSOR_BACKWARD((int)strlen(str));
  fflush(stdout);
}

void		end(char *str, int *pos)
{
  CURSOR_FORWARD((int)strlen(str));
  fflush(stdout);
}

void		backspace(char *str, int *pos)
{

}
