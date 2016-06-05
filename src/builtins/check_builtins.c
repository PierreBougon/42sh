/*
** check_builtins.c for check_builtins in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 16:28:38 2016 marel_m
** Last update Sun Jun  5 11:56:06 2016 Poc
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "fptrtab.h"
#include "42s.h"

t_blt	*init_tab_builtins()
{
  t_blt	*tab;

  if ((tab = malloc(sizeof(t_blt) * MAX_BLT)) == NULL)
    return (NULL);
  tab[SETENV].blt = "setenv";
  tab[SETENV].ft_blt = &my_setenv;
  tab[UNSETENV].blt = "unsetenv";
  tab[UNSETENV].ft_blt = &my_unsetenv;
  tab[ENV].blt = "env";
  tab[ENV].ft_blt = &my_env;
  tab[CD].blt = "cd";
  tab[CD].ft_blt = &my_cd;
  tab[EXIT].blt = "exit";
  tab[EXIT].ft_blt = &my_exit;
  tab[ECHO].blt = "echo";
  tab[ECHO].ft_blt = &my_echo;
  tab[HISTORY].blt = "history";
  tab[HISTORY].ft_blt = &blt_hist;
  tab[TETRIS].blt = "tetris";
  tab[TETRIS].ft_blt = &tetris;
  tab[F_FG].blt = "fg";
  tab[F_FG].ft_blt = &push_job_foreground;
  tab[F_BG].blt = "bg";
  tab[F_BG].ft_blt = &print_list;
  return (tab);
}

int	determine_fd(t_sh *sh)
{
  if (sh->is_pipe && sh->actual_pipe[sh->actual_pipe])
    {
      sh->exec->fd[0][1] = sh->exec->fd[sh->actual_pipe][1];
      close(sh->exec->fd[sh->actual_pipe][0]);
    }
  return (0);
}

int	check_builtin(t_sh *sh)
{
  t_blt	*fptrtab;
  int	i;
  int	ret;

  i = -1;
  if ((fptrtab = init_tab_builtins()) == NULL)
    return (1);
  while (++i < MAX_BLT)
    if (strlen(sh->exec->arg[0]) == strlen(fptrtab[i].blt)
	&& strncmp(sh->exec->arg[0], fptrtab[i].blt, strlen(fptrtab[i].blt)) == 0)
      {
	determine_fd(sh);
	ret = fptrtab[i].ft_blt(sh);
	close_all(sh->exec->fd);
	wait_func(sh->list, sh);
	return (free(fptrtab), ret);
      }
  free(fptrtab);
  return (-3);
}
