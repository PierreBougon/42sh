/*
** parsing_double_quote.c for parsing_double_quote in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu Jun  2 10:43:51 2016 marel_m
** Last update Thu Jun  2 10:54:32 2016 marel_m
*/

#include "42s.h"

char	*pars_double_quote(char *str)
{
  char	*new;
  int	i;

  i = 0;
  j = 0;
  while (str[i] != '"')
    {
      i++;
      j++;
    }
  while (str[j] != '"')
    j++;
  return (new);
}

int	check_quote(char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '"')
	return (1);
      i++;
    }
  return (0);
}
