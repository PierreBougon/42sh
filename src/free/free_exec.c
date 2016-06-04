/*
** free_exec.c for free_struct in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue May 24 13:18:46 2016 marel_m
** Last update Sat Jun  4 20:30:33 2016 marel_m
*/

#include <stdlib.h>
#include "42s.h"

void	free_exec(t_exec *exec)
{

  free_tab(exec->arg);
  my_free((void **)exec->arg);
  my_free((void **)&(exec)->exec);
  my_free((void **)&(exec)->good_path);
  /* free_tab_int((*exec)->fd); */
  my_free((void **)&(exec)->fd);
  my_free((void **)&(exec));
}

void		free_tree(t_list_sh *list)
{
  int		i;
  t_node	*tmp;
  t_node	*save;

  i = 0;
  tmp = list->node;
  while (i < list->nb)
    {
      save = tmp;
      tmp = tmp->right;

      if (save->left != NULL)
	my_free((void **)&(save)->left->arg);
      my_free((void **)&(save)->left);
      my_free((void **)&(save)->arg);
      my_free((void **)&(save));
      i++;
    }
}

void		free_list(t_sh *sh)
{
  int		i;
  t_list_sh	*tmp;
  t_list_sh	*save;

  i = 0;
  tmp = sh->root->next;
  while (i < sh->lenght - 1)
    {
      save = tmp;
      tmp = tmp->next;
      free_tree(save);
      my_free((void **)&(save)->arg);
      my_free((void **)&save);
      i++;
    }
  sh->lenght = 0;
}

void	free_struct(t_sh *sh)
{
  free_list(sh);
  my_free((void **)&(sh)->root);
  free_exec(sh->exec);
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
