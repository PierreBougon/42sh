/*
** my_put_nbr.c for my_put_nbr in /PSU_2015_my_printf
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Wed Sep 30 14:07:08 2015 maud marel
** Last update Fri Mar 18 14:32:16 2016 
*/

#include "my.h"

int	isneg2(int *nb)
{
  if (*nb < 0)
  {
    my_putchar('-');
    *nb = -(*nb);
    return (1);
  }
  return (0);
}

int	my_put_nbr(int nb)
{
  int	div_nbr;
  int	result;
  int	len;

  div_nbr = 1;
  result = 0;
  len = 0;
  if (nb == -2147483648)
    {
      my_putstr("-2147483648");
      return (11);
    }
  len = isneg2(&nb);
  while ((nb / div_nbr) >= 10)
    div_nbr = div_nbr * 10;
  while (div_nbr > 0)
    {
      result = (nb / div_nbr) % 10;
      my_putchar(48 + result);
      div_nbr = div_nbr / 10;
      len++;
    }
  return (len);
}
