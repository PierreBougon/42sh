/*
** echo.c for echo in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 29 16:23:51 2016 bougon_p
** Last update Mon May 30 16:29:02 2016 bougon_p
*/

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

void	debug_opt(t_echo *opt)
{
  printf("=== OPT ===\n");
  if (opt->opt_e)
    printf("e = True\n");
  else
    printf("e = False\n");
  if (opt->opt_E)
    printf("E = True\n");
  else
    printf("E = False\n");
  if (opt->opt_n)
    printf("n = True\n");
  else
    printf("n = False\n");
  if (opt->opt_vers)
    printf("vers = True\n");
  else
    printf("vers = False\n");
  if (opt->opt_help)
    printf("help = True\n");
  else
    printf("help = False\n");
  printf("===     ===\n");
}

int		my_echo(t_sh *sh)
{
  t_echo	opt;

  init_opt(&opt);
  parse_opt(&opt, sh);
  /* debug_opt(&opt); */
  if (opt.opt_vers)
    {
      printf("%s\n", ECHO_VERSION);
      return (0);
    }
  else if (opt.opt_help)
    {
      print_help();
      return (0);
    }
  else
    {
      print_echo(&opt, sh->exec->arg);
    }
  return (0);
}
