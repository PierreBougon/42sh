/*
** init_echo.c for echo in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 31 17:46:55 2016 bougon_p
** Last update Tue May 31 17:47:30 2016 bougon_p
*/

#include "42s.h"

void	init_ftab(t_echo *opt)
{
  opt->ftab[0] = print_backslash;
  opt->ftab[1] = print_alert;
  opt->ftab[2] = print_backspace;
  opt->ftab[3] = print_nomore;
  opt->ftab[4] = print_escape;
  opt->ftab[5] = print_formfeed;
  opt->ftab[6] = print_newline;
  opt->ftab[7] = print_carriageret;
  opt->ftab[8] = print_tab;
  opt->ftab[9] = print_verttab;
  opt->ftab[10] = print_octal;
  opt->ftab[11] = print_hexa;
  opt->ftab[12] = print_squote;
  opt->ftab[13] = print_dquote;
}

void	init_tab(t_echo *opt)
{
  init_ftab(opt);
  opt->sequence[0] = '\\';
  opt->sequence[1] = 'a';
  opt->sequence[2] = 'b';
  opt->sequence[3] = 'c';
  opt->sequence[4] = 'e';
  opt->sequence[5] = 'f';
  opt->sequence[6] = 'n';
  opt->sequence[7] = 'r';
  opt->sequence[8] = 't';
  opt->sequence[9] = 'v';
  opt->sequence[10] = '0';
  opt->sequence[11] = 'x';
  opt->sequence[12] = '\'';
  opt->sequence[13] = '\"';
}
