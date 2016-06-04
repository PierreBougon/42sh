/*
** main.c for int main in /home/peau_c/PSU_2015_42sh/parsing
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Mon May  9 13:23:09 2016
** Last update Sat Jun  4 20:14:15 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"

char	*space_around_act(char *str, char *new, int *i, int *j)
{
  if (str[(*i)] == ' ')
    {
      if (str[(*i) + 1] != '\0' && str && (*j) != 0
	  && new[(*j) - 1] != ' ' && str[(*i) + 1] != ';'
	  && str[(*i) + 1] != '<' && str[(*i) + 1] != '>'
	  && str[(*i) + 1] != '|' && new[(*j) - 1] != ';'
	  && new[(*j) - 1] != '<' && new[(*j) - 1] != '>'
	  && new[(*j) - 1] != '|' && new[(*j) - 1] != '&'
	  && str[(*i) + 1] != '&')
	new[(*j)++] = ' ';
      (*i)++;
    }
  return (new);
}

char	*epur_with_quote(char *str, char *new_str, int *i, int *j)
{
  new_str[*j] = '"';
  (*j)++;
  (*i)++;
  while (str[*i] != '"' && str[*i] != '\0')
    {
      new_str[*j] = str[*i];
      (*i)++;
      (*j)++;
    }
  return (new_str);
}

char	*epur_without_quote(char *str, char *new_str, int *i, int *j)
{
  new_str = space_around_act(str, new_str, i, j);
  if (str[*i] != '"' && str[*i] != '\0' && str)
    new_str[(*j)++] = str[(*i)++];
  return (new_str);
}

char	*epur(char *str)
{
  int	i;
  int	j;
  char	*new_str;

  if ((new_str = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i] == ' ')
    i++;
  while (str[i] != '\0' && str)
    {
      if (str[i] == '"')
	new_str = epur_with_quote(str, new_str, &i, &j);
      else
	new_str = epur_without_quote(str, new_str, &i, &j);
    }
  new_str[j] = 0;
  my_free((void **)&str);
  return (new_str);
}
