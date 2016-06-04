/*
** echo.c for echo in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 29 16:23:51 2016 bougon_p
** Last update Sat Jun  4 16:57:32 2016 bougon_p
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

int	init_opt(t_echo *opt)
{
  opt->opt_e = false;
  opt->opt_n = false;
  opt->opt_E = true;
  opt->opt_help = false;
  opt->opt_vers = false;
  opt->nb_opt = 3;
  if (!(opt->opt_tab = malloc(sizeof(char) * (opt->nb_opt + 1))))
    return (1);
  opt->opt_tab[0] = 'e';
  opt->opt_tab[1] = 'n';
  opt->opt_tab[2] = 'E';
  opt->opt_tab[3] = 0;
  return (0);
}

int		my_echo(t_sh *sh)
{
  t_echo	opt;

  opt.fd = sh->exec->fd[0][1];
  if (init_opt(&opt) == 1)
    return (1);
  parse_opt(&opt, sh);
  if (opt.opt_e)
    opt.opt_E = false;
  if (opt.opt_vers)
    dprintf(opt.fd, "%s\n", ECHO_VERSION);
  else if (opt.opt_help)
    print_help();
  else
    print_echo(&opt, &sh->exec->arg[1]);
  free(opt.opt_tab);
  return (0);
}
