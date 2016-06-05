/*
** aliascmp.c for cmp in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Jun  5 15:05:52 2016 bougon_p
** Last update Sun Jun  5 15:08:11 2016 bougon_p
*/

#include <string.h>
#include "42s.h"

int	aliascmp(char *alias, char *str)
{
  int	size;
  int	i;
  int	ret;

  size = strlen(alias);
  i = 0;
  while (alias && str && alias[i]
         && str[i] && alias[i] == str[i]
         && i < size)
    i++;
  ret = alias[i] - str[i];
  if (ret == 0)
    return (0);
  else if (i >= 1 && str[i] == ' ' && alias[i] == 0)
    return (alias[i - 1] - str[i - 1]);
  else
    return (-1);
}
