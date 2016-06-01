/*
** convert_base.c for base in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 31 14:13:43 2016 bougon_p
** Last update Tue May 31 16:09:17 2016 bougon_p
*/

#include <string.h>
#include "42s.h"

int	cupper(int c)
{
  if (c >= 'a' && c <= 'z')
    c -= 32;
  return (c);
}

int	check_base(char *base)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (base[i] != '\0')
    {
      while (base[j] != '\0')
	{
	  if (i != j && cupper((int)base[i]) == cupper((int)base[j]))
	    return (-1);
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
  return (0);
}

unsigned int	my_getnbr_base_limit(char *str, char *base,
				     unsigned int limit, int *n)
{
  unsigned int	nb;
  unsigned int	size_base;
  unsigned int	i;
  unsigned int	j;

  size_base = strlen(base);
  nb = 0;
  i = 0;
  if (check_base(base) == -1)
    return (0);
  while (str[i] != '\0' && i < limit)
    {
      j = 0;
      while (j < size_base && base[j] != str[i])
        j = j + 1;
      if (cupper((int)base[j]) == cupper((int)str[i]))
        nb = nb * size_base + j;
      else
        if ((str[i] != '-' && str[i] != '+'))
	  {
	    *n = i - 1;
	    return (nb);
	  }
      i = i + 1;
    }
  *n = i;
  return (nb);
}
