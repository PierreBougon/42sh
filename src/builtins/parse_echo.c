/*
** parse_echo.c for parse in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 29 18:38:35 2016 bougon_p
** Last update Sun May 29 18:39:16 2016 bougon_p
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

bool	opt_exist(char *str, t_echo *opt)
{
  int	i;

  i = -1;
  if ((version(str)) || (help(str)))
    return (true);
  while (str[++i])
    {
      if (str[i] != opt->opt_tab[0]
	  && str[i] != opt->opt_tab[1]
	  && str[i] != opt->opt_tab[2])
	return (false);
    }
  return (true);
}

void	set_opt(t_echo *opt, char op)
{
  if (op == opt->opt_tab[0])
    opt->opt_e = true;
  else if (op == opt->opt_tab[1])
    opt->opt_n = true;
  else if (op == opt->opt_tab[2])
    opt->opt_E = true;
}

bool	check_opt(char *str, t_echo *opt)
{
  int	i;

  i = -1;
  if (!opt_exist(str, opt))
    return (false);
  if (version(str))
    {
      opt->opt_vers = true;
      return (true);
    }
  else if (help(str))
    {
      opt->opt_help = true;
      return (true);
    }
  while (str[++i])
    {
      set_opt(opt, str[i]);
    }
  return (true);
}

void	parse_opt(t_echo *opt, t_sh *sh)
{
  char	**args;
  int	i;

  args = sh->exec->arg;
  i = 0;
  while (args[++i])
    {
      printf("%s\n", args[i]);
      if (args[i][0] == '-')
	check_opt(&args[i][1], opt);
    }
}
