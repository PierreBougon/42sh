/*
** check_if_missing_name.c for check_if_missing_name in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jun  1 14:34:32 2016 marel_m
** Last update Wed Jun  1 15:02:36 2016 marel_m
*/

#include <unistd.h>
#include "42s.h"

int	check_if_missing_name(t_sh *sh, char *str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      if ((str[i] != '\0' && str[i + 1] != '\0' && str[i + 2] != '\0')
	  && ((str[i] == '<' && str[i + 1] == ' ' && str[i + 2] == '<')
	      || (str[i] == '>' && str[i + 1] == ' ' && str[i + 2] == '>')))
	{
	  sh->exit = 1;
	  write(2, "Missing name for redirect.\n", 27);
	  return (1);
	}
      i++;
    }
  return (0);
}
