/*
** auto_completion_find.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue May 24 11:00:59 2016 Mathieu Sauvau
** Last update Mon May 30 17:58:01 2016 Mathieu Sauvau
*/

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "42s.h"

int		find_in_(char *path, char *str, char **res, int in_env_path)
{
  DIR		*d;
  struct dirent	*dir;
  int		i;
  struct stat	st;
  char		*all_dir_path;

  if (!(d = opendir(path)))
    return (0);
  i = 0;
  /* printf("path %s\n", path); */
  while ((dir = readdir(d)))
    {
      if (dir->d_name[0] != '.' && strncmp(str, dir->d_name, strlen(str)) == 0)
	{
	  /* printf("name %s\n", dir->d_name); */
	  if (!(all_dir_path = get_all_dir_path(path, dir->d_name, in_env_path)) ||
	      !get_res(res, all_dir_path, dir->d_name, &st))
	    return (-1);
	  /* printf("\nall_dir_path %s\n", all_dir_path); */
	  ++i;
	  free(all_dir_path);
	}
    }
  closedir(d);
  return (i);
}

int		find_in_env_path(char **env_path, char *elem, char **res)
{
  int		i;
  int		n;

  i = -1;
  n = 0;
  while (env_path[++i])
    {
      n += find_in_(env_path[i], elem, res, 1);
    }
  return (n);
}

int		find_anywhere(char **env_path, char **res, t_autoc *autoc)
{
  int		n;

  n = 0;
  printf("%d\n", autoc->i_elem);
  if (autoc->i_elem == 0)
    n += find_in_env_path(env_path, autoc->elem, res);
  else
    n += find_in_(autoc->path, autoc->elem, res, 0);
  return (n);
}

int	nb_word_tab(char **tab)
{
  int	i;

  if (!tab)
    return (0);
  i = -1;
  while (tab[++i]);
  return (i - 1);
}

int	add_path(char **env_path, char *path)
{
  int	i;

  i = -1;
  if (strcmp(path, ".") == 0 ||
      strcmp(path, "/") == 0)
    return (0);
  while (env_path[++i])
    {
      if (strcmp(path, env_path[i]) == 0)
	return (0);
    }
  return(1);
}

void	del_substring(char *str, char *to_rm)
{
  while ((str = strstr(str, to_rm)))
    memmove(str, str + strlen(to_rm), 1 + strlen(str + strlen(to_rm)));
}

char	*get_new_str(char **str, char *path, char *elem)
{
  if (!(*str = realloc(*str, strlen(*str) + strlen(path) + 2)))
    return (NULL);
  del_substring(*str, elem);
  return (*str);
}

char		**find_routine(char **str, char **env_path, t_autoc *autoc)
{
  char		*res;
  char		**tab;

  tab = NULL;
  if (!(res = malloc(1)))
    return (NULL);
  res[0] = 0;
  if (find_anywhere(env_path, &res, autoc) == 1)
    {
      if (!get_new_str(str, autoc->path, autoc->elem))
	return (NULL);
      res[strlen(res) - 1] = 0;
      /* if (add_path(env_path,autoc->path)) */
      /* 	strcat(*str, autoc->path); */
      strcat(*str, res);
    }
  else
    tab =  my_str_to_word_tab(res, ' ');
  return (free(res), tab);
}



char		**find_match(char **env_path, char **str)
{
  t_autoc	autoc;
  char		**tab;
  char		*cur_str;

  cur_str = *str;
  autoc.i_elem = 0;
  if (*str && *str[0])
    {
      if ((autoc.tab_str = my_str_to_word_tab(*str, ' ')))
	{
	  autoc.i_elem = nb_word_tab(autoc.tab_str);
	  cur_str = autoc.tab_str[autoc.i_elem];
	}
    }
  if (!(autoc.path = get_path(cur_str)))
    return (NULL);
  if (*str && *str[0])
    {
      if (!(autoc.elem = get_elem(cur_str)))
	return (NULL);
    }
  else
    {
      if (!(autoc.elem = strdup(cur_str)))
	return (NULL);
    }
  tab = find_routine(str, env_path, &autoc);
  printf("\npath %s elem %s\n", autoc.path, autoc.elem);
  /*
FREE AUTOC TAB
   */
  free(autoc.path);
  free(autoc.elem);
  return (tab);
}
