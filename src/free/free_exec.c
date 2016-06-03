/*
** free_exec.c for free_struct in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue May 24 13:18:46 2016 marel_m
** Last update Fri Jun  3 13:26:59 2016 marel_m
*/

#include <stdlib.h>
#include "42s.h"

void	free_exec(t_exec *exec)
{
  free_tab(exec->arg);
  free(exec->arg);
  free(exec->exec);
  free(exec->good_path);
  /* free_tab_int(exec->fd); */
  free(exec->fd);
  free(exec);
}

void		free_list(t_sh *sh)
{
  int		i;
  t_list_sh	*tmp;
  t_list_sh	*tmp2;

  i = 0;
  tmp2 = sh->root->next;
  while (i < sh->lenght - 2)
    {
      i++;
      tmp = tmp2;
      tmp2 = tmp->next;
      /* free_tree(tmp->node); */
      free(tmp);
    }
}

void	free_env(t_env *env)
{
  free_tab(env->env);
  free(env->env);
  free_tab(env->path);
  free(env->path);
  free(env->pwd);
  free(env->oldpwd);
  free(env->home);
  free(env);
}

void	free_struct(t_sh *sh)
{
  free_list(sh);
}
