/*
** check_env.c for check_env in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 16:27:42 2016 marel_m
** Last update Wed May 18 18:27:25 2016 marel_m
*/

#include "42s.h"

int	my_env(t_sh *sh)
{
  my_show_tab(sh->env->env);
  return (0);
}
