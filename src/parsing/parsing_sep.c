/*
** parsing_sep.c for parsing_sep in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 13 15:22:08 2016 marel_m
** Last update Tue May 17 11:35:16 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"

char	*pars_pipe(t_list_sh *elem, char *str)
{
  int	i;
  char	*new;

  i = my_strlen(str) - 1;
  while (str[i] != '|')
    i--;
  insert_node(&elem->node, my_strdup_e(str, i + 1), strndup(str, i), PIPE);
  new = strndup(str, i);
  free(str);
  return (new);
}

char	*pars_redir_right(t_list_sh *elem, char *str)
{
  int	i;
  char	*new;

  i = my_strlen(str) - 1;
  while (str[i] != '>')
    i--;
  insert_node(&elem->node, my_strdup_e(str, i + 1), strndup(str, i),
	      REDIR_RIGHT);
  new = strndup(str, i);
  free(str);
  return (new);
}

char	*pars_redir_left(t_list_sh *elem, char *str)
{
  char	*new;
  int   i;

  i = my_strlen(str) - 1;
  while (str[i] != '<')
    i--;
  insert_node(&elem->node, my_strdup_e(str, i + 1), strndup(str, i),
	      REDIR_LEFT);
  new = strndup(str, i);
  free(str);
  return (new);
}

char	*pars_redir(t_list_sh *elem, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str)
    {
      if (str[i] == '>')
	{
	  str = pars_redir_right(elem, str);
	  return (0);
	}
      i++;
    }
  str = pars_redir_left(elem, str);
  return (str);
}

/* int	pars_double_redir_right(t_list_sh *elem, char *str, t_dir dir) */
/* { */
/*   return (0); */
/* } */

/* int	pars_double_redir_left(t_list_sh *elem, char *str, t_dir dir) */
/* { */
/*   return (0); */
/* } */
