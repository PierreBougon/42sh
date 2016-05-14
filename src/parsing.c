/*
** parsing.c for parsing in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 11 16:02:55 2016 marel_m
** Last update Sat May 14 16:38:15 2016 marel_m
*/

#include <stdio.h>
#include "42s.h"

int	check_first_priority(char *str)
{
  int	i;
  int	prior;

  i = 0;
  prior = 0;
  while (str[i] != '\0' && str)
    {
      if (str[i] == ';')
	prior = 4;
      else if (((str[i] == '|' && str[i + 1] == '|')
	       || (str[i] == '&' && str[i + 1] == '&'))
	       && prior < 3)
	prior = 3;
      else if ((str[i] == '>' || str[i] == '<') && prior < 2)
	prior = 2;
      else if (str[i] == '|' && prior < 1)
	prior = 1;
      i++;
    }
  return (prior);
}

int	parsing(t_sh *sh, char *str)
{
  int	prior;

  printf("str = %s\n", str);
  prior = check_first_priority(str);
  printf("%d\n", prior);
  if (prior == 4)
    pars_semicolon(sh, str);
  /* else if (prior == 3) */
  /*   pars_double(sh, str); */
  else if (prior == 2)
    pars_redir(sh, str);
  else if (prior == 1)
    pars_pipe(sh, str);
  return (0);
}
