/*
** prompt.c for prompt in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon May 30 16:49:29 2016 Poc
** Last update Mon May 30 18:40:54 2016 Poc
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <42s.h>

char	*get_prompt_value(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (strncmp(env[i], "PS1=", 4) == 0)
	return (my_index(env[i], '='));
      i++;
    }
  return (NULL);
}

char	*prompt_from_env(char **env)
{
  char	*value;
  char	*new;
  char	localhost[_POSIX_HOST_NAME_MAX];

  if ((value = get_prompt_value(env)) == NULL)
    {
      if ((value = strdup("?> ")) == NULL)
	return (NULL);
      return (value);
    }
  if (gethostname(localhost, _POSIX_HOST_NAME_MAX) == -1)
      return (NULL);
  if ((new = malloc((strlen(localhost) + strlen(value) + 4) *
		    sizeof(char))) == NULL)
    return (NULL);
  strcpy(new, value);
  strcat(new, "@");
  strcat(new, localhost);
  strcat(new, " >");
  free(value);
  return (new);
}
