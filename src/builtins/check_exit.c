/*
** check_exit.c for check_exit
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 15:44:57 2016 marel_m
** Last update Wed Jun  1 15:14:35 2016 bougon_p
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "42s.h"

void		free_aliases(t_conf *conf)
{
  t_aliases	*tmp;

  while (conf->head)
    {
      free(conf->head->alias);
      free(conf->head->original);
      tmp = conf->head;
      conf->head = conf->head->next;
      free(tmp);
    }
  free(conf->head);
}

int		my_exit(t_sh *sh)
{
  if (sh->exec->arg[1] != NULL)
    sh->exit = my_getnbr(sh->exec->arg[1]);
  else
    sh->exit = 0;
  free_env(sh->env);
  free_aliases(&sh->conf);
  exit(sh->exit);
}

void		do_shortcut_exit(t_sh *sh)
{
  if (!(sh->exec = malloc(sizeof(t_exec))))
    exit(1);
  if (!(sh->exec->arg = malloc(sizeof(char *) * 2)))
    exit(1);
  sh->exec->arg[1] = NULL;
  printf("exit\n");
  my_exit(sh);
}

bool	check_exit(char *buf)
{
  char	exit[2];

  exit[0] = 4;
  exit[1] = 0;
  if (strcmp(buf, exit) == 0)
    return (true);
  return (false);
}
