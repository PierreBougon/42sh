/*
** my_itoa.c for azd in /home/debrau_c/Documents/cours/PSU/PSU_2015_42sh
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Fri Jun  3 22:48:53 2016 debrau_c
** Last update Fri Jun  3 23:11:36 2016 debrau_c
*/

#include <stdlib.h>
#include <string.h>

void	my_itoa_revstr(char *str)
{
  int	i;
  int	size;
  char	tmp;

  i = (str[0] == '-') ? 1 : 0;
  size = strlen(str) - 1;
  while (i < size)
    {
      tmp = str[i];
      str[i] = str[size];
      str[size] = tmp;
      i++;
      size--;
    }
}

char	*my_itoa_just_zero()
{
  char	*nb;

  if ((nb = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  nb[0] = '0';
  nb[1] = '\0';
  return (nb);
}

char	*my_itoa(int nb)
{
  char	*str;
  int	i;

  if (nb == 0)
    return (my_itoa_just_zero());
  if ((str = malloc(sizeof(char) * 12)) == NULL)
    return (NULL);
  i = 0;
  if (nb < 0 && (nb *= -1) && (i = 1))
    str[0] = '-';
  while (nb > 0)
    {
      str[i] = (nb % 10) + '0';
      i++;
      nb /= 10;
    }
  str[i] = '\0';
  my_itoa_revstr(str);
  return (str);
}
