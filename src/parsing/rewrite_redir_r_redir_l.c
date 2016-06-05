/*
** rewrite_redir_r_redir_l.c for redir_r_redir_l_rewrite in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sun Jun  5 10:42:10 2016 marel_m
** Last update Sun Jun  5 11:00:26 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>
#include "42s.h"

char	*change_str_redir_r_redir_l(char *str)
{
  int	i;
  int	j;
  char	*tmp;
  char	*tmp2;
  char	*new;

  i = 0;
  while (str[i] != '>')
    i++;
  if ((new = strndup(str, i)) == NULL)
    return (NULL);
  j = strlen(str) - 1;
  while (str[j] != '<')
    j--;
  if ((tmp = my_strdup_bt(str, j, strlen(str))) == NULL
      || (tmp2 = my_strdup_bt(str, i, j)) == NULL
      || (new = realloc(new, strlen(new) + strlen(tmp) + strlen(tmp2))) == NULL)
    return (NULL);
  new = strcat(new, tmp);
  new = strcat(new, tmp2);
  my_free((void **)&str);
  my_free((void **)&tmp);
  my_free((void **)&tmp2);
  return (new);
}

char	*rewrite_redir_r_redir_l(char *str)
{
  int	i;
  int	redir_r;

  i = 0;
  redir_r = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '>')
	redir_r = 1;
      else if (str[i] == '<' && redir_r == 1)
	return (change_str_redir_r_redir_l(str));
      i++;
    }
  return (str);
}
