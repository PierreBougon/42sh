/*
** auto_completion_utility.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue May 24 11:01:19 2016 Mathieu Sauvau
** Last update Fri Jun  3 18:45:43 2016 marel_m
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "42s.h"

char	*get_all_dir_path(char *path, char *d_name, int in_env_path)
{
  char	*all_dir_path;

  if (!(all_dir_path = malloc(strlen(d_name) + strlen(path) + 2)))
    return (NULL);
  all_dir_path[0] = 0;
  strcat(all_dir_path, path);
  if (path[0] == '.' || in_env_path)
    strcat(all_dir_path, "/");
  strcat(all_dir_path, d_name);
  return (all_dir_path);
}

int	get_max_len(char **tab)
{
  int	r;
  int	i;

  r = 0;
  i = -1;
  while (tab[++i])
    {
      if (r < (int)strlen(tab[i]))
	r = strlen(tab[i]);
    }
  return (r);
}

int	strlen_b_slash(char *str)
{
  int	i;
  int	r;

  i = strlen(str) + 1;
  r = 0;
  while (--i >= 0 && str[i] != '/')
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

void	print_word_tab(char **tab, int nb_col)
{
  int	i;
  int	all;
  int	col_size;

  i = -1;
  all = 0;
  if (!tab)
    return ;
  col_size = get_max_len(tab) + 5;
  while (tab[++i])
    {
      if (all > nb_col - col_size - 5 || i == 0)
	{
	  all = 0;
	  printf("\n");
	}
      printf("%*s ", -col_size, tab[i]);
      all += col_size;
    }
  printf("\n");
}
