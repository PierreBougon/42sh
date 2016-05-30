/*
** autocompletion.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Mon May 16 15:27:20 2016 Mathieu Sauvau
** Last update Mon May 30 16:02:12 2016 Mathieu Sauvau
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "42s.h"

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
  /* printf("%s\n", *res); */
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
  tab = find_match(history->path, str);
  print_word_tab(tab, w.ws_col);
  cursor_forward(strlen(*str));
  *pos = strlen(*str);
  printf("\nhey ->%s", *str);
  fflush(stdout);
}
