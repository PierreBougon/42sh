/*
** glob_string.c for azd in /home/debrau_c/Documents/cours/PSU/glob_easy
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Thu May 26 20:56:29 2016 debrau_c
** Last update Mon May 30 15:16:21 2016 marel_m
*/

#include <stdlib.h>

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

  i = -1;
  if (str == NULL)
    return ;
  while (str[0] == '\t' || str[0] == ' ')
    glob_suppr_char(str, 0);
  i = 0;
  while (str && str[++i])
    if ((str[i - 1] == ' ' || str[i - 1] == '\t')
	&& (str[i] == ' ' || str[i - 1] == '\t'))
      {
	glob_suppr_char(str, i - 1);
	i = 0;
      }
}