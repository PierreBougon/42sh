/*
** auto_completion_utility3.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Tue May 31 13:56:59 2016 Mathieu Sauvau
** Last update Tue May 31 13:58:41 2016 Mathieu Sauvau
*/

#include <string.h>
#include "42s.h"

int		find_in_env_path(char **env_path, char *elem, char **res)
{
  int		i;
  int		n;

  i = -1;
  n = 0;
  while (env_path[++i])
    n += find_in_(env_path[i], elem, res, 1);
  return (n);
}

int		show_bin(t_autoc *autoc)
{
  if (autoc->show &&
       (autoc->i_elem == 1 ||
	strcmp(autoc->tab_str[autoc->i_elem - 2], "|") == 0 ||
	strcmp(autoc->tab_str[autoc->i_elem - 2], "||") == 0 ||
	strcmp(autoc->tab_str[autoc->i_elem - 2], "&&") == 0 ||
	strcmp(autoc->tab_str[autoc->i_elem - 2], ";") == 0))
    return (1);
  return (0);
}
