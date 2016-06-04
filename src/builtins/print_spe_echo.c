/*
** print_spe_echo.c for echo in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon May 30 16:31:08 2016 bougon_p
** Last update Sat Jun  4 17:29:32 2016 bougon_p
*/

#include <stdio.h>
#include "42s.h"

void	print_octal(UNUSED t_echo *opt)
{
}

void	print_hexa(UNUSED t_echo *opt)
{
}

void	print_squote(t_echo *opt)
{
  dprintf(opt->fd, "\'");
}

void	print_dquote(t_echo *opt)
{
  dprintf(opt->fd, "\"");
}
