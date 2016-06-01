/*
** auto_completion_utility2.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue May 31 12:07:06 2016 Mathieu Sauvau
** Last update Wed Jun  1 12:42:04 2016 Mathieu Sauvau
*/

#include <string.h>
#include <stdlib.h>
#include "42s.h"

int	nb_word_tab(char **tab)
{
  int	i;

  if (!tab)
    return (0);
  i = -1;
  while (tab[++i]);
  return (i);
}

void	del_substring(char *str, char *to_rm)
{
  while ((str = strstr(str, to_rm)))
    memmove(str, str + strlen(to_rm), 1 + strlen(str + strlen(to_rm)));
}

char	*get_new_str(char **str, char *path, char *elem, char *res)
{
  char	*new;

  if (!(new = malloc(strlen(*str) + strlen(path) + strlen(res) + 1)))
    return (NULL);
  printf("truncate %s\n", *str + strlen(*str) - strlen(elem));
  strncpy(new, *str, strlen(*str) <= strlen(elem) ?
	  0 : strlen(*str) - strlen(elem));
  new[strlen(*str) - strlen(elem)] = 0;
  free(*str);
  //  del_substring(*str, elem);
  return (new);
}

void		free_word_tab(char **tab)
{
  int		i;

  i = -1;
  while (tab && tab[++i])
      free(tab[i]);
  free(tab);
}

void		free_autoc(t_autoc *autoc)
{
  if (autoc->tab_str)
    free_word_tab(autoc->tab_str);
  free(autoc->path);
  free(autoc->elem);
}
