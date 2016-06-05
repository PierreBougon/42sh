/*
** glob_extend.c for ad in /home/debrau_c/Documents/cours/PSU/PSU_2015_42sh
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Fri Jun  3 18:15:08 2016 debrau_c
** Last update Sun Jun  5 04:25:59 2016 marel_m
*/

#include <string.h>
#include "my_glob.h"

int	glob_maj_quotes(int on_quotes, char c)
{
  if (!on_quotes && c == '"')
    return (1);
  else if (on_quotes && c == '"')
    return (0);
  return (on_quotes);
}

void	glob_clean_str_first(char *str)
{
  int	i;

  while (str[0] == '\t' || str[0] == ' ')
    glob_suppr_char(str, 0);
  i = -1;
  while (str && str[++i])
    if (str[i] == '\t')
      str[i] = ' ';
  while (str[i] && str[((strlen(str) == 0 ? 1 : strlen(str))) - 1] == ' ')
    str[strlen(str) - 1] = '\0';
}
