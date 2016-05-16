/*
** 42rc_create_alias.c for create in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon May 16 13:22:30 2016 Poc
** Last update Mon May 16 17:04:59 2016 Poc
*/

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

static int     		push_alias_string_back(t_aliases *head, char *string)
{
  t_aliases		*alias;

  if ((alias = malloc(sizeof(t_aliases))) == NULL)
    return (1);
  while (head->next)
    head = head->next;
  head->next = alias;
  alias->alias = string;
  alias->next = NULL;
  return (0);
}

static char		*isolate_str(char *str)
{
  char			*cleaned_str;
  int			i;

  i = 0;
  if ((cleaned_str = my_index(str, '=')) == NULL)
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
}

int			create_alias(t_conf *conf, t_env **env, char *str)
{
  printf("Je cree un joyeux alias\n");
  printf("Create alias str = %s\n", str);
  if ((str = isolate_str(str)) == NULL)
    return (0);
  if (conf->head == NULL)
    {
      if (!(conf->head = create_alias_node()))
	return (1);
      conf->head->alias = str;
    }
  else
    if (!push_alias_string_back(conf->head, str))
      return (0);
}
