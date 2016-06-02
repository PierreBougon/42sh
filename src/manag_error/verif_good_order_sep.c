/*
** verif_good_order_sep.c for verif_good_order_sep in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue May 31 22:23:41 2016 marel_m
** Last update Fri Jun  3 00:02:26 2016 marel_m
*/

#include <unistd.h>
#include <stdlib.h>
#include "42s.h"

int	loop_order_else(int *redir_r, int *pipe, int *i, char *str)
{
  if (str[*i] == '"')
    while (str[++(*i)] != '"' && str[*i] != '\0');
  else if (str[*i] == '|')
    {
      if (*redir_r != 0)
	return (write(2, "Ambiguous output redirect.\n", 27), 1);
      (*pipe)++;
    }
  else if (str[*i] == '>')
    {
      if (*redir_r != 0)
	return (write(2, "Ambiguous output redirect.\n", 27), 1);
      (*redir_r)++;
      if (str[(*i) + 1] != '\0' && str[(*i) + 1] == '>')
	(*i)++;
    }
  else
    return (-1);
  return (0);
}

int	loop_order(char *str, int redir_r, int redir_l, int pipe)
{
  int	i;
  int	ret;

  i = -1;
  while (str && str[++i] != '\0')
    {
      if ((ret = loop_order_else(&redir_r, &pipe, &i, str)) == 1)
	return (1);
      else if (ret == -1)
	if (str[i] == '<')
	  {
	    if (pipe != 0)
	      return (write(2, "Ambiguous input redirect.\n", 26), 1);
	    redir_l++;
	    if (str[i + 1] != '\0' && str[i + 1] == '<')
	      i++;
	  }
    }
  return (0);
}

int	check_order(char *str, int st, int end)
{
  char	*tmp;
  int	redir_r;
  int	redir_l;
  int	pipe;

  if ((tmp = my_strdup_bt(str, st, end)) == NULL)
    exit(1);
  redir_r = 0;
  redir_l = 0;
  pipe = 0;
  if (loop_order(tmp, redir_r, redir_l, pipe))
    return (free(tmp), 1);
  free(tmp);
  return (0);
}

int	if_is_a_sep(char *str, int *i, int *j)
{
  if (str[(*i)] == ';')
    {
      if (check_order(str, *j, *i))
	return (1);
      (*i)++;
      *j = *i;
      return (0);
    }
  else if (str[(*i)] == '&' && str[(*i) + 1] == '&')
    {
      if (check_order(str, *j, *i))
	return (1);
      *i += 2;
      *j = *i;
      return (0);
    }
  else if (str[(*i)] == '|' && str[(*i) + 1] == '|')
    {
      if (check_order(str, *j, *i))
	return (1);
      *i += 2;
      *j = *i;
      return (0);
    }
  return (-1);
}

int	verif_good_order_sep(t_sh *sh, char *str)
{
  int	i;
  int	j;
  int	ret;

  i = 0;
  j = 0;
  while (str && str[i] != '\0')
    {
      if ((ret = if_is_a_sep(str, &i, &j)) == -1)
	i++;
      else if (ret == 1)
	{
	  sh->exit = 1;
	  return (1);
	}
    }
  if (check_order(str, j, i))
    {
      sh->exit = 1;
      return (1);
    }
  return (0);
}
