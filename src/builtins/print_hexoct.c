/*
** print_hexoct.c for print in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 31 14:27:01 2016 bougon_p
** Last update Tue May 31 16:09:27 2016 bougon_p
*/

#include "42s.h"

#include <unistd.h>

int		print_hexa_char(char *str)
{
  unsigned int	nb;
  int		i;

  i = 0;
  if ((nb = my_getnbr_base_limit(str, "0123456789abcdef", 3, &i)) <= 0)
    return (0);
  printf("%c", nb);
  return (i);
}

int		print_octal_char(char *str)
{
  unsigned int	nb;
  int		i;

  i = 0;
  if ((nb = my_getnbr_base_limit(str, "01234567", 2, &i)) <= 0)
    return (0);
  printf("%c", nb);
  return (i);
}
