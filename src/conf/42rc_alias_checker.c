/*
** 42rc_alias_checker.c for check alias in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Wed May 18 12:37:44 2016 Poc
** Last update Sat Jun  4 21:43:30 2016 bougon_p
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

int	change_word(char **str, t_aliases *node, int pos, int end)
{
  char	*corrected_chain;
  int	i;

  i = strlen(*str);
  if ((corrected_chain =
       malloc(sizeof(char) * (strlen(*str) + strlen(node->alias) + 2))) == NULL)
     return (1);
  (*str)[pos] = 0;
  (*str)[end] = 0;
  strcpy(corrected_chain, *str);
  strcat(corrected_chain, node->alias);
  if (strlen(corrected_chain) != 0 &&
      corrected_chain[strlen(corrected_chain) - 1] != ' ')
    strcat(corrected_chain, " ");
  strcat(corrected_chain, (*str) + end + (end == i ? 0 : 1));
  free(*str);
  *str = corrected_chain;
  return (0);
}

int	jump_next_word(char *str, int i)
{
  if (i == 0)
    return (0);
  while (str && str[i] && str[i] != ' ')
    {
      i++;
    }
  if (str[i + 1])
    return (i + 1);
  else
    return (-1);
}

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
  if (ret == 0 && (str[i + 1] == 0 || str[i + 1] == ' '))
    return (0);
  else if (i >= 1 && str[i] == ' ')
    return (alias[i - 1] - str[i - 1]);
  else
    return (-1);
}

int	check_alias(t_aliases *head, char **str)
{
  int	i;
  int	n;
  char	*new;

  if (!(new = strdup(*str)))
    exit(1);
  n = 0;
  while (head)
    {
      i = n;
      while ((i = jump_next_word(*str, i)) != -1)
        {
          if (aliascmp(head->original, &(*str)[i]) == 0)
            {
              change_word(&new, head, i, strlen(head->original));
              n = i + strlen(head->original);
            }
          i++;
        }
      head = head->next;
    }
  if (*str)
    return (free(*str), *str = new, 0);
  return (0);
}
