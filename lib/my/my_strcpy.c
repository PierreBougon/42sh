/*
** my_strcpy.c for my_strcpy in /home/marel_m/rendu/Piscine_C_J06/ex_02
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Oct  5 11:19:50 2015 maud marel
** Last update Tue Mar  1 14:25:01 2016 maud marel
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
