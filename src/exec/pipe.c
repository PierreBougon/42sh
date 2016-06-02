/*
** pipe.c for pipe in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Thu May 26 13:16:31 2016 marel_m
** Last update Thu Jun  2 11:05:06 2016 Poc
*/

#include <unistd.h>
#include "42s.h"

int	execute_in_son(t_sh *sh)
{
  sh = sh;
  return (0);
}

int	pipes(t_sh *sh, t_node *node)
{
  int	chid;

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
