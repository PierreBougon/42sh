/*
** env.c for env in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Apr 29 18:23:11 2016 marel_m
** Last update Mon May  9 14:22:32 2016 marel_m
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "42s.h"
#include "fptrtab.h"

int	create_env(t_sh *sh)
{
  char	*pwd;

  if ((sh->env->env = malloc(sizeof(char *) * 2)) == NULL
      || (pwd = getcwd(NULL, 0)) == NULL
      || (sh->env->env[0] = strdup("PWD=")) == NULL
      || (sh->env->env[0] = strcat(sh->env->env[0], pwd)) == NULL)
    return (1);
  sh->env->env[1] = NULL;
  sh->env->pst_home = 0;
  sh->env->pst_pwd = 0;
  if ((sh->env->pwd = strdup(pwd)) == NULL
      || (sh->env->path = my_str_to_word_tab("~/bin:/bin:/sbin:/usr/bin:/usr/sbin", ':')) == NULL
      || (sh->env->oldpwd = strdup(pwd)) == NULL)
    return (1);
  return (0);
}

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
    return (1);
  while (env[l] != NULL && env)
    {
      if ((sh->env->env[l] = strdup(env[l])) == NULL)
	return (1);
      l++;
    }
  sh->env->env[l] = NULL;
  return (0);
}

int	check_if_present_in_env(t_sh *sh)
{
  char  *pwd;

  if ((sh->env->pst_path == 0 &&
       (sh->env->path = my_str_to_word_tab("~/bin:/bin:/sbin:/usr/bin:/usr/sbin",
					  ':')) == NULL)
      || (sh->env->pst_pwd == 0 && ((pwd = getcwd(NULL, 0)) == NULL
				|| (sh->env->pwd = strdup(pwd)) == NULL))
      || (sh->env->pst_oldpwd == 0 &&
	  (sh->env->oldpwd = strdup(sh->env->pwd)) == NULL))
    return (-1);
  if (sh->env->pst_home == 0)
    sh->env->home = NULL;
  return (0);
}

t_env_elem	*init_tab_env_elem()
{
  t_env_elem    *tab;

  if ((tab = malloc(sizeof(t_env_elem) * MAX_ELEM_ENV)) == NULL)
    return (NULL);
  tab[PATH].env_elem = "PATH=";
  tab[PATH].ft_env_elem = &check_path;
  tab[HOME].env_elem = "HOME=";
  tab[HOME].ft_env_elem = &check_home;
  tab[PWD].env_elem = "PWD=";
  tab[PWD].ft_env_elem = &check_pwd;
  tab[OLDPWD].env_elem = "OLDPWD=";
  tab[OLDPWD].ft_env_elem = &check_oldpwd;
  return (tab);
}

int		check_if_present_env(t_sh *sh)
{
  int		i;
  int		l;
  t_env_elem	*fptrtab;

  if ((fptrtab = init_tab_env_elem()) == NULL)
    return (1);
  l = 0;
  while (sh->env->env[l] != NULL && sh->env->env)
    {
      i = -1;
      while (++i < MAX_ELEM_ENV)
	if (strncmp(sh->env->env[l], fptrtab[i].env_elem,
		    strlen(fptrtab[i].env_elem)) == 0)
	  if (fptrtab[i].ft_env_elem(sh))
	    return (1);
      l++;
    }
  free(fptrtab);
  if (check_if_present_in_env(sh))
    return (1);
  return (0);
}

int     check_env(t_sh *sh, char **env)
{
  if ((sh->env = malloc(sizeof(t_env))) == NULL)
    return (1);
  if (env[0] == NULL)
    {
      if (create_env(sh))
	return (1);
    }
  else
    if (copy_env(sh, env)
	|| check_if_present_env(sh))
      return (1);
  return (0);
}
