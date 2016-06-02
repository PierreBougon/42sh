/*
** parsing_sep.c for parsing_sep in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 13 15:22:08 2016 marel_m
** Last update Thu Jun  2 08:17:37 2016 marel_m
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
  if (insert_node(&elem->node, my_strdup_e(str, i + 1),
		  (new = strndup(str, i)), PIPE) == NULL)
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
  if (i == 0)
    return (NULL);
  if (str[i - 1] != '>')
    {
      if (insert_node(&elem->node, my_strdup_e(str, i + 1),
		      (new = strndup(str, i)), REDIR_RIGHT) == NULL)
	return (NULL);
    }
  else
    if (insert_node(&elem->node, my_strdup_e(str, i + 1),
		    (new = strndup(str, i - 1)), DOUBLE_REDIR_RIGHT) == NULL)
      return (NULL);
  free(str);
  return (new);
}

char	*pars_redir_left_with_other(t_list_sh *elem, char *str, int i)
{
  char	*new;
  char	*tmp;
  int	j;

  j = 0;
  while (str[j] != '>' && str[j] != '|')
    j++;
  if ((new = strndup(str, i)) == NULL
      || (tmp = my_strdup_bt(str, i, (i + 1))) == NULL
      || (new = realloc(new, (strlen(new) + strlen(tmp) + 1))) == NULL
      || (new = strcat(new, tmp)) == NULL)
    return (NULL);
  free(tmp);
  if ((tmp = my_strdup_e(str, (j + 1))) == NULL
      || (new = realloc(new, (strlen(tmp) + strlen(new) + 1))) == NULL
      || (new = strcat(new, tmp)) == NULL)
    return (NULL);
  free(tmp);
  if (insert_node(&elem->node, my_strdup_bt(str, i + 1, j), new,
		  REDIR_LEFT) == NULL)
    return (NULL);
  return (new);
}

char	*pars_redir_left(t_list_sh *elem, char *str)
{
  char	*new;
  int   i;

  i = my_strlen(str) - 1;
  while (str[i] != '<')
    i--;
  if (str[i - 1] == '<')
    {
      if ((new = pars_double_redirection_left(elem, str, i)) == NULL)
	return (NULL);
    }
  else
    {
      if (check_prior(my_strdup_e(str, i + 1)) == 0)
	{
	  if (insert_node(&elem->node, my_strdup_e(str, i + 1),
			  (new = strndup(str, i)), REDIR_LEFT) == NULL)
	    return (NULL);
	}
      else
	if ((new = pars_redir_left_with_other(elem, str, i)) == NULL)
	  return (NULL);
    }
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
