/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:00:58 2016 marel_m
** Last update Thu May 12 20:46:38 2016 Mathieu Sauvau
*/

#include <sys/ioctl.h>
#include <termios.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "42s.h"

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

void		init_actions(t_key_act actions[5])
{
  actions[0].key = strdup(tigetstr("kcub1"));
  actions[0].fct = &move_left;
  actions[1].key = strdup(tigetstr("kcuf1"));
  actions[1].fct = &move_right;
  actions[2].key = strdup(tigetstr("khome"));
  actions[2].fct = &debut;
  actions[3].key = strdup(tigetstr("kend"));
  actions[3].fct = &end;
  actions[4].key = strdup(tigetstr("kbs"));
  actions[4].fct = &backspace;
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

int		cpy_to_pos(char **str, char *buff, int *curs_pos)
{
  char		*start;
  char		*end;
  int		y;
  int		x;

  y = 0;
  x = 0;
  start = strdup(*str);
  start[*curs_pos] = 0;
  end = strdup(*str + *curs_pos);
  *str = realloc(*str, strlen(*str) + strlen(buff) + 1);
  strcpy(*str, start);
  strcat(*str, buff);
  strcat(*str, end);
  *curs_pos += 1;
  CURSOR_FORWARD(1);
  CURSOR_SAVE;
  getsyx(y,x);
  //  printf("     %d\n", y);
  /* MOVE_CURSOR_TO(0, y); */
  fflush(stdout);
  write(1, "\r", 1);
  write(1, "hey ->", 6);
  write(1, *str, strlen(*str));
  CURSOR_RESTORE;
  fflush(stdout);
  return (0);
}

int		do_action(t_key_act actions[5], char **str)
{
  static int	cur_pos;
  char		buff[10];
  int		i;

  i = -1;
  memset(buff, 0, 10);
  read(0, buff, 10);
  while (++i < 5)
    {
      if (strcmp(buff, actions[i].key) == 0)
	{
	  actions[i].fct(str, &cur_pos);
	  return (1);
	}
    }
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
  cpy_to_pos(str, buff, &cur_pos);
  return (0);
}

char		*term()
{
  char		*str;
  t_key_act	actions[5];
  int		a;

  init_actions(actions);
  a = 3;
  if ((str = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  str[0] = 0;
  memset(str, 0, 10);
  write(1, "hey ->", 7);
  while (42)
    {
      a = do_action(actions, &str);
      if (a == 3)
	{
	  // execute_command(str); // Fonction d'exec et de parsing
	  //	  free(str);
	  write(1, "hey ->", 7);
	  if ((str = malloc(sizeof(char) * 10)) == NULL)
	    return (NULL);
	  str[0] = 0;
	}
    }
}

int		main(UNUSED int ac, UNUSED char **av, char **env)
{
  char		*str;
  t_sh		sh;

  if (check_env(&sh, env))
    return (-1);
  setupterm(NULL, 0, NULL);
  printf("%s\n", tigetstr("smkx"));
  change_read_mode(0, 100, 1);
  str = term();
  return (0);
}
