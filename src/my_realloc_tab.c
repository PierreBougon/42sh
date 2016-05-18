/*
** my_realloc.c for my_realloc in /home/marel_m/Rendu/Piscine_C/Piscine_C_workshoplib/lib/my
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Nov 23 11:36:14 2015 maud marel
** Last update Wed May 18 18:39:12 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>

char	**my_realloc_tab(char **old, int size)
{
  char	**new;
  int	l;

  if ((new = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  l = 0;
  while (old && old[l] != '\0')
    {
      new[l] = strdup(old[l]);
      free(old[l]);
      l++;
    }
  free(old);
  return (new);
}
