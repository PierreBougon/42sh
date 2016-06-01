/*
** auto_completion_find.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue May 24 11:00:59 2016 Mathieu Sauvau
** Last update Wed Jun  1 12:55:59 2016 Mathieu Sauvau
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
  while ((dir = readdir(d)))
    {
      if (dir->d_name[0] != '.' && strncmp(str, dir->d_name, strlen(str)) == 0)
	{
	  if (!(all_dir_path = get_all_dir_path(path, dir->d_name, in_env_path)) ||
	      !get_res(res, all_dir_path, dir->d_name, &st))
	    return (-1);
	  ++i;
	  free(all_dir_path);
	}
    }
  closedir(d);
  return (i);
}

int		get_commmom_subtring(char **tab)
{
  int		i;
  int		j;
  int		k;
  int		i_sub;
  int		i_sub_tmp;
  int		do_break;

  i = -1;
  i_sub = 0;
  while (tab[++i])
    {
      k = 0;
      while (tab[++k])
	{
	  j = -1;
	  i_sub_tmp = 0;
	  while (tab[i][++j] && tab[k][j])
	    {
	      if (tab[i][j] != tab[k][j])
		break;
	      ++i_sub_tmp;
	    }
	  if ((i_sub > i_sub_tmp || i_sub == 0) && i_sub_tmp != 0)
	    i_sub = i_sub_tmp;
	}
    }
  printf("index %d substring %s\n", i_sub, tab[0] + i_sub);
  return (i_sub);
}

int		find_anywhere(char **env_path, char **res, t_autoc *autoc)
{
  int		n;

  n = 0;
  if (autoc->i_elem >= 1)
    {
      if (show_bin(autoc))
	n += find_in_env_path(env_path, autoc->elem, res);
      else
	n += find_in_(autoc->path, autoc->elem, res, 0);
    }
  return (n);
}

char		**find_routine(char **str, char **env_path, t_autoc *autoc)
{
  char		*res;
  char		**tab;
  int		i_sub;

  tab = NULL;
  if (!(res = malloc(1)))
    return (NULL);
  res[0] = 0;
  i_sub = 0;
  find_anywhere(env_path, &res, autoc);
  if ((tab =  my_str_to_word_tab(res, ' ')))
    i_sub = get_commmom_subtring(tab);
  if (!(*str = get_new_str(str, autoc->path, autoc->elem, res)))
    return (NULL);
  //  res[strlen(res) - 1] = 0;
  //  strncpy(*str, *str, strlen(*str) - strlen(autoc->elem));
  strncat(*str, tab[0], i_sub);
  return (free(res), tab);
}

int		separate_path_elem(t_autoc *autoc, char **str, char *cur_str, int pos)
{
  if (!(autoc->path = get_path(cur_str)))
    return (-1);
  if (*str && (*str)[0])
    {
      if (!(autoc->elem = get_elem(cur_str)))
	return (-1);
    }
  else
    {
      if (!(autoc->elem = strdup(cur_str)))
	return (-1);
    }
  if ((autoc->i_elem == 1 && (*str)[0] == '.') ||
      (pos > 1 && (*str)[pos - 1] == ' '))
    {
      autoc->elem[0] = 0;
      autoc->show = 0;
    }
  return (0);
}

char		**find_match(char **env_path, char **str, int pos)
{
  t_autoc	autoc;
  char		**tab;
  char		*cur_str;

  cur_str = *str;
  autoc.tab_str = NULL;
  autoc.show = 1;
  autoc.i_elem = 0;
  if (*str && (*str)[0])
    {
      if ((autoc.tab_str = my_str_to_word_tab(*str, ' ')))
	{
	  autoc.i_elem = nb_word_tab(autoc.tab_str);
	  cur_str = autoc.tab_str[autoc.i_elem - 1];
	}
    }
  if (separate_path_elem(&autoc, str, cur_str, pos) == -1)
    return (NULL);
  printf("\n path %s elem %s\n", autoc.path, autoc.elem);
  tab = find_routine(str, env_path, &autoc);
  free_autoc(&autoc);
  return (tab);
}
