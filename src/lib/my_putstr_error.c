/*
** my_putstr.c for my_putstr.c in /PSU_2015_my_printf
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Thu Oct  1 17:06:54 2015 maud marel
** Last update Fri Mar  4 20:50:49 2016 maud marel
*/

#include <unistd.h>
#include <stdlib.h>

void		my_putstr_error(char *str)
{
  long int	i;

  i = 0;
  while (str && str[i])
    {
      if (write(2, &str[i], 1) == -1)
	exit(1);
      i++;
    }
}
