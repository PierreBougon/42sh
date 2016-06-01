/*
** hisrory.c for azd in /home/debrau_c/Documents/cours/PSU/history
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Wed Jun  1 15:21:39 2016 debrau_c
** Last update Wed Jun  1 13:50:15 2016 marel_m
*/

#include <stdio.h>
#include "42s.h"

int		blt_hist(t_sh *sh)
{
  t_history	*histo_list;
  int		i;

  i = 1;
  histo_list = sh->history->first;
  while (histo_list)
    {
      printf("  %d\t%s\n", i, histo_list->str);
      histo_list = histo_list->next;
      ++i;
    }
  return (0);
}
