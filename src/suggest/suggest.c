/*
** suggest.c for suggest in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu May 26 11:43:54 2016 bougon_p
** Last update Tue May 31 18:05:38 2016 bougon_p
*/

#include <stdlib.h>
#include "42s.h"
#include "suggest.h"

void	calc_all_distances(t_suggest *sugg, char *cmd)
{
  int	i;

  i = -1;
  while (sugg->binaries[++i])
    {
      sugg->tab_dist[i] = levenshtein(cmd, sugg->binaries[i]);
      if (i == 0)
	sugg->dist_min = sugg->tab_dist[i];
      else
	{
	  sugg->dist_min = (sugg->dist_min > sugg->tab_dist[i])
	    ? sugg->tab_dist[i] : sugg->dist_min;
	}
    }
}

void	print_minimal_dist(t_suggest *sugg, int pass)
{
  int	i;
  int	n;
  bool	first;

  first = true;
  i = -1;
  n = 0;
  while (sugg->binaries[++i])
    {
      if (sugg->tab_dist[i] == sugg->dist_min)
	{
	  if (first)
	    {
	      dprintf(2, "Did you mean ?\n");
	      first = false;
	    }
	  dprintf(2, "%s\n", sugg->binaries[i]);
	  n++;
	}
    }
  if (n <= 1 && pass == 0)
    {
      sugg->dist_min += 1;
      print_minimal_dist(sugg, 1);
    }
}

static void	free_datas(t_suggest *sugg)
{
  int		i;

  i = -1;
  while (sugg->binaries[++i])
    {
      free(sugg->binaries[i]);
    }
  free(sugg->binaries);
  free(sugg->tab_dist);
}

int		suggest(t_sh *sh, char *cmd)
{
  t_suggest	sugg;

  sugg.nb_bin = 0;
  sugg.dist_min = -1;
  if (!cmd)
    return (0);
  if (!(sugg.binaries = malloc(sizeof(char *) * 1)))
    return (1);
  sugg.binaries[0] = NULL;
  if (check_all_path(sh, &sugg) == 1)
    return (1);
  if (!(sugg.tab_dist = malloc(sizeof(int) * sugg.nb_bin)))
    return (1);
  calc_all_distances(&sugg, cmd);
  print_minimal_dist(&sugg, 0);
  free_datas(&sugg);
  return (0);
}
