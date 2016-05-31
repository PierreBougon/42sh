/*
** rewrite_str.c for rewrite_str in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue May 31 23:47:51 2016 marel_m
** Last update Tue May 31 23:49:24 2016 marel_m
*/

#include <stdlib.h>
#include "42s.h"

char	*rewrite_str(char *str)
{
  char	*tmp;
  int	i;
  int	j;

  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[j] != '\0' && str && str[j] != ' ' && str[j] != '|')
    j++;
  if (str[j] == '\0' && str)
    return (str);
  j++;
  while (str[j] != '\0' && str && str[j] != '|')
    tmp[i++] = str[j++];
  j = 0;
  while (str[j] != '\0' && str && str[j] != ' ')
    tmp[i++] = str[j++];
  tmp[i] = '\0';
  return (tmp);
}
