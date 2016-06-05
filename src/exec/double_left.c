/*
** double_left.c for azd in /home/debrau_c/Documents/cours/PSU/PSU_2015_42sh/src
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Wed Jun  1 20:57:19 2016 debrau_c
** Last update Sun Jun  5 21:49:11 2016 DEBRAUWERE Carl
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "42s.h"

char	*manage_fin(char *fin, char *str)
{
  char	*new;

  if (!(new = realloc(fin, strlen(fin) + strlen(str) + 2)))
    return (NULL);
  strcat(new, "\n");
  strcat(new, str);
  return (new);
}

int	prepare_dble_left(t_sh *sh, int new_fd[2], char **fin)
{
  if (pipe(new_fd) < 0)
    exit(1);
  sh->exec->fd[0][0] = new_fd[0];
  *fin = NULL;
  write(1, "? ", strlen("? "));
  return (0);
}

int	double_redir_left(UNUSED t_sh *sh, t_node *node)
{
  char	*str;
  char	*fin;
  int	new_fd[2];

  prepare_dble_left(sh, new_fd, &fin);
  change_read_mode(1, 0, 1);
  while ((str = get_next_line(0)) != NULL && strcmp(str, node->arg) != 0)
    {
      if (fin == NULL && (fin = strdup(str)) == NULL)
	return (1);
      else if ((fin = manage_fin(fin, str)) == NULL)
	return (1);
      write(new_fd[1], fin, strlen(fin));
      write(1, "? ", strlen("\n? "));
      fflush(stdout);
      free(str);
    }
  free(str);
  change_read_mode(0, 0, 1);
  close(new_fd[1]);
  free(fin);
  return (0);
}
