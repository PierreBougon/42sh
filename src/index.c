/*
** index.c for index in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon May 16 15:43:39 2016 Poc
** Last update Wed May 18 10:27:29 2016 Poc
*/

#include <string.h>
#include <unistd.h>

char	*my_index(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != c)
      i++;
  if (str[i] == 0)
    return (NULL);
  return (strdup(str + i + (str[i] == 0 ? 0 : 1)));
}