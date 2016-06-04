/*
** print_spe_echo2.c for print_spe_echo2 in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Jun  3 19:03:16 2016 marel_m
** Last update Sat Jun  4 17:29:45 2016 bougon_p
*/

#include <stdio.h>
#include "42s.h"

void    print_backslash(t_echo *opt)
{
  dprintf(opt->fd, "\\");
}

void    print_alert(t_echo *opt)
{
  dprintf(opt->fd, "\a");
}

void    print_backspace(t_echo *opt)
{
  dprintf(opt->fd, "\b");
}

void    print_nomore(UNUSED t_echo *opt)
{
}

void    print_escape(t_echo *opt)
{
  dprintf(opt->fd, "\e");
}
