/*
** check_good_path.c for check_good_path in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 17:33:30 2016 marel_m
** Last update Thu May 26 13:46:14 2016 bougon_p
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

void	wrong_access(t_sh *sh)
{
  write(2, sh->exec->exec, strlen(sh->exec->exec));
  write(2, ": Access required.\n", 19);
  suggest(sh, sh->exec->exec);
}

void	wrong_command(t_sh *sh)
{
  write(2, sh->exec->exec, strlen(sh->exec->exec));
  write(2, ": Command not found.\n", 21);
  suggest(sh, sh->exec->exec);
}

int	check_wrong_path(t_sh *sh)
{
  if (sh->exec->good_path == '\0')
    {
      write(2, sh->exec->exec, strlen(sh->exec->exec));
      write(2, ": Command not found.\n", 21);
      suggest(sh, sh->exec->exec);
      return (1);
    }
  if (access(sh->exec->good_path, F_OK) == 0)
    if (access(sh->exec->good_path, X_OK) == 0)
      return (0);
    else
      return (wrong_access(sh), 1);
  else
    return (wrong_command(sh), 1);
  return (0);
}

int	check_good_path_normal_case(t_sh *sh)
{
  int	i;

  i = -1;
  while (sh->env->path[++i] != '\0' && sh->env->path)
    {
      if ((sh->exec->good_path = strdup(sh->env->path[i])) == NULL
	  || (sh->exec->good_path = my_strcat(sh->exec->good_path, "/")) == NULL
	  || (sh->exec->good_path = my_strcat(sh->exec->good_path, sh->exec->exec)) == NULL)
	return (1);
      if (access(sh->exec->good_path, F_OK) == 0
	  && access(sh->exec->good_path, X_OK) == 0)
	return (-1);
    }
  return (0);
}

int	check_good_path(t_sh *sh)
{
  int	ret;

  if (sh->exec->exec[0] == '/')
    {
      if ((sh->exec->good_path = strdup(sh->exec->exec)) == NULL)
	return (1);
      if (access(sh->exec->exec, F_OK) == 0 && access(sh->exec->exec, X_OK) == 0)
	return (0);
    }
  else if (strncmp(sh->exec->exec, "./", 2) == 0
	   || strncmp(sh->exec->exec, "../", 2) == 0)
    {
      if ((sh->exec->good_path = strdup(sh->exec->exec)) == NULL)
	return (1);
    }
  else
    if ((ret = check_good_path_normal_case(sh)) != 0)
      return (ret);
  if (check_wrong_path(sh))
    return (-1);
  return (0);
}
