/*
** verif_god_syn_dep.c for azd in /home/debrau_c/Documents/cours/PSU/FALSE_42/PSU_2015_42sh
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Sat Jun  4 19:49:10 2016 debrau_c
** Last update Sun Jun  5 15:48:37 2016 marel_m
*/

#include <unistd.h>
#include "42s.h"

static int	separ_find(char *str, int *i, int *j)
{
  if (check_synthax(str, *j, *i))
    return (1);
  while (str[(*i)] != '\0' && str[(*i)] == ';')
    (*i)++;
  if (str && str[(*i)] != '\0')
    (*i)++;
  *j = *i;
  return (0);
}

static int	separ_esperluette_find(char *str, int *i, int *j)
{
  if (check_synthax(str, *j, *i))
    return (1);
  if (str && str[(*i)] != '\0' && str[(*i) + 1] != '\0')
    (*i) += 2;
  if (str[(*i)] == '&' || str[(*i)] == '|' || str[(*i)] == ';')
    return (write(2, "Invalid null command.\n", 22), 1);
  *j = *i;
  return (0);
}

int	if_is_a_separator(char *str, int *i, int *j)
{
  if (str[(*i)] == ';')
    return (separ_find(str, i, j));
  else if (str[(*i)] == '&' && str[(*i) + 1] == '&')
    return (separ_esperluette_find(str, i, j));
  else if (str[(*i)] == '|' && str[(*i) + 1] == '|')
    {
      if (check_synthax(str, *j, *i))
	return (1);
      if (str && str[(*i)] != '\0' && str[(*i) + 1] != '\0')
	(*i) += 2;
      *j = *i;
      return (0);
    }
  return (-1);
}
