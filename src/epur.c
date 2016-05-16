/*
** main.c for int main in /home/peau_c/PSU_2015_42sh/parsing
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Mon May  9 13:23:09 2016
** Last update Mon May 16 11:30:52 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>

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
      while (str[(*i)] != '\0' && str
      	     && str[(*i)] == ' ')
      	(*i)++;
    }
  return (new);
}

char	*epur(char *str)
{
  int	i;
  int	j;
  char	*new_str;

  if ((new_str = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    if (str[i] == '\t')
      str[i] = ' ';
  i = 0;
  j = 0;
  while (str[i] == ' ')
    i++;
  while (str[i] != '\0' && str)
    {
      new_str = space_around_act(str, new_str, &i, &j);
      if (str[i] != '\0' && str)
	new_str[j++] = str[i++];
    }
  new_str[j] = 0;
  return (new_str);
}
