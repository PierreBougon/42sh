/*
** verif_good_synthax.c for verif_good_synthax in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue May 31 11:03:03 2016 marel_m
** Last update Sat Jun  4 16:23:51 2016 marel_m
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "42s.h"

int	verif_elem_redirect_first(char *tmp)
{
  int	i;

  if (tmp[0] == '>')
    {
      i = 0;
      while (tmp[i] == '>')
	i++;
      if (i > 2)
	return (write(2, "Missing name for redirect.\n", 27), 1);
      while (tmp && tmp[i] != '\0')
	{
	  if (tmp[i] == '"')
	    while (tmp[++i] != '"' && tmp[i] != '\0');
	  else if (tmp[i] == '|')
	    return (write(2, "Ambiguous output redirect.\n", 27), 1);
	  i++;
	}
    }
  return (0);
}

int	elem_good_position(char *tmp)
{
  int	i;

  if (tmp == NULL)
    return (1);
  if (tmp[0] == '|' || tmp[strlen(tmp) - 1] == '|')
    return (write(2, "Invalid null command.\n", 22), 1);
  if (tmp[strlen(tmp) - 1] == '>' || tmp[strlen(tmp) - 1] == '<')
    return (write(2, "Missing name for redirect.\n", 27), 1);
  i = 0;
  while (tmp && tmp[i] != '\0')
    {
      if (tmp && tmp[i] != '\0' && tmp[i] == '"')
	while (tmp && tmp[++i] != '\0' && tmp[i] != '"');
      else if (tmp && tmp[i] != '\0' && tmp[i + 1] != '\0' && tmp[i + 2] != '\0'
	  && ((tmp[i] == '|' && tmp[i + 1] == '|' && tmp[i + 2] == '|')
	      || (tmp[i] == '&' && tmp[i + 1] == '&' && tmp[i + 2] == '&')))
	return (write(2, "Invalid null command.\n", 22), 1);
      else if (tmp && tmp[i] != '\0' && tmp[i + 1] != '\0' && tmp[i + 2] != '\0'
	       && ((tmp[i] == '>' && tmp[i + 1] == '>' && tmp[i + 2] == '>') ||
		   (tmp[i] == '<' && tmp[i + 1] == '<' && tmp[i + 2] == '<') ||
		   (tmp[i] == '>' && tmp[i + 1] == '<') ||
		   (tmp[i] == '<' && tmp[i + 1] == '>')))
	return (write(2, "Missing name for redirect.\n", 27), 1);
      if (tmp && tmp[i] != '\0')
	i++;
    }
  if (verif_elem_redirect_first(tmp))
    return (1);
  return (0);
}

int	check_synthax(char *str, int st, int end)
{
  int	ret;
  char	*tmp;

  if ((tmp = my_strdup_bt(str, st, end)) == NULL)
    exit(1);
  if (strlen(tmp) == 0)
    return (free(tmp), 0);
  if ((ret = elem_good_position(tmp)) != 0)
    return (free(tmp), ret);
  if (tmp[0] == '>' || tmp[0] == '<')
    {
      if ((str = rewrite_str(tmp)) == NULL)
	exit(1);
      if (strcmp(str, tmp) == 0)
	return (write(2, "Invalid null command.\n", 22), 1);
    }
  free(tmp);
  return (0);
}

int	if_is_a_separator(char *str, int *i, int *j)
{
  if (str[(*i)] == ';')
    {
      if (check_synthax(str, *j, *i))
	return (1);
      while (str[(*i)] != '\0' && str[(*i)] == ';')
	(*i)++;
      if (str && str[(*i)] != '\0')
	(*i)++;
      return (*j = *i, 0);
    }
  else if (str[(*i)] == '&' && str[(*i) + 1] == '&')
    {
      if (check_synthax(str, *j, *i))
	return (1);
      if (str && str[(*i)] != '\0' && str[(*i) + 1] != '\0')
	(*i) += 2;
      if (str[(*i)] == '&')
	return (write(2, "Invalid null command.\n", 22), 1);
      *j = *i;
      return (0);
    }
  else if (str[(*i)] == '|' && str[(*i) + 1] == '|')
    {
      if (check_synthax(str, *j, *i))
	return (1);
      if (str && str[(*i)] != '\0' && str[(*i) + 1] != '\0')
	(*i) += 2;
      return (*j = *i, 0);
    }
  return (-1);
}

int    verif_good_synthax_string(t_sh *sh, char *str)
{
  int	i;
  int	j;
  int	ret;

  i = 0;
  j = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '"')
	while (str && str[++i] != '\0' && str[i] != '"');
      else if ((ret = if_is_a_separator(str, &i, &j)) == -1)
	{
	  if (str && str[i] != '\0')
	    i++;
	}
      else if (ret == 1)
	{
	  sh->exit = 1;
	  return (1);
	}
    }
  if (check_synthax(str, j, i))
    {
      sh->exit = 1;
      return (1);
    }
  return (0);
}
