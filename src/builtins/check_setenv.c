/*
** check_setenv.c for check_setenv in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 15:48:13 2016 marel_m
** Last update Tue May 31 14:54:09 2016 marel_m
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

int	in_env(t_sh *sh, char *name, char *value, int l)
{
  free(sh->env->env[l]);
  if ((sh->env->env[l] = strdup(name)) == NULL
      || (sh->env->env[l] = my_strcat(sh->env->env[l], value)) == NULL)
    return (1);
  return (0);
}

int	out_env(t_sh *sh, char *name, char *value, int l)
{
  if ((sh->env->env = my_realloc_tab(sh->env->env, (l + 1))) == NULL
      || (sh->env->env[l] = strdup(name)) == NULL
      || (sh->env->env[l] = my_strcat(sh->env->env[l], value)) == NULL)
    return (1);
  sh->env->env[++l] = NULL;
  return (0);
}

int	copy_setenv_env(t_sh *sh, char *name, char *value)
{
  int	l;

  l = 0;
  while (sh->env->env[l] != '\0' && sh->env->env
	 && strncmp(sh->env->env[l], name, strlen(name)) != 0)
    l++;
  if (sh->env->env[l] == NULL)
    {
      if (out_env(sh, name, value, l))
	return (1);
    }
  else
    if (in_env(sh, name, value, l))
      return (1);
  return (0);
}

int	action_setenv(t_sh *sh)
{
  char	*name;
  char	*value;

  if ((name = strdup(sh->exec->arg[1])) == NULL
      || (name = my_strcat(name, "=")) == NULL)
    return (1);
  if (sh->exec->arg[2] == '\0')
    {
      if ((value = strdup("\0")) == NULL)
	return (1);
    }
  else if ((value = strdup(sh->exec->arg[2])) == NULL)
    return (1);
  if (copy_setenv_env(sh, name, value))
    return (1);
  free(name);
  free(value);
  return (0);
}

int	my_setenv(t_sh *sh)
{
  if (sh->exec->arg[1] == '\0')
    my_show_tab(sh->env->env);
  else if (sh->exec->arg[2] == '\0' || sh->exec->arg[3] == '\0')
    {
      if (action_setenv(sh))
	return (1);
    }
  else if (sh->exec->arg[3] != '\0')
    {
      write(2, "setenv : Too many arguments.\n", 29);
      sh->exit = 1;
    }
  if (sh->exec->arg[1] != '\0' && strcmp(sh->exec->arg[1], "PATH") == 0)
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
    }
  return (0);
}
