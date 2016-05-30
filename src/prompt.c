/*
** prompt.c for prompt in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon May 30 16:49:29 2016 Poc
** Last update Mon May 30 18:19:49 2016 Poc
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
  char	*env_ptr;
  char	*new;
  char	localhost[_POSIX_HOST_NAME_MAX];

  printf("%d\n", _POSIX_HOST_NAME_MAX);
  if ((env_ptr = get_prompt_value(env)) == NULL)
    {
      if ((env_ptr = strdup("?> ")) == NULL)
	return (NULL);
      return (env_ptr);
    }
  if (gethostname(localhost, _POSIX_HOST_NAME_MAX) == -1)
    return (NULL);
  printf("%s\n", localhost);
  exit (1);
  return (env_ptr);
}
