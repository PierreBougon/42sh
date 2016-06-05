/*
** main_loop.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Jun  5 15:24:48 2016 Mathieu Sauvau
** Last update Sun Jun  5 15:28:13 2016 Mathieu Sauvau
*/

#include <unistd.h>
#include <stdlib.h>
#include "42s.h"

int		term(t_sh *sh)
{
  char		*str;
  t_key_act	actions[18];
  int		a;
  t_head	history;

  history.cpy_buf = NULL;
  sh->reset_curs = false, sh->history = &history;
  if ((a = 3) && isatty(0) && term_func_01(sh, actions, &str, &history))
    return (1);
  sh->exit = 0;
  while (42)
    {
      sh->is_pipe = false;
      if (!isatty(0))
      	{
      	  if ((str = get_next_line(0)) == NULL)
	    exit(sh->exit);
      	  a = 3;
      	}
      else
	a = do_action(actions, &str, sh, history.prompt);
      if (a == 3 && test(&str, sh, &history, &a))
	return (1);
    }
  return (0);
}
