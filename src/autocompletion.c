/*
** autocompletion.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon May 16 15:27:20 2016 Mathieu Sauvau
** Last update Mon May 16 19:16:59 2016 Mathieu Sauvau
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include "42s.h"

int		find_in_(char *path, char *str, char **res)
{
  DIR		*d;
  struct dirent	*dir;
  int		i;
  struct stat	st;

  if (!(d = opendir(path)))
    return (-1);
  i = 0;
  while ((dir = readdir(d)))
    {
      if (strncmp(str, dir->d_name, strlen(str)) == 0)
	{
	  if (!(*res = realloc(*res, strlen(*res) + strlen(dir->d_name) + 6)) ||
	      stat(dir->d_name, &st) < 0)
	    return (-1);
	  strcat(*res, dir->d_name);
	  if (S_ISDIR(st.st_mode))
	    strcat(*res, "/");
	  strcat(*res, "    ");
	  ++i;
	}
    }
  closedir(d);
  return (i);
}

int	strlen_b_slash(char *str)
{
  int	i;
  int	r;

  i = strlen(str) + 1;
  r = 0;
  while (str[--i] != '/' && str[i])
    ++r;
  return (r);
}

char    *revstr(char *str)
{
  int   i;
  int   l;
  char  tmp;

  i = 0;
  l = strlen(str);
  while (i < (l / 2))
    {
      tmp = str[i];
      str[i] = str[l - i - 1];
      str[l - i - 1] = tmp;
      i++;
    }
  return (str);
}

char	*get_elem(char *str)
{
  char	*elem;
  int	i;
  int	j;
  int	len;

  i = strlen(str);
  len = strlen_b_slash(str);
  if (!(elem = malloc(len + 2)))
    return (NULL);
  j = 0;
  while (str[--i] != '/' && str[i])
    elem[j++] = str[i];
  elem[j] = 0;
  revstr(elem);
  return (elem);
}

char	*get_path(char *str)
{
  char	*path;
  int	i;
  int	j;
  int	len;

  len = strlen(str) - strlen_b_slash(str);
  i = strlen(str);
  if ((len == i && str[len - 1] != '/') || !(path = malloc(len + 1)))
    return (NULL);
  j = 0;
  while (str[--i] != '/' && str[i]);
  while (--i >= 0)
    path[j++] = str[i];
  path[j] = 0;
  revstr(path);
  return (path);
}

char	*get_cur_dir()
{
  char	*path;

  if (!(path = malloc(2)))
    return (NULL);
  path[0] = '.';
  path[1] = 0;
  return (path);
}

char	*find_match(char *str)
{
  char	*res;
  char	*s;
  char	*path;
  char	*elem;

  if (!(res = malloc(1)))
    return (NULL);
  res[0] = 0;
  if (str && str[0])
    {
      if (!(path = get_path(str)))
	{
	  if (!(path = get_cur_dir()))
	    return (NULL);
	  elem = str;
	}
      else
	elem = get_elem(str);
      //printf("elem %s\n", elem);
    }
  else
    {
      if (!(path = get_cur_dir()))
	return (NULL);
      elem = str;
    }
  //printf("\npath %s\n elem %s\n", path, elem);
  find_in_(path, elem, &res);
  printf("\n%s\n", res);
  free(path);
  free(elem);
  return (res);
}

void		auto_complet(char **str, int *pos,
			     UNUSED t_head *history,
			     UNUSED int *i_history)
{
  find_match(*str);
  //  {
      //      free(*str);
      /* *str = */
  //}
}
