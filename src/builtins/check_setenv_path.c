/*
** check_setenv_path.c for check_setenv_path in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Jun  3 00:05:25 2016 marel_m
** Last update Fri Jun  3 00:07:52 2016 marel_m
*/

#include <stdlib.h>
#include "42s.h"

int	check_setenv_path(t_sh *sh)
{
  free_tab(sh->env->path);
  free(sh->env->path);
  if (sh->exec->arg[2] == NULL)
    {
      if (check_path_setenv(sh))
	return (1);
    }
  else
    if (check_path(sh))
     return (1);
  return (0);
}
