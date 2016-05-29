/*
** display_echo.c for display in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 29 18:40:38 2016 bougon_p
** Last update Sun May 29 18:41:45 2016 bougon_p
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "42s.h"

void	print_help()
{
  printf("echo : Usage : echo [OPTION] [STRINGS]\n\n");
  printf("-n \tdo not output the trailing newline\n");
  printf("-e \tenable interpretation of backslash escapes\n");
  printf("-E \tdisable interpretation of backslash escapes (default)\n");
  printf("--help \tdisplay this help and exit\n");
  printf("--version \toutput version information and exit\n");
}

void	print_echo(t_echo *opt, char **arg)
{
  if (opt->opt_n)
    write(1, "\n", 1);
}
