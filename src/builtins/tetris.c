/*
** tetris.c for tetris in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Jun  2 15:38:27 2016 bougon_p
** Last update Thu Jun  2 16:03:50 2016 bougon_p
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "42s.h"

int	tetris(t_sh *sh)
{
  pid_t	pid;
  int	status;
  char	*arg[2];

  arg[0] = "assets/tetris";
  arg[1] = NULL;
  if ((pid = fork()) == -1)
    exit(1);
  if (pid == 0)
    {
      if (execve("assets/tetris", arg, sh->env->env) == -1)
	exit(1);
    }
  else if (pid != 0)
    {
      if (wait(&status) == -1)
	return (1);
    }
  return (0);
}
