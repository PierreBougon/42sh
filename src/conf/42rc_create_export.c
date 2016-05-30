/*
** 42rc_create_export.c for lol in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon May 16 13:46:22 2016 Poc
** Last update Mon May 30 22:33:07 2016 Poc
*/

#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include "42s.h"

int	arrlen(char **array)
{
  int	i;

  i = 0;
  while (array[i])
    i++;
  return (i);
}

int	cpy_new_env(char ***env, char *nocpy)
{
  char	**new_env;
  int	i;
  int	j;
  int	bonus;

  bonus = 0;
  j = 0;
  i = 0;
  if ((new_env = malloc(sizeof(void *) * (arrlen(*env) + 2))) == NULL)
    return (-1);
  while (i < arrlen(*env) - bonus)
    {
      if (strncmp(nocpy, (*env)[i], strlen(nocpy)) == 0)
	{
	  j++;
	  bonus++;
	}
      new_env[i++] = (*env)[j++];
    }
  new_env[i] = NULL;
  free(*env);
  *env = new_env;
  return (i - bonus);
}

void	create_export_new_chain(char *new_one, char *index, char *value)
{
  strcpy(new_one, index);
  strcat(new_one, "=");
  strcat(new_one, value);
  free(index);
  free(value);
}

int	create_export(UNUSED t_conf *conf, char ***env, char *str)
{
  char	*index;
  char	*value;
  char	*new_one;
  int	index_env;
  int	i;

  i = 0;
  if ((index = my_index(str, ' ')) == NULL)
    return (1);
  if ((value = my_index(str, '=')) == NULL)
    return (0);
  while (index[i] && index[i] != '=')
    i++;
  index[i] = 0;
  if ((index_env = cpy_new_env(env, index)) == -1 ||
      (new_one = malloc(sizeof(char) *
			(strlen(index) + strlen(value) + 2))) == NULL)
    return (1);
  create_export_new_chain(new_one, index, value);
  (*env)[index_env] = new_one;
  (*env)[index_env + 1] = NULL;
  return (0);
}
