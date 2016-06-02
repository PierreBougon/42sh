/*
** double_left.c for azd in /home/debrau_c/Documents/cours/PSU/PSU_2015_42sh/src
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Wed Jun  1 20:57:19 2016 debrau_c
** Last update Thu Jun  2 16:12:42 2016 debrau_c
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "42s.h"

char	*manage_fin(char *fin, char *str)
{
  int	size;
  char	*new;

  if (!(new = realloc(fin, strlen(fin) + strlen(str) + 2)))
    return (NULL);
  new[(size = strlen(new))] = '\n';
  new[size + 1] = '\0';
  strcat(new, str);
  return (new);
}

int	double_redir_left(UNUSED t_sh *sh, t_node *node)
{
  char	*str;
  char	*fin;

  write(1, "heredoc> ", strlen("heredoc> "));
  fin = NULL;
  change_read_mode(1, 0, 1);
  while ((str = get_next_line(0)) != NULL
	 && strcmp(str, node->arg) != 0)
    {
      if (fin == NULL && (fin = strdup(str)) == NULL)
	return (1);
      else if ((fin = manage_fin(fin, str)) == NULL)
	return (1);
      write(1, "heredoc> ", strlen("\nheredoc> "));
      fflush(stdout);
      free(str);
    }
  change_read_mode(0, 0, 1);
  free(fin);
  return (0);
}
