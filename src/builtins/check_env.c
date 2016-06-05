/*
** check_env.c for check_env in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 16:27:42 2016 marel_m
** Last update Sun Jun  5 11:26:21 2016 bougon_p
*/

#include "42s.h"
#include "my.h"

int	my_env(t_sh *sh)
{
  int	fd;

  if ((fd = sh->exec->fd[0][1]) == -1)
    fd = 1;
  my_show_tab_fd(sh->env->env, fd);
  return (0);
}
