/*
** 42rc_create_alias.c for create in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon May 16 13:22:30 2016 Poc
** Last update Wed Jun  1 14:06:47 2016 Poc
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

static t_aliases	*create_alias_node()
{
  t_aliases		*new_node;

  if ((new_node = malloc(sizeof(t_aliases))) == NULL)
    return (NULL);
  new_node->alias = NULL;
  new_node->next = NULL;
  return (new_node);
}

static int     		push_alias_string_back(t_aliases *head,
					       char *first,
					       char *last)
{
  t_aliases		*alias;

  if ((head->alias == NULL))
    {
      head->original = first;
      head->alias = last;
    }
  else
  {
    if ((alias = create_alias_node()) == NULL)
      return (1);
    while (head->next)
      head = head->next;
    head->next = alias;
    alias->alias = first;
    alias->original = last;
    alias->next = NULL;
  }
  return (0);
}

static char		*isolate_str(char *str)
{
  char			*cleaned_str;
  int			i;

  i = 0;
  if (!(cleaned_str = strdup(str)))
    return (NULL);
  if (cleaned_str[0] == '\'' || cleaned_str[0] == '\"')
    {
      if ((str = strdup(cleaned_str + 1)) == NULL)
	return (NULL);
      while (str[i])
	{
	  if (str[i] == '\'' || str[i] == '\"')
	    str[i] = 0;
	  i++;
	}
    }
  else if ((str = strdup(cleaned_str)) == NULL)
    return (NULL);
  return (str);
}

static char		*get_first_alias_part(char *str)
{
  char			*new_chain;
  char			*tmp;
  int			i;

  i = 0;
  if ((new_chain = my_index(str, ' ')) == NULL)
    return (NULL);
  if (((tmp = my_index(str, '\'')) == NULL))
    tmp = my_index(str, '\"');
  if (tmp)
    {
      free(new_chain);
      new_chain = tmp;
    }
  while (new_chain[i] && new_chain[i] != '=' &&
	 new_chain[i] != '\'' && new_chain[i] != '\"')
    i++;
  new_chain[((i != 0 &&
  	      (str[i - 1] == '\'' || str[i - 1] == '\"')) ? i - 1 : i)] = 0;
  return (new_chain);
}

int			create_alias(t_conf *conf,
				     UNUSED char ***env,
				     char *str)
{
  char			*tmp;
  char			*first_part;
  char			*second_part;
  int			i;

  i = 0;
  if (!conf->head && (conf->head = create_alias_node()) == NULL)
    return (1);
  if ((tmp = strdup(str)) == NULL)
    return (1);
  while (tmp[i] && tmp[i] != '=')
    i++;
  tmp[i] = 0;
  if ((first_part = get_first_alias_part(tmp)) == NULL)
    return (0);
  if ((second_part = isolate_str(tmp + i + (str[i] == 0 ? 0 : 1))) == NULL)
    return (0);
  if (push_alias_string_back(conf->head, second_part, first_part))
    return (0);
  return (0);
}
