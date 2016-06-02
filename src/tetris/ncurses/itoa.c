/*
** itoa.c for itoa in /home/sauvau_m/rendu/gfx_tekdoom/menu_wip
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Fri Jan 22 16:03:20 2016 Mathieu Sauvau
** Last update Thu Mar 17 11:54:00 2016 
*/

#include "tetris.h"

char	*my_revstr(char *str)
{
  int   i;
  int   l;
  char  tmp;

  i = 0;
  l = my_strlen(str);
  while (i < (l / 2))
    {
      tmp = str[i];
      str[i] = str[l - i - 1];
      str[l - i - 1] = tmp;
      i++;
    }
  return (str);
}

char	*finish(char *str, bool neg, int i)
{
  if (neg)
    str[i++] = '-';
  str[i] = 0;
  my_revstr(str);
  return (str);
}

char	*itoa(int nb, char* str, int base)
{
  int	i;
  bool	neg;
  int	r;

  neg = false;
  i = 0;
  if (nb == 0)
    {
      str[i++] = '0';
      str[i] = '\0';
      return (str);
    }
  if (nb < 0 && base == 10)
    {
      neg = true;
      nb = -nb;
    }
  while (nb != 0)
    {
      r = nb % base;
      str[i++] = (r > 9)? (r - 10) + 'a' : r + '0';
      nb = nb / base;
    }
  return (finish(str, neg, i));
}
