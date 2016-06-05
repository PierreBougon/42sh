/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:00:58 2016 marel_m
** Last update Sun Jun  5 15:05:29 2016 marel_m
*/

#include <signal.h>
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

int	push_job_foreground(t_sh *sh)
{
  int	status;

  if (sh->is_pipe)
    {
      dprintf(2, "You can't resume a job in a pipe ;)\n");
      return (1);
    }
  if (g_job_list)
    {
      g_last_fg = true;
      g_job_list->prev->state = FG;
      kill(g_job_list->prev->pid, SIGCONT);
      g_need_check = true;
      if (waitpid(g_job_list->prev->pid, &status, WUNTRACED) == -1)
  	return (1);
      g_need_check = false;
      if (signal_gest(status, sh, g_job_list->prev->pid, false))
  	{
  	  sh->exit = status;
  	  sh->exec->stop = 1;
  	}
      g_last_fg = false;
    }
  else
    dprintf(2, "bg : no current job\n");
  return (0);
}

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

int		term(t_sh *sh)
{
  char		*str;
  t_key_act	actions[18];
  int		a;
  t_head	history;

  history.cpy_buf = NULL;
  sh->reset_curs = false;
  sh->history = &history;
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

void		catch_ctrlz()
{
  if (g_need_check)
    g_zsig = true;
  g_need_check = false;
}

void		catch_ctrlc()
{
  printf("\n%s", g_prompt);
  g_ctrlc = true;
  fflush(stdout);
}

void		init_data(t_sh *sh)
{
  #ifndef DEBUG
  signal(SIGINT, catch_ctrlc);
  #endif
  signal(SIGTSTP, catch_ctrlz);
  g_job_list = NULL;
  g_zsig = false;
  g_need_check = false;
  g_last_fg = false;
  g_ctrlc = false;
  atexit(kill_list_job);
  sh->cwd = NULL;
  if (!(sh->cwd = getcwd(sh->cwd, 0)))
    exit(1);
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
