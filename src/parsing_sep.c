/*
** parsing_sep.c for parsing_sep in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri May 13 15:22:08 2016 marel_m
** Last update Sat May 14 16:39:47 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include "42s.h"

int	pars_semicolon(t_sh *sh, char *str)
{
  int	i;

  insert_node(&sh->node, NULL, SEMICOLON, NULL);
  i = 0;
  while (str[i] != ';')
    i++;
  insert_node(&sh->node, strndup(str, i), NULL, LEFT);
  parsing(sh, strndup(str, i));
  insert_node(&sh->node, my_strdup_e(str, ++i), NULL, RIGHT);
  parsing(sh, my_strdup_e(str, i));
  return (0);
}

int	pars_double_pipe(t_sh *sh, char *str)
{
  int	i;

  insert_node(&sh->node, NULL, DOUBLE_PIPE, NULL);
  i = 0;
  while (str[i] != '|' && str[i + 1] != '|')
    i++;
  insert_node(&sh->node, strndup(str, i), NULL, LEFT);
  parsing(sh, strndup(str, i));
  insert_node(&sh->node, my_strdup_e(str, ++i), NULL, RIGHT);
  parsing(sh, my_strdup_e(str, i));
  return (0);
}

int	pars_double_and(t_sh *sh, char *str)
{
  int	i;

  insert_node(&sh->node, NULL, DOUBLE_AND, NULL);
  i = 0;
  while (str[i] != '&' && str[i + 1] != '&')
    i++;
  insert_node(&sh->node, strndup(str, i), NULL, LEFT);
  insert_node(&sh->node, my_strdup_e(str, ++i), NULL, RIGHT);
  return (0);
}

int	pars_double(t_sh *sh, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str)
    {
      if (str[i] == '|' && str[i + 1] == '|')
	{
	  pars_double_pipe(sh, str);
	  return (0);
	}
      i++;
    }
  pars_double_and(sh, str);
  return (0);
}

int	pars_pipe(t_sh *sh, char *str)
{
  int	i;

  insert_node(&sh->node, NULL, PIPE, NULL);
  i = 0;
  while (str[i] != '|')
    i++;
  insert_node(&sh->node, strndup(str, i), NULL, LEFT);
  insert_node(&sh->node, my_strdup_e(str, ++i), NULL, RIGHT);
  return (0);
}

int	pars_redir_right(t_sh *sh, char *str)
{
  int	i;

  insert_node(&sh->node, NULL, REDIR_RIGHT, NULL);
  i = 0;
  while (str[i] != '>')
    i++;
  insert_node(&sh->node, strndup(str, i), NULL, LEFT);
  insert_node(&sh->node, my_strdup_e(str, ++i), NULL, RIGHT);
  return (0);
}

int	pars_redir_left(t_sh *sh, char *str)
{
  int   i;

  insert_node(&sh->node, NULL, REDIR_LEFT, NULL);
  i = 0;
  while (str[i] != '>')
    i++;
  insert_node(&sh->node, strndup(str, i), NULL, LEFT);
  insert_node(&sh->node, my_strdup_e(str, ++i), NULL, RIGHT);
  return (0);
}

int	pars_redir(t_sh *sh, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str)
    {
      if (str[i] == '>')
	{
	  pars_redir_right(sh, str);
	  return (0);
	}
      i++;
    }
  pars_redir_left(sh, str);
  return (0);
}

/* int	pars_double_redir_right(t_sh *sh, char *str, t_dir dir) */
/* { */
/*   return (0); */
/* } */

/* int	pars_double_redir_left(t_sh *sh, char *str, t_dir dir) */
/* { */
/*   return (0); */
/* } */
