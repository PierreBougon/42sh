/*
** glob_string.c for azd in /home/debrau_c/Documents/cours/PSU/glob_easy
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Thu May 26 20:56:29 2016 debrau_c
** Last update Fri Jun  3 22:30:22 2016 debrau_c
*/

#include <stdlib.h>
#include "my_glob.h"

int	glob_strclen(char *str, char c)
{
  int	i;

  i = 0;
  while (str && str[i] && str[i] != c)
    ++i;
  return (i);
}

int	glob_count_occur(char *str, char c)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str && str[i])
    {
      if (str[i] == c)
	res++;
      i++;
    }
  res++;
  return (res);
}

char	*glob_strcdup(char *str, char c)
{
  int	i;
  char	*new;

  i = 0;
  if ((new = malloc(sizeof(char) * ((glob_strclen(str, c) + 1)))) == NULL)
    return (NULL);
  while (str && str[i] && str[i] != c)
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}

void	glob_suppr_char(char *str, int index)
{
  int	i;

  i = index;
  while (str && str[i])
    {
      str[i] = str[i + 1];
      i++;
    }
}

void	glob_epur(char *str)
{
  int	i;
  int	on_quotes;

  on_quotes = 0;
  i = -1;
  if (str == NULL)
    return ;
  glob_clean_str_first(str);
  i = 0;
  while (str && str[++i])
    {
      if (!on_quotes && str[i] == '"')
	on_quotes = 1;
      else if (on_quotes && str[i] == '"')
	on_quotes = 0;
      if (!on_quotes)
	if ((str[i - 1] == ' ' || str[i - 1] == '\t')
	    && (str[i] == ' ' || str[i] == '\t'))
	  {
	    glob_suppr_char(str, i - 1);
	    i = 0;
	  }
    }
}
