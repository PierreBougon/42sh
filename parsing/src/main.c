/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:00:58 2016 marel_m
** Last update Fri Apr 29 18:25:27 2016 marel_m
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

void	my_show_tab(char **str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      printf("%s\n", str[i]);
      i++;
    }
}

int	main(int ac, char **av, char **env)
{
  char	*str;
  t_sh	sh;

  if (check_env(&sh, env))
    return (-1);
  while (42)
    {
      printf("kikou -> ");
      if ((str = get_next_line(0)) == NULL)
	return (-1);
    }
  return (0);
}
