/*
** copy_arg_sep_node.c for copy_arg_sep_node in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Mon May 30 21:15:46 2016 marel_m
** Last update Mon May 30 21:17:00 2016 marel_m
*/

#include <string.h>
#include <stdlib.h>

int	arg_pipe(char **arg)
{
  if (((*arg) = strdup("|")) == NULL)
    return (1);
  return (0);
}

int	arg_redir_r(char **arg)
{
  if (((*arg) = strdup(">")) == NULL)
    return (1);
  return (0);
}

int	arg_redir_l(char **arg)
{
  if (((*arg) = strdup("<")) == NULL)
    return (1);
  return (0);
}

int	arg_redir_rr(char **arg)
{
  if (((*arg) = strdup(">>")) == NULL)
    return (1);
  return (0);
}

int	arg_redir_ll(char **arg)
{
  if (((*arg) = strdup("<<")) == NULL)
    return (1);
  return (0);
}
