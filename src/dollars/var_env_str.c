/*
** my_string.c for azd in /home/debrau_c/bin/new_repo/srcs
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Fri Apr 29 21:06:16 2016 debrau_c
** Last update Fri Jun  3 22:42:56 2016 marel_m
*/

#include <stdlib.h>

int	var_env_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i]) i++;
  return (i);
}

int	var_env_strclen(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != c) i++;
  return (i);
}

char	*var_env_strcdup(char *str, char c)
{
  int	i;
  char	*new;

  i = 0;
  if (!(new = malloc(sizeof(char) * (var_env_strclen(str, c) + 1))))
      return (NULL);
  while (str[i] && str[i] != c && str[i] != '"')
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}
