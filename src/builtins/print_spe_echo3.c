/*
** print_spe_echo3.c for print_spe_echo3 in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Jun  3 19:04:37 2016 marel_m
** Last update Sat Jun  4 17:30:08 2016 bougon_p
*/

#include <stdio.h>
#include "42s.h"

void    print_formfeed(t_echo *opt)
{
  dprintf(opt->fd, "\f");
}

void    print_newline(t_echo *opt)
{
  dprintf(opt->fd, "\n");
}

void    print_carriageret(t_echo *opt)
{
  dprintf(opt->fd, "\r");
}

void    print_tab(t_echo *opt)
{
  dprintf(opt->fd, "\t");
}

void    print_verttab(t_echo *opt)
{
  dprintf(opt->fd, "\v");
}
