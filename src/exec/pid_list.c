/*
** fd_list.c for fdlist in /home/peau_c/toto
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Sat Jun  4 16:55:43 2016 Poc
** Last update Sun Jun  5 00:02:41 2016 Poc
*/

#include <string.h>
#include <stdlib.h>
#include "42s.h"

t_pid	*create_pid()
{
  t_pid	*list;

  if ((list = malloc(sizeof(t_pid))) == NULL)
    exit(1);
  if (memset(list, 0, sizeof(t_pid)) == NULL)
    exit(1);
  return (list);
}

void	add_to_back(t_pid **list, int pid)
{
  t_pid	*tmp;

  if (!(*list))
    {
      (*list) = create_pid();
      (*list)->pid = pid;
      return ;
    }
  tmp = create_pid();
  tmp->pid = pid;
  tmp->next = (*list);
  *list = tmp;
}

void	clear_list(t_pid *pid)
{
  t_pid	*tmp;

  while (pid)
    {
      tmp = pid;
      pid = pid->next;
      free(tmp);
    }
}
