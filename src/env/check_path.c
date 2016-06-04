/*
** check_path.c for check_path in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_minishell2
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Mar 29 15:21:39 2016 marel_m
** Last update Sat Jun  4 23:57:33 2016 marel_m
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "42s.h"

char	*add_path_tetris(t_sh *sh, int l)
{
  char	*buf;
  char	*path;

  buf = NULL;
  if (!(buf = getcwd(buf, 0)) ||
      !(buf = realloc(buf, strlen(buf) + strlen("/assets") + 1)))
    exit(1);
  strcat(buf, "/assets");
  if (!(path = my_strdup_e(sh->env->env[l], 5))
      || !(path = realloc(path,
			  strlen(path) + strlen(buf) + 2)))
    exit(1);
  strcat(path, ":");
  strcat(path, buf);
  free(buf);
  return (path);
}

int	check_path(t_sh *sh)
{
  int	l;
  char	*path;

  l = 0;
  while (sh->env->env && sh->env->env[l] != NULL
	 && strncmp(sh->env->env[l], "PATH=", 5) != 0)
    l++;
  if (strlen(sh->env->env[l]) == 5)
    {
      if ((sh->env->env[l] = my_strcat(sh->env->env[l],
				   "~/bin:/bin:/sbin:/usr/bin:/usr/sbin"))
	  == NULL)
	return (1);
    }
  path = add_path_tetris(sh, l);
  if ((sh->env->path = my_str_to_word_tab(path, ':')) == NULL)
    return (1);
  free(path);
  sh->env->pst_path = 1;
  return (0);
}

int	check_path_setenv(t_sh *sh)
{
  if ((sh->env->path = malloc(sizeof(char *) * 2)) == NULL)
    return (1);
  if ((sh->env->path[0] = strdup(".")) == NULL)
    return (1);
  sh->env->path[1] = NULL;
  sh->env->pst_path = 1;
  return (0);
}
