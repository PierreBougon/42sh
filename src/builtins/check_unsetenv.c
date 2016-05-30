/*
** check_unsetenv.c for check_unsetenv in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 16:11:47 2016 marel_m
** Last update Mon May 30 22:39:21 2016 marel_m
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

char	**take_away_env(t_sh *sh, int l)
{
  char	**new;
  int	nb;
  int	nb2;

  nb = 0;
  while (sh->env->env && sh->env->env[nb] != '\0')
    nb++;
  if ((new = malloc(sizeof(char *) * nb)) == NULL)
    return (NULL);
  nb = 0;
  nb2 = 0;
  while (sh->env->env[nb2] != '\0' && sh->env->env)
    {
      if (nb2 != l)
	if ((new[nb++] = strdup(sh->env->env[nb2])) == NULL)
	  return (NULL);
      nb2++;
    }
  new[nb] = NULL;
  free_tab(sh->env->env);
  return (new);
}

int	my_unsetenv(t_sh *sh)
{
  int	nb;
  int	l;

  if (sh->exec->arg[1] == NULL)
    return (write(2, "unsetenv: Too few arguments.\n", 29), -1);
  nb = 1;
  while (sh->exec->arg[nb] != NULL)
    {
      if (strcmp(sh->exec->arg[1], "PWD") == 0)
	sh->env->pst_pwd = 0;
      if (strcmp(sh->exec->arg[1], "PATH") == 0)
	sh->env->pst_path = 0;
      l = 0;
      if ((sh->exec->arg[nb] = my_strcat(sh->exec->arg[nb], "=")) == NULL)
	return (1);
      while (sh->env->env[l] != '\0' && sh->env->env
	     && strncmp(sh->env->env[l], sh->exec->arg[nb],
			strlen(sh->exec->arg[nb])) != 0)
	l++;
      if (sh->env->env[l] != '\0')
	if ((sh->env->env = take_away_env(sh, l)) == NULL)
	  return (1);
      nb++;
    }
  return (0);
}
