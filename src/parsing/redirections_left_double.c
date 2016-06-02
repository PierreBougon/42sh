/*
** redirections_left_double.c for redirections_left_double in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Jun  1 22:10:30 2016 marel_m
** Last update Wed Jun  1 23:55:24 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>
#include "42s.h"

char	*pars_double_redirection_left(t_list_sh *elem, char *str, int i)
{
  char	*new;
  char	*tmp;
  int	j;

  j = i;
  while (str && str[j] != '\0' && str[j] != ' ' && str[j] != '|')
    j++;
  new = strndup(str, i - 1);
  tmp = my_strdup_e(str, j);
  if (strlen(tmp) != 0)
    {
      new = realloc(new, strlen(new) + strlen(tmp) + 2);
      new = strcat(new, tmp);
    }
  printf("%s %s\n", my_strdup_bt(str, i + 1, j), new);
  if (insert_node(&elem->node, my_strdup_bt(str, i + 1, j),
		  new, DOUBLE_REDIR_LEFT) == NULL)
    return (NULL);
  free(tmp);
  return (new);
}
