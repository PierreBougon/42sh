/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:00:58 2016 marel_m
** Last update Thu Jun  2 10:10:55 2016 Mathieu Sauvau
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
#include <sys/stat.h>
#include <fcntl.h>
#include "42s.h"
#include "my_glob.h"
#include "var_env.h"

void	my_show_tab(char **str)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      printf("%s\n", str[i]);
      i++;
    }
}

int		init_actions_next(t_key_act actions[14])
{
  actions[0].fct = &move_left;
  actions[1].fct = &move_right;
  actions[2].fct = &debut;
  actions[3].fct = &end;
  actions[4].fct = &backspace;
  actions[5].fct = &backspace;
  actions[6].fct = &history_up;
  actions[7].fct = &history_down;
  actions[8].fct = &auto_complet;
  actions[9].fct = &clear_scr;
  actions[10].fct = &del;
  actions[11].fct = &backspace;
  actions[12].fct = &end;
  actions[13].fct = &debut;
  return (0);
}

int		init_actions2(t_key_act actions[14])
{
  char		end[2];
  char		start[2];
  char		backs[2];

  backs[0] = 127;
  backs[1] = 0;
  end[0] = 5;
  end[1] = 0;
  start[0] = 1;
  start[1] = 0;
  if ((!(actions[11].key = strdup(&backs[0])) ||
       !(actions[12].key = strdup(end)) ||
       !(actions[13].key = strdup(start))))
    return (-1);
  return (init_actions_next(actions));
}

int		init_actions(t_key_act actions[14])
{
  char		*str;

  if ((str = tigetstr("kcub1")) == (char *)-1 ||
      !(actions[0].key = strdup(str)) ||
      (str = tigetstr("kcuf1")) == (char *)-1 ||
      !(actions[1].key = strdup(str)) ||
      (str = tigetstr("khome")) == (char *)-1 ||
      !(actions[2].key = strdup(str)) ||
      (str = tigetstr("kend")) == (char *)-1 ||
      !(actions[3].key = strdup(str)) ||
      (str = tigetstr("kbs")) == (char *)-1 ||
      !(actions[4].key = strdup(str)) ||
      (str = tigetstr("cub1")) == (char *)-1 ||
      !(actions[5].key = strdup(str)) ||
      (str = tigetstr("kcuu1")) == (char *)-1 ||
      !(actions[6].key = strdup(str)) ||
      (str = tigetstr("kcud1")) == (char *)-1 ||
      !(actions[7].key = strdup(str)) ||
      !(actions[8].key = strdup("\t")) ||
      !(actions[9].key = strdup("\f")) ||
      (str = tigetstr("kdch1")) == (char *)-1 ||
      !(actions[10].key = strdup(str)))
    return (-1);
  return (init_actions2(actions));
}

void            change_read_mode(int i, int time, int nb_char)
{
  static struct termios old;
  static struct termios new;

  if (i == 0)
    {
      ioctl(0, TCGETS, &old);
      ioctl(0, TCGETS, &new);
      new.c_lflag &= ~(ICANON);
      new.c_lflag &= ~(ECHO);
      new.c_cc[VMIN] = nb_char;
      new.c_cc[VTIME] = time;
      ioctl(0, TCSETS, &new);
    }
  if (i == 1)
    ioctl(0, TCSETS, &old);
}

int		cpy_to_pos(char **str, char *buff, int *curs_pos, char *prompt)
{
  char		*start;
  char		*end;

  if ((start = strdup(*str)) == NULL)
    return (1);
  start[*curs_pos] = 0;
  if ((end = strdup(*str + *curs_pos)) == NULL ||
      (*str = realloc(*str, strlen(*str) + strlen(buff) + 1)) == NULL)
    return (1);
  strcpy(*str, start);
  strcat(*str, buff);
  strcat(*str, end);
  *curs_pos += 1;
  cursor_forward(1);
  cursor_save();
  fflush(stdout);
  write(1, "\r", 1);
  write(1, prompt, strlen(prompt));
  write(1, *str, strlen(*str));
  cursor_restore();
  fflush(stdout);
  return (0);
}

int		do_action(t_key_act actions[14], char **str,
			  t_sh *sh, char *prompt)
{
  static int	cur_pos;
  static int	index_history;
  char		buff[11];
  int		i;
  t_head	*history;

  history = sh->history;
  i = -1;
  memset(buff, 0, 11);
  read(0, buff, 10);
  history->prompt = prompt;

  /* int j = -1; */
  /* while (++j < 10) */
  /*   printf("\n%d %c\n", buff[j], buff[j]); */

  while (++i < 14)
    {
      if (strcmp(buff, actions[i].key) == 0)
	{
	  actions[i].fct(str, &cur_pos, history, &index_history);
	  return (1);
	}
    }
  if (check_exit(buff))
    do_shortcut_exit(sh);
  i = -1;
  while (buff[++i])
    {
      if (buff[i] == '\n')
	{
	  printf("\n");
	  cur_pos = 0;
	  return (3);
	}
    }
  cpy_to_pos(str, buff, &cur_pos, prompt);
  return (0);
}

void		get_history(t_sh *sh, t_head *history)
{
  char		*str;

  history->path = sh->env->path;
  while ((str = get_next_line(sh->fd_history)))
    {
      push_front_history(history, str);
      free(str);
    }
}

int		pars_check_exec(t_sh *sh, char *str)
{
  if (check_if_missing_name(sh, str))
    return (0);
  if ((str = epur(str)) == NULL)
    return (1);
  if (verif_good_synthax_string(sh, str)
      || verif_good_order_sep(sh, str))
    return (0);
  if (parsing(sh, str) || execute_each_act(sh))
    return (1);
  /* free_struct(sh); */
  return (0);
}

int		term_func_01(t_sh *sh, t_key_act actions[14],
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
  if (!memset((*str), 0, 10))
    return (1);
  return (0);
}

int		execution(char **str, t_head *history, t_sh *sh)
{
  if (str && str[0])
    {
      if ((sh->exit = bang(str, history)))
	return (0);
      push_front_history(history, *str);
    }
  if (sh->fd_history > 0)
    dprintf(sh->fd_history, "%s\n", *str);
  check_alias(sh->conf.head, str);
  if (var_env_format(sh, str, sh->env->env))
    return (0);
  if (globing(str)
      || pars_check_exec(sh, *str))
    return (1);
  return (0);
}

int		test(char **str, t_sh *sh, t_head *history, int *a)
{
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
  t_key_act	actions[14];
  int		a;
  t_head	history;

  sh->history = &history;
  if (isatty(0) && term_func_01(sh, actions, &str, &history))
    return (1);
  a = 3;
  sh->exit = 0;
  while (42)
    {
      if (!isatty(0))
      	{
      	  if ((str = get_next_line(0)) == NULL)
	    return (sh->exit);
      	  a = 3;
      	}
      else
	a = do_action(actions, &str, sh, history.prompt);
      if (a == 3 && test(&str, sh, &history, &a))
	return (1);
    }
  return (0);
}

void		create_history_file(t_sh *sh)
{
  sh->fd_history = open(".42sh_history", O_CREAT | O_RDWR | O_APPEND,
			S_IRUSR | S_IWUSR | S_IRGRP |
			S_IWGRP | S_IROTH | S_IWOTH);
}

int		main(UNUSED int ac, UNUSED char **av, char **env)
{
  t_sh		sh;

  if (check_env(&sh, env))
    return (1);
  get_conf_file(&sh.conf, &sh.env->env);
  if (isatty(0))
    {
      if (setupterm(NULL, 0, NULL) < 0)
	return (1);
      printf("%s", tigetstr("smkx"));
      fflush(stdout);
      create_history_file(&sh);
      change_read_mode(0, 100, 1);
      sh.history = NULL;
    }
  if (term(&sh))
    return (1);
  return (0);
}
