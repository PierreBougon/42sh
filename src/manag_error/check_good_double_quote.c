/*
** check_good_double_quote.c for check_good_double_quote in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu Jun  2 15:07:00 2016 marel_m
** Last update Thu Jun  2 15:15:38 2016 marel_m
*/

#include <unistd.h>
#include "42s.h"

int	check_good_double_quote(t_sh *sh, char *str)
{
  int	i;
  int	quote;

  i = 0;
  quote = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '"')
	quote++;
      i++;
    }
  if (quote % 2 == 0)
    return (0);
  else
    {
      sh->exit = 1;
      write(2, "Unmatched \".\n", 13);
      return (1);
    }
}
