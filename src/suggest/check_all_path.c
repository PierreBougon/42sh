/*
** check_all_path.c for check_path in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu May 26 00:32:55 2016 bougon_p
** Last update Thu May 26 13:05:22 2016 bougon_p
*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "42s.h"
#include "suggest.h"

int		check_all_dir(char *dir_name, t_suggest *sugg)
{
  DIR		*dirp;
  struct dirent	*curr_dir;

  if (!(dirp = opendir(dir_name)))
    return (1);
  while ((curr_dir = readdir(dirp)))
    {
      if (strcmp(curr_dir->d_name, ".") != 0
	  && strcmp(curr_dir->d_name, "..") != 0)
	{
	  if (!(sugg->binaries = my_realloc_tabadd(sugg->binaries, 1)))
	    return (1);
	  if (!(sugg->binaries[sugg->nb_bin++] = strdup(curr_dir->d_name)))
	    return (1);
	}
    }
  if (closedir(dirp) == -1)
    return (1);
  return (0);
}

int	check_all_path(t_sh *sh, t_suggest *sugg)
{
  int	i;

  i = -1;
  while (sh->env->path[++i])
    {
      if (check_all_dir(sh->env->path[i], sugg) == 1)
	return (1);
    }
  return (0);
}
