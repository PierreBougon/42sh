/*
** autocompletion.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon May 16 15:27:20 2016 Mathieu Sauvau
** Last update Thu May 19 10:33:45 2016 Mathieu Sauvau
*/

#include <sys/ioctl.h>
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
  //  printf("path %s\n", path);
  while ((dir = readdir(d)))
    {
      if (strncmp(str, dir->d_name, strlen(str)) == 0)
	{
	  printf("name %s\n", dir->d_name);
	  if (!(*res = realloc(*res, strlen(*res) + strlen(dir->d_name) + 6)))
	    return (-1);
	  stat(dir->d_name, &st);
	  strcat(*res, dir->d_name);
	  if (S_ISDIR(st.st_mode))
	    strcat(*res, "/");
	  strcat(*res, " ");
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

  i = strlen(str);
  if (!(path = malloc(i - strlen_b_slash(str) + 1)))
    return (NULL);
  j = 0;
  while (str[--i] != '/' && str[i]);
  while (--i >= 0)
    path[j++] = str[i];
  path[j] = 0;
  if (j == 0 && str[0] != '/')
    {
      path[j++] = '.';
      path[j] = 0;
    }
  else if (str[0] == '/')
    {
      path[j++] = '/';
      path[j] = 0;
    }
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

char	**find_match(char *str)
{
  char	*res;
  char	*s;
  char	*path;
  char	*elem;
  char	**tab;

  if (!(res = malloc(1)))
    return (NULL);
  res[0] = 0;
  if (!(path = get_path(str)))
    return (NULL);
  if (str && str[0])
    {
      if (!(elem = get_elem(str)))
	return (NULL);
    }
  else
    {
      if (!(elem = strdup(str)))
	return (NULL);
    }
  printf("\npath %s\n elem %s\n", path, elem);
  find_in_(path, elem, &res);
  tab =  my_str_to_word_tab(res, ' ');
  free(path);
  free(elem);
  return (tab);
}

int		get_max_len(char **tab)
{
  int		r;
  int		i;

  r = 0;
  i = -1;
  while (tab[++i])
    {
      if (r < (int)strlen(tab[i]))
	r = strlen(tab[i]);
    }
  return (r);
}

void		print_word_tab(char **tab, int nb_col)
{
  int		i;
  int		all;
  int		col_size;

  i = -1;
  all = 0;
  col_size = get_max_len(tab) + 5;
  printf("%d\n", col_size);
  while (tab[++i])
    {
      if (all > nb_col - col_size)
	{
	  all = 0;
	  printf("\n");
	}
      //      if (all != 0)
      printf("%*s ", -col_size, tab[i]);
      /* else */
      /* printf("%s", tab[i]); */
      all += col_size;
    }
  printf("\n");
}

void			auto_complet(char **str, int *pos,
				     UNUSED t_head *history,
				     UNUSED int *i_history)
{
  char			**tab;
  struct winsize	w;

  ioctl(0, TIOCGWINSZ, &w);

  tab = find_match(*str);
  print_word_tab(tab, w.ws_col);
  printf("\nhey ->%s", *str);
  fflush(stdout);
  //  {
      //      free(*str);
      /* *str = */
  //}
}
