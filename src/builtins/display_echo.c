/*
** display_echo.c for display in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 29 18:40:38 2016 bougon_p
** Last update Sat Jun  4 17:23:42 2016 bougon_p
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

void	print_help(t_echo *opt)
{
  dprintf(opt->fd, "\necho : Usage : echo [OPTION] [STRINGS]\n\n");
  dprintf(opt->fd, "-n \t\tDo not output the trailing newline\n");
  dprintf(opt->fd, "-e \t\tEnable interpretation of backslash escapes\n");
  dprintf(opt->fd,
	  "-E \t\tDisable interpretation of backslash escapes (default)\n");
  dprintf(opt->fd, "--help \t\tDisplay this help and exit\n");
  dprintf(opt->fd, "--version \tOutput version information and exit\n");
}

void	invert(bool *waiting_d, bool *waiting_s, char c)
{
  if (c == '"')
    {
      if (!*waiting_d)
        *waiting_d = true;
      else
        *waiting_d = false;
    }
  else if (c == '\'')
    {
      if (!*waiting_s)
        *waiting_s = true;
      else
        *waiting_s = false;
    }
}

void	print_echo(t_echo *opt, char **arg)
{
  int	i;

  i = -1;
  while (arg[++i])
    {
      if ((arg[i][0] == '-' && opt_exist(arg[i], opt))
          || arg[i][0] != '-')
        {
          if (opt->opt_E)
	    print_str_no_change(arg[i], opt);
          else if (opt->opt_e)
	    print_str_changed(arg[i], opt);
	  if (arg[i + 1])
	    dprintf(opt->fd, " ");
	  fflush(stdout);
        }
    }
  if (!opt->opt_n)
    write(opt->fd, "\n", 1);
}
