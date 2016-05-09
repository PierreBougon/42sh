/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:00:58 2016 marel_m
** Last update Sat May  7 18:18:09 2016 marel_m
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
      write(1, "hey ->", 7);
      if ((str = get_next_line(0)) == NULL)
	return (-1);
      write(1, str, strlen(str));
    }
  return (0);
}
