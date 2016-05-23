/*
** auto_completion_find.c for  in /home/mathieu/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <mathieu@epitech.net>
**
** Started on  Mon May 23 18:28:53 2016 Mathieu Sauvau
** Last update Mon May 23 18:48:42 2016 Mathieu Sauvau
*/

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "42s.h"

int		find_in_(char *path, char *str, char **res)
{
  DIR		*d;
  struct dirent	*dir;
  int		i;
  struct stat	st;
  char		*all_dir_path;

  if (!(d = opendir(path)))
    return (-1);
  i = 0;
  //  printf("path %s\n", path);
  while ((dir = readdir(d)))
    {
      if (dir->d_name[0] != '.' && strncmp(str, dir->d_name, strlen(str)) == 0)
	{
	  /* printf("name %s\n", dir->d_name); */
	  if (!(all_dir_path = get_all_dir_path(path, dir->d_name)) ||
	      !get_res(res, all_dir_path, dir->d_name,  &st))
	    return (-1);
	  /* printf("\nall_dir_path %s\n", all_dir_path); */
	  ++i;
	  free(all_dir_path);
	}
    }
  closedir(d);
  return (i);
}

char	**find_routine(char **str, char *path, char *elem)
{
  char	*res;
  char	**tab;

  tab = NULL;
  if (!(res = malloc(1)))
    return (NULL);
  res[0] = 0;
  if ((find_in_(path, elem, &res)) == 1)
    {
      free(*str);
      if (strcmp(path, ".") != 0)
      	*str = malloc(strlen(res) + strlen(path) + 1);
      else
      	*str = malloc(strlen(res) + 1);
      if (!*str)
      	return (NULL);
      res[strlen(res) - 1] = 0;
      *str[0] = 0;
      if (strcmp(path, ".") != 0)
	strcat(*str, path);
      strcat(*str, res);
    }
  else
    tab =  my_str_to_word_tab(res, ' ');
  return (free(res), tab);
}

char	**find_match(char **str)
{
  char	*path;
  char	*elem;
  char	**tab;

  if (!(path = get_path(*str)))
    return (NULL);
  if (*str && *str[0])
    {
      if (!(elem = get_elem(*str)))
	return (NULL);
    }
  else
    {
      if (!(elem = strdup(*str)))
	return (NULL);
    }
  tab = find_routine(str, path, elem);
  /* printf("\npath %s elem %s\n", path, elem); */
  free(path);
  free(elem);
  return (tab);
}
