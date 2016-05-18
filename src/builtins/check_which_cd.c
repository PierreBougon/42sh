/*
** check_which_cd.c for check_which_cd in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 14:12:02 2016 marel_m
** Last update Wed May 18 18:33:13 2016 marel_m
*/

#include <string.h>
#include <unistd.h>
#include "42s.h"

int	check_cd_home(t_sh *sh)
{
  if (sh->exec->arg[1] != NULL && strcmp(sh->exec->arg[1], "~") != 0)
    return (-1);
  if (sh->env->pst_home == 1)
    {
      if (chdir(sh->env->home) == -1
	  || cd_action(sh))
	return (1);
    }
  else if (sh->exec->arg[1] == NULL)
    write(2, "cd : No home directory\n", 23);
  else
    write(2, "No $home variable set.\n", 23);
  return (0);
}

int	check_cd_dash(t_sh *sh)
{
  if (strcmp(sh->exec->arg[1], "-") != 0)
    return (-1);
  if (chdir(sh->env->oldpwd) == -1
      || cd_action(sh))
    return (1);
  return (0);
}

int	check_cd_good(t_sh *sh)
{
  if (sh->exec->arg[2] != NULL)
    return (-1);
  if (chdir(sh->exec->arg[1]) == -1)
    {
      write(2, "cd: no such file or direcory: ", 30);
      write(2, sh->exec->arg[1], strlen(sh->exec->arg[1]));
      write(2, "\n", 1);
      return (0);
    }
  if (cd_action(sh))
    return (1);
  return (0);
}

int	check_cd_else(t_sh *sh)
{
  if (sh->exec->arg[2] != '\0')
    write(2, "Too much arguments\n", 19);
  return (0);
}
