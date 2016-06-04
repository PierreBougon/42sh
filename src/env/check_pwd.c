/*
** check_pwd.c for check_pwd in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_minishell2
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Mar 29 15:24:04 2016 marel_m
** Last update Sat Jun  4 20:33:35 2016 debrau_c
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"

int	check_pwd(t_sh *sh)
{
  int	l;

  l = 0;
  while (sh->env->env && sh->env->env[l] != '\0'
	 && strncmp(sh->env->env[l], "PWD=", 4) != 0)
    l++;
  if ((sh->env->pwd = my_strdup_e(sh->env->env[l], 4)) == NULL)
    return (-1);
  sh->env->pst_pwd = 1;
  return (0);
}
