/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:00:58 2016 marel_m
** Last update Sun Jun  5 15:29:37 2016 Mathieu Sauvau
*/

#include <sys/ioctl.h>
#include <ncurses.h>
#include <termios.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "42s.h"
#include "my_glob.h"
#include "var_env.h"

int		pars_check_exec(t_sh *sh, char *str)
{
  if (check_if_missing_name(sh, str))
    return (0);
  if ((str = epur(str)) == NULL)
    return (1);
  if (verif_good_synthax_string(sh, str)
      || verif_good_order_sep(sh, str)
      || (str = rewrite_redir_r_redir_l(str)) == NULL)
    return (0);
  if (parsing(sh, str) || execute_each_act(sh))
    return (1);
  my_free((void **)&str);
  return (0);
}

int		term_func_01(t_sh *sh, t_key_act actions[18],
			     char **str, t_head *history)
{
  init_actions(actions);
  history->first = NULL;
  history->last = NULL;
  get_history(sh, history);
  if (((*str) = malloc(sizeof(char) * 10)) == NULL ||
      (history->prompt = prompt_from_env(sh->env->env)) == NULL)
    return (1);
  write(1, history->prompt, strlen(history->prompt));
  (*str)[0] = 0;
  g_prompt = history->prompt;
  if (!memset((*str), 0, 10))
    return (1);
  return (0);
}

int		execution(char **str, t_head *history, t_sh *sh)
{
  int		tty;

  tty = isatty(0);
  if (str && str[0])
    {
      if (bang(str, history))
	return (0);
      if (tty)
	push_front_history(history, *str);
    }
  if (tty && sh->fd_history > 0)
    dprintf(sh->fd_history, "%s\n", *str);
  if (var_env_format(sh, str, sh->env->env)
      || (*str = check_good_quote_replace_quote(sh, *str)) == NULL)
    return (0);
  if (globing(str))
    return (1);
  check_alias(sh->conf.head, str);
  if (pars_check_exec(sh, *str))
    return (1);
  return (0);
}

int		test(char **str, t_sh *sh, t_head *history, int *a)
{
  sh->actual_pipe = 0;
  if (*str && (*str)[0] && execution(str, history, sh))
    return (1);
  if (isatty(0))
    {
      if ((*str = malloc(sizeof(char) * 10)) == NULL)
	return (1);
      (*str)[0] = 0;
      write(1, history->prompt, strlen(history->prompt));
    }
  else
    {
      *a = *a;
      *a = 0;
    }
  return (0);
}

int		main(UNUSED int ac, UNUSED char **av, char **env)
{
  t_sh		sh;
  char		*str;

  sh.list = NULL;
  if (check_env(&sh, env))
    return (1);
  get_conf_file(&sh.conf, &sh.env->env);
  init_data(&sh);
  if (isatty(0))
    {
      if (setupterm(NULL, 0, NULL) < 0 ||
	  !(str = tigetstr("smkx")))
	return (1);
      printf("%s", str);
      fflush(stdout);
      create_history_file(&sh);
      change_read_mode(2, 100, 1);
      change_read_mode(0, 100, 1);
      sh.history = NULL;
    }
  if (term(&sh))
    return (1);
  return (0);
}
