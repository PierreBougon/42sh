/*
** history.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri May 13 17:39:20 2016 Mathieu Sauvau
** Last update Fri Jun  3 20:13:35 2016 marel_m
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

void		push_front_history(t_head *history, char *str)
{
  t_history	*new;

  if (!str || !str[0] ||
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

void            get_history(t_sh *sh, t_head *history)
{
  char          *str;

  history->path = sh->env->path;
  while ((str = get_next_line(sh->fd_history)))
    {
      push_front_history(history, str);
      free(str);
    }
}

void            create_history_file(t_sh *sh)
{
  sh->fd_history = open(".42sh_history", O_CREAT | O_RDWR | O_APPEND,
			                        S_IRUSR | S_IWUSR | S_IRGRP |
			S_IWGRP | S_IROTH | S_IWOTH);
}
