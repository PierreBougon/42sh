/*
** parsing.c for parsing in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 11 16:02:55 2016 marel_m
** Last update Sun Jun  5 14:11:52 2016 marel_m
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "42s.h"

int	check_prior(char *str)
{
  int	i;
  int	prior;
  int	quote;

  i = 0;
  prior = 0;
  quote = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '"')
	quote++;
      if (quote % 2 == 0 && str[i] == '|' && prior < 1)
	prior = 1;
      else if (quote % 2 == 0 && (str[i] == '>' || str[i] == '<'))
	prior = 2;
      i++;
    }
  return (prior);
}

int		pars_tree(t_list_sh *elem, char *str)
{
  int		prior;
  int		quote;

  if (str == NULL)
    return (1);
  prior = check_prior(str);
  elem->nb++;
  if (prior == 0)
    return (my_free((void **)&str), 0);
  else if (prior == 1)
    {
      quote = check_quote(str, '|', '|');
      if ((str = pars_pipe(elem, str, quote)) == NULL)
	return (1);
    }
  else if (prior == 2)
    {
      quote = check_quote(str, '<', '>');
      if ((str = pars_redir(elem, str, quote)) == NULL)
	return (1);
    }
  if (check_prior(str) != 0)
    if (pars_tree(elem, str))
      return (1);
  my_free((void **)&str);
  return (0);
}

int		stock_elem(t_sh *sh, char *str, int st, int end)
{
  t_list_sh	*elem;

  if ((elem = add_list_after(sh)) == NULL
      || (st != end && ((elem->arg = my_strdup_bt(str, st, end)) == NULL))
      || (st == end && ((elem->arg = strdup(str)) == NULL))
      || (elem->arg = rewrite_redir_r_redir_l(elem->arg)) == NULL)
    return (1);
  elem->node = NULL;
  elem->nb = 1;
  if (elem->arg[0] == '>' || elem->arg[0] == '<')
    if ((elem->arg = rewrite_str(elem->arg)) == NULL)
      exit(1);
  if (check_prior(elem->arg) == 0)
    {
      if (insert_node(&elem->node, elem->arg, elem->arg, NO_ONE) == NULL)
	return (1);
      return (0);
    }
  if (pars_tree(elem, elem->arg))
    return (1);
  return (0);
}

int	which_separator(t_sh *sh, char *str, int *i, int *j)
{
  if (str[(*i)] == ';')
    {
      if (stock_elem(sh, str, *j, *i))
	return (1);
      sh->root->prev->type = SEMICOLON;
      while (str[(*i)] == ';' || str[(*i)] == '&')
	(*i)++;
      return (*j = *i, 0);
    }
  else if (str[(*i)] == '&' && str[(*i) + 1] == '&')
    {
      if (stock_elem(sh, str, *j, *i))
	return (1);
      sh->root->prev->type = DOUBLE_AND;
      return (*i += 2, *j = *i, 0);
    }
  else if (str[(*i)] == '|' && str[(*i) + 1] == '|')
    {
      if (stock_elem(sh, str, *j, *i))
	return (1);
      sh->root->prev->type = DOUBLE_PIPE;
      return (*i += 2, *j = *i, 0);
    }
  return (-1);
}

int	parsing(t_sh *sh, char *str)
{
  int	i;
  int	j;
  int	ret;

  if (str == NULL)
    return (1);
  if (create_list(sh))
    return (1);
  i = 0;
  j = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '"')
	while (str[++i] != '\0' && str[i] != '"');
      else if ((ret = which_separator(sh, str, &i, &j)) == -1)
	i++;
      else if (ret == 1)
	return (1);
    }
  if (j != i)
    if (stock_elem(sh, str, j, i))
      return (1);
  sh->root->prev->type = 0;
  return (0);
}
