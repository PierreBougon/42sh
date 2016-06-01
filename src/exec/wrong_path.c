/*
** wrong_path.c for wrong_path in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue May 31 23:30:58 2016 marel_m
** Last update Tue May 31 23:39:07 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

int	wrong_access(t_sh *sh)
{
  write(2, sh->exec->exec, strlen(sh->exec->exec));
  write(2, ": Access required.\n", 19);
  if (suggest(sh, sh->exec->exec) == 1)
    return (1);
  return (0);
}

int	wrong_command(t_sh *sh)
{
  write(2, sh->exec->exec, strlen(sh->exec->exec));
  write(2, ": Command not found.\n", 21);
  if (suggest(sh, sh->exec->exec) == 1)
    return (1);
  return (0);
}

int	check_wrong_path(t_sh *sh)
{
  sh->exec->stop = 1;
  if (strncmp(sh->exec->exec, "./", 2) == 0)
    {
      if ((sh->exec->exec
	   = my_strdup_bt(sh->exec->exec, 2, strlen(sh->exec->exec))) == NULL)
	return (1);
    }
  if (sh->exec->good_path == '\0')
    {
      write(2, sh->exec->exec, strlen(sh->exec->exec));
      write(2, ": Command not found.\n", 21);
      if (suggest(sh, sh->exec->exec) == 1)
	return (sh->exit = 1, 1);
      return (sh->exit = 1, 1);
    }
  if (access(sh->exec->good_path, F_OK) == 0)
    {
      if (access(sh->exec->good_path, X_OK) == 0)
	return (0);
      else
	return (sh->exit = 1, wrong_access(sh), 1);
    }
  else
    return (sh->exit = 1, wrong_command(sh), 1);
  return (0);
}
