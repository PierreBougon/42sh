/*
** rewrite_str.c for rewrite_str in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue May 31 23:47:51 2016 marel_m
** Last update Fri Jun  3 12:00:20 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>
#include "42s.h"

char	*rewrite_str(char *str)
{
  char	*tmp;
  char	*tmp2;
  int	i;
  int	j;

  j = 0;
  while (str[j] != '\0' && str && str[j] != ' ' && str[j] != '|')
    j++;
  if (str[j] == '\0' && str)
    return (str);
  j++;
  i = j;
  while (str && str[j] != '\0' && str[j] != '|')
    j++;
  if ((tmp = my_strdup_bt(str, i, j)) == NULL)
    return (NULL);
  j = 0;
  while (str && str[j] != '\0' && str[j] != ' ')
    j++;
  if ((tmp2 = strndup(str, j)) == NULL
      || (tmp = realloc(tmp, strlen(tmp) + strlen(tmp2) + 1)) == NULL)
    return (NULL);
  tmp = strcat(tmp, tmp2);
  return (tmp);
}
