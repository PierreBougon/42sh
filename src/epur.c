/*
** main.c for int main in /home/peau_c/PSU_2015_42sh/parsing
**
** Made by
** Login   <peau_c@epitech.net>
**
** Started on  Mon May  9 13:23:09 2016
** Last update Mon May  9 14:27:22 2016 
*/

#include <stdlib.h>
#include <string.h>

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
  while (str[i])
    {
      while ((str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == 0)))
	i++;
      new_str[j++] = str[i++];
      i = (str[i - 1] == 0 ? i - 1 : i);
    }
  new_str[j] = 0;
  return (new_str);
}
