/*
** glob_extend.c for ad in /home/debrau_c/Documents/cours/PSU/PSU_2015_42sh
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Fri Jun  3 18:15:08 2016 debrau_c
** Last update Fri Jun  3 22:26:47 2016 debrau_c
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
  while (str[++i])
    if (str[i] == '\t')
      str[i] = ' ';
  while (str[strlen(str) - 1] == ' ')
    str[strlen(str) - 1] = '\0';
}
