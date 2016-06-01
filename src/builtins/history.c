/*
** hisrory.c for azd in /home/debrau_c/Documents/cours/PSU/history
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Wed Jun  1 15:21:39 2016 debrau_c
** Last update Wed Jun  1 15:44:33 2016 debrau_c
*/

#include <stdio.h>
#include "42s.h"

int		blt_hist(t_sh *sh)
{
  t_history	*histo_list;
  int		i;

  i = 1;
  histo_list = sh->history;
  while (histo_list)
    {
      printf("\t%d\t%s\n", i, histo_list->str);
      histo_list = histo_list->next;
      ++i;
    }
  return (0);
}
/*
t_history	*history_init()
{
  t_history	*newer;
  char		*str;

  if ((fd = open(".4sh_history", O_RDONLY)) < 0)
    return (NULL);
  if ((newer = malloc(sizeof(t_history))) == NULL)
    return (NULL);
  newer->history->str = get_next_line(fd);
  while ((str = get_next_line(fd)) != NULL)
    {

    }
  return (newer);
}
*/
