/*
** tetris.c for tetris in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Jun  2 15:38:27 2016 bougon_p
** Last update Sun Jun  5 14:16:03 2016 bougon_p
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "42s.h"

char	*add_path_tetris(t_sh *sh)
{
  char	*buf;

  buf = NULL;
  if (!(buf = strdup(sh->cwd)) ||
      !(buf = realloc(buf, strlen(buf) + strlen("/assets") + 1)))
    exit(1);
  strcat(buf, "/assets");
  return (buf);
}

char	*concat_bin(char *str)
{
  char	*bin;

  if (!(bin = strdup(str)))
    exit(1);
  if (!(bin = realloc(bin, strlen(bin) + strlen("/tetris") + 1)))
    exit(1);
  bin = strcat(bin, "/tetris");
  return (bin);
}

int	tetris(t_sh *sh)
{
  pid_t	pid;
  int	status;
  char	*arg[3];

  arg[1] = add_path_tetris(sh);
  arg[0] = concat_bin(arg[1]);
  arg[2] = NULL;
  if ((pid = fork()) == -1)
    exit(1);
  if (pid == 0)
    {
      if (execve(arg[0], arg, sh->env->env) == -1)
	exit(1);
    }
  else if (pid != 0)
    {
      if (wait(&status) == -1)
	return (1);
    }
  return (0);
}
