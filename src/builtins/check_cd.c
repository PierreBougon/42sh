/*
** check_cd.c for check_cd in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 13:54:34 2016 marel_m
** Last update Tue May 31 16:03:21 2016 marel_m
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "fptrtab.h"
#include "42s.h"

int	copy_env_pwd(t_sh *sh)
{
  int	l;

  if (sh->env->pst_pwd == 1)
    {
      l = 0;
      while (strncmp(sh->env->env[l], "PWD", 3) != 0)
	l++;
      free(sh->env->env[l]);
      if ((sh->env->env[l] = strdup("PWD=")) == NULL
	  || (sh->env->env[l] = my_strcat(sh->env->env[l], sh->env->pwd)) == NULL)
	return (1);
    }
  return (0);
}

int	cd_action(t_sh *sh)
{
  char	*pwd;

  free(sh->env->oldpwd);
  if ((sh->env->oldpwd = strdup(sh->env->pwd)) == NULL)
    return (1);
  if (sh->env->pst_pwd == 1)
    {
      free(sh->env->pwd);
      if ((pwd = getcwd(NULL, 0)) == NULL
	  || (sh->env->pwd = strdup(pwd)) == NULL
	  || copy_env_pwd(sh))
	return (1);
      free(pwd);
    }
  return (0);
}

t_cd	*init_tab_cd()
{
  t_cd	*tab;
  if ((tab = malloc(sizeof(t_cd) * MAX_CD)) == NULL)
    return (NULL);
  tab[HOME_CD].ft_cd = &check_cd_home;
  tab[DASH_CD].ft_cd = &check_cd_dash;
  tab[GOOD_CD].ft_cd = &check_cd_good;
  tab[ELSE_CD].ft_cd = &check_cd_else;
  return (tab);
}

int	my_cd(t_sh *sh)
{
  t_cd	*fptrtab;
  int	i;
  int	ret;

  i = 0;
  if ((fptrtab = init_tab_cd()) == NULL)
    return (1);
  while (i < MAX_CD)
    {
      ret = fptrtab[i].ft_cd(sh);
      if (ret == -1)
	i++;
      else
	return (free(fptrtab), ret);
    }
  free(fptrtab);
  return (0);
}
