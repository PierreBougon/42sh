/*
** autocompletion.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon May 16 15:27:20 2016 Mathieu Sauvau
** Last update Wed Jun  1 14:36:31 2016 Mathieu Sauvau
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "42s.h"

int		get_commom_subtring(char **tab)
{
  int		i;
  int		j;
  int		k;
  int		i_sub;
  int		i_sub_tmp;

  i = -1;
  i_sub = 0;
  while (tab[++i])
    {
      k = 0;
      while (tab[++k])
	{
	  j = -1;
	  i_sub_tmp = 0;
	  while (tab[i][++j] && tab[k][j] && tab[i][j] == tab[k][j])
	    ++i_sub_tmp;
	  if ((i_sub > i_sub_tmp || i == 0) && i_sub_tmp != 0)
	    i_sub = i_sub_tmp;
	}
    }
  return (i == 1 ? (int)strlen(tab[0]) : i_sub);
}

char		**get_res(char **res, char *all_dir_path,
			  char *d_name, struct stat *st)
{
  if (!(*res = realloc(*res, strlen(*res) + strlen(d_name) + 3)))
    return (NULL);
  if (stat(all_dir_path, st) == -1)
    return (NULL);
  strcat(*res, d_name);
  if (S_ISDIR(st->st_mode))
    strcat(*res, "/");
  strcat(*res, " ");
  return (res);
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
  while (--i >= 0 && str[i] != '/')
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

  if (!str)
    return (NULL);
  i = strlen(str) + 1;
  if (!(path = malloc(i - strlen_b_slash(str) + 2)))
    return (NULL);
  j = 0;
  while (--i >= 0 && str[i] != '/');
  ++i;
  while (--i >= 0)
    path[j++] = str[i];
  path[j] = 0;
  if (j == 0 && str[0] != '/')
    {
      path[j++] = '.';
      path[j] = 0;
    }
  revstr(path);
  return (path);
}

void			auto_complet(char **str, int *pos,
				     t_head *history,
				     UNUSED int *i_history)
{
  char			**tab;
  struct winsize	w;

  ioctl(0, TIOCGWINSZ, &w);
  tab = find_match(history->path, str, *pos);
  print_word_tab(tab, w.ws_col);
  cursor_forward(strlen(*str));
  *pos = strlen(*str);
  printf("\r%s%s", history->prompt, *str);
  free_word_tab(tab);
  fflush(stdout);
}
