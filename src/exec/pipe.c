/*
** pipe.c for pipe in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu May 26 13:16:31 2016 marel_m
** Last update Thu Jun  2 13:33:00 2016 Poc
*/

#include <string.h>
#include <unistd.h>
#include "42s.h"

int	execute_in_son(t_sh *sh)
{
  sh = sh;
  return (0);
}

int	pipes(t_sh *sh, t_node *node)
{
  int		chid;
  /* static int	pipe_count = 0; */

  sh->exec->type = node->type;
  /* printf("\nnode->args = %s\n", node->arg); */
  sh->exec->arg = my_str_to_word_tab(node->arg, ' ');
  sh->exec->exec = strdup(sh->exec->arg[0]);
  /* printf("\nnode->args = %s\n", node->arg); */
  check_good_path(sh);
  sh = sh;
  node = node;
  if ((chid = fork()) == -1)
    return (1);
  if (chid == 0)
    {
      if (execute_in_son(sh))
	return (1);
    }
  return (0);
}
