/*
** hisrory.c for azd in /home/debrau_c/Documents/cours/PSU/history
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Wed Jun  1 15:21:39 2016 debrau_c
** Last update Sun Jun  5 11:24:44 2016 bougon_p
*/

#include <stdio.h>
#include "42s.h"

int		blt_hist(t_sh *sh)
{
  t_history	*histo_list;
  int		i;
  int		fd;

  if ((fd = sh->exec->fd[0][1]) == -1)
    fd = 1;
  i = 1;
  histo_list = sh->history->first;
  while (histo_list)
    {
      dprintf(fd, "  %d\t%s\n", i, histo_list->str);
      histo_list = histo_list->next;
      ++i;
    }
  return (0);
}
