/*
** my_strcat.c for strcat in /home/marel_m/rendu/CPE_2015_corewar/asm
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Mon Mar 14 19:02:45 2016 marel_m
** Last update Wed May 18 19:21:19 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	p;

  i = -1;
  p = -1;
  if ((dest = realloc(dest, (strlen(dest) + strlen(src) + 1))) == NULL)
    return (NULL);
  while (dest[++i] != 0);
  while (src[++p] != 0)
    dest[i++] = src[p];
  dest[i] = 0;
  return (dest);
}
