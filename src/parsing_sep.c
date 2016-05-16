/*
** parsing_sep.c for parsing_sep in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 13 15:22:08 2016 marel_m
** Last update Mon May 16 19:06:03 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"

int	pars_pipe(t_list_sh *elem, char *str)
{
  int	i;
  char	*new;

  i = 0;
  while (str[i] != '|')
    i++;
  insert_node(&elem->node, strndup(str, i), my_strdup_e(str, (i + 1)), PIPE);
  new = my_strdup_e(str, (i + 1));
  free(str);
  return (new);
}

int	pars_redir_right(t_list_sh *elem, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '>')
    i++;
  insert_node(&elem->node, strndup(str, i), my_strdup_e(str, (i + 1)), REDIR_RIGHT);
  return (0);
}

int	pars_redir_left(t_list_sh *elem, char *str)
{
  int   i;

  i = 0;
  while (str[i] != '<')
    i++;
  insert_node(&elem->node, strndup(str, i), my_strdup_e(str, (i + 1)), REDIR_LEFT);
  return (0);
}

int	pars_redir(t_list_sh *elem, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str)
    {
      if (str[i] == '>')
	{
	  pars_redir_right(elem, str);
	  return (0);
	}
      i++;
    }
  pars_redir_left(elem, str);
  return (0);
}

/* int	pars_double_redir_right(t_list_sh *elem, char *str, t_dir dir) */
/* { */
/*   return (0); */
/* } */

/* int	pars_double_redir_left(t_list_sh *elem, char *str, t_dir dir) */
/* { */
/*   return (0); */
/* } */
