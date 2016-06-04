/*
** print_str.c for echo in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue May 31 17:48:01 2016 bougon_p
** Last update Sat Jun  4 17:32:05 2016 bougon_p
*/

#include <stdio.h>
#include "42s.h"

void	print_str_no_change(char *str, t_echo *opt)
{
  int	i;
  bool	waiting_s;
  bool	waiting_d;

  i = -1;
  waiting_s = false;
  waiting_d = false;
  while (str[++i])
    {
      if (str[i] != '"' && str[i] != '\'')
        dprintf(opt->fd, "%c", str[i]);
      else
        invert(&waiting_d, &waiting_s, str[i]);
    }
  fflush(stdout);
}

int	convert_next_letter(char c, t_echo *opt)
{
  int	i;

  i = -1;
  while (++i < NB_SPE_ECHO && opt->sequence[i] != c);
  if (i > NB_SPE_ECHO)
    return (0);
  if (i < NB_SPE_ECHO)
    opt->ftab[i](opt);
  else
    dprintf(opt->fd, "%c", c);
  if (i == 3)
    return (2);
  else if (i == 10)
    return (3);
  else if (i == 11)
    return (4);
  return (0);
}

int	chose_backslash_fct(char *str, t_echo *opt,
			    int i)
{
  int	ret;

  if ((ret = convert_next_letter(str[++i], opt)) == 2)
    {
      fflush(stdout);
      return (-1);
    }
  else if (ret == 3)
    {
      ret = print_octal_char(&str[++i], opt);
      i += ret - 1;
    }
  else if (ret == 4)
    {
      ret = print_hexa_char(&str[++i], opt);
      i += ret - 1;
    }
  return (i);
}

void	print_str_changed(char *str, t_echo *opt)
{
  int	i;
  bool	waiting_s;
  bool	waiting_d;

  i = -1;
  waiting_s = false;
  waiting_d = false;
  init_tab(opt);
  while (str[++i])
    {
      if (str[i] != '"' && str[i] != '\'' && str[i] != '\\')
        dprintf(opt->fd, "%c", str[i]);
      else if (str[i] == '\\')
	{
	  if ((i = chose_backslash_fct(str, opt, i)) == -1)
	    return ;
	}
      else
        invert(&waiting_d, &waiting_s, str[i]);
    }
  fflush(stdout);
}
