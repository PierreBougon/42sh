/*
** env.c for env in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Apr 29 18:23:11 2016 marel_m
** Last update Fri Apr 29 18:24:26 2016 marel_m
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "mysh.h"

int     nb_line(char **env)
{
  int   i;

  i = 0;
  while (env[i] != NULL && env)
    i++;
  return (i);
}

int     copy_env(t_sh *sh, char **env)
{
  int   l;
  int   nb_l;

  l = 0;
  nb_l = nb_line(env);
  if ((sh->env->env = malloc(sizeof(char *) * (nb_l + 1))) == NULL)
    return (-1);
  while (env[l] != NULL && env)
    {
      if ((sh->env->env[l] = strdup(env[l])) == NULL)
	return (-1);
      l++;
    }
  sh->env->env[l] = '\0';
  return (0);
}

int     check_env(t_sh *sh, char **env)
{
  if ((sh->env = malloc(sizeof(sh->env))) == NULL)
    return (1);
  if (copy_env(sh, env))
    return (1);
  my_show_tab(sh->env->env);
  return (0);
}
