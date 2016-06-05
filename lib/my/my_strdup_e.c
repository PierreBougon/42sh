/*
** my_strdup.c for my_strdup in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Tue Mar  8 09:15:03 2016 maud marel
** Last update Sun Jun  5 17:50:34 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"

char	*my_strdup_e(char *str, int i)
{
  char	*new;
  int	j;

  j = 0;
  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str && str[i])
    {
      new[j] = str[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}
