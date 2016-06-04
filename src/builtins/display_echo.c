/*
** display_echo.c for display in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 29 18:40:38 2016 bougon_p
** Last update Sat Jun  4 16:07:21 2016 marel_m
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

void	print_help()
{
  printf("\necho : Usage : echo [OPTION] [STRINGS]\n\n");
  printf("-n \t\tDo not output the trailing newline\n");
  printf("-e \t\tEnable interpretation of backslash escapes\n");
  printf("-E \t\tDisable interpretation of backslash escapes (default)\n");
  printf("--help \t\tDisplay this help and exit\n");
  printf("--version \tOutput version information and exit\n");
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
	    print_str_no_change(arg[i]);
          else if (opt->opt_e)
	    print_str_changed(arg[i], opt);
	  /* printf(" "); */
	  fflush(stdout);
        }
    }
  if (!opt->opt_n)
    write(1, "\n", 1);
}
