/*
** parsing_sep.c for parsing_sep in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 13 15:22:08 2016 marel_m
** Last update Mon May 23 18:58:57 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"

char	*pars_pipe(t_list_sh *elem, char *str)
{
  int	i;
  char	*new;

  i = my_strlen(str) - 1;
  while (str[i] != '|')
    i--;
  if (insert_node(&elem->node, my_strdup_e(str, i + 1), strndup(str, i), PIPE)
      == NULL || (new = strndup(str, i)) == NULL)
    return (NULL);
  free(str);
  return (new);
}

char	*pars_redir_right(t_list_sh *elem, char *str)
{
  int	i;
  char	*new;

  i = my_strlen(str) - 1;
  while (str[i] != '>')
    i--;
  if (str[i - 1] != '>')
    {
      if (insert_node(&elem->node, my_strdup_e(str, i + 1), strndup(str, i),
		      REDIR_RIGHT) == NULL || (new = strndup(str, i)) == NULL)
	return (NULL);
    }
  else
    {
      if (insert_node(&elem->node, my_strdup_e(str, i + 1), strndup(str, i - 1),
		      DOUBLE_REDIR_RIGHT) == NULL
	  || (new = strndup(str, i - 1)) == NULL)
	return (NULL);
    }
  free(str);
  return (new);
}

char	*pars_redir_left(t_list_sh *elem, char *str)
{
  char	*new;
  int   i;

  i = my_strlen(str) - 1;
  while (str[i] != '<')
    i--;
  if (insert_node(&elem->node, my_strdup_e(str, i + 1), strndup(str, i),
		  REDIR_LEFT) == NULL || (new = strndup(str, i)) == NULL)
    return (NULL);
  free(str);
  return (new);
}

char	*pars_redir(t_list_sh *elem, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str)
    {
      if (str[i] == '>')
	return (pars_redir_right(elem, str));
      i++;
    }
  return (pars_redir_left(elem, str));
}

/* int	pars_double_redir_left(t_list_sh *elem, char *str, t_dir dir) */
/* { */
/*   return (0); */
/* } */
