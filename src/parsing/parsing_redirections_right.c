/*
** parsing_redirections_right.c for parsing_redirections_right in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Jun  3 00:34:52 2016 marel_m
** Last update Fri Jun  3 01:10:39 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>
#include "42s.h"

char	*cut_redir_r(char *str, int i, int j)
{
  char	*tmp;
  char	*tmp2;
  char	*new;

  if ((tmp = strndup(str, i)) == NULL)
    return (NULL);
  if (str[j] != '\0')
    {
      if ((new = malloc(sizeof(char)
			* (strlen(tmp) + strlen(str) + j + 1))) == NULL
	  || (tmp2 = my_strdup_bt(str, j, strlen(str))) == NULL)
	return (NULL);
      new = strcpy(new, tmp);
      new = strcat(new, tmp2);
      free(tmp2);
    }
  else
    if ((new = strdup(tmp)) == NULL)
      return (NULL);
  free(tmp);
  return (new);
}

char	*cut_redir_rr(char *str, int i, int j)
{
  char	*new;
  char	*tmp;
  char	*tmp2;

  if ((tmp = strndup(str, i - 1)) == NULL)
    return (NULL);
  if (str[j] != '\0')
    {
      if ((new = malloc(sizeof(char)
			* (strlen(tmp) + strlen(str) + j + 1))) == NULL
	  || (tmp2 = my_strdup_bt(str, j, strlen(str))) == NULL)
	return (NULL);
      new = strcpy(new, tmp);
      new = strcat(new, tmp2);
      free(tmp2);
    }
  else
    if ((new = strdup(tmp)) == NULL)
      return (NULL);
  free(tmp);
  return (new);
}

int	init_pars_redir_r(char *str, int quote, int *i, int *j)
{
  int	nb;

  nb = 0;
  while (nb < quote)
    {
      if (str[*i] == '"')
	nb++;
      (*i)--;
    }
  while (str[*i] != '>')
    (*i)--;
  if (*i == 0)
    return (1);
  *j = *i;
  while (str && str[*j] != '\0' && str[*j] != ' ')
    (*j)++;
  return (0);
}

char	*pars_redir_right(t_list_sh *elem, char *str, int quote)
{
  int	i;
  char	*new;
  int	j;

  i = my_strlen(str) - 1;
  if (quote != 0)
    quote = pos_double_quote(str, '>');
  if (init_pars_redir_r(str, quote, &i, &j))
    return (NULL);
  if (str[i - 1] != '>')
    {
      if ((new = cut_redir_r(str, i, j)) == NULL
	  || insert_node(&elem->node, my_strdup_bt(str, i + 1, j),
			 new, REDIR_RIGHT) == NULL)
	return (NULL);
    }
  else
    {
      if ((new = cut_redir_rr(str, i, j)) == NULL
	  || insert_node(&elem->node, my_strdup_bt(str, i + 1, j),
			 new, DOUBLE_REDIR_RIGHT) == NULL)
	return (NULL);
    }
  free(str);
  return (new);
}
