/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:00:58 2016 marel_m
** Last update Thu May 12 15:27:48 2016 Mathieu Sauvau
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

void		move_left(int *pos)
{
  //  printf("move left");
  cursorbackward(1);
  fflush(stdout);
}

void		move_right(int *pos)
{
  /* printf("move right\n"); */
  cursorforward(*pos++);
  fflush(stdout);
}

void		init_actions(t_key_act actions[4])
{
  actions[0].key = tigetstr("kcub1");
  actions[0].fct = &move_left;
  actions[1].key = tigetstr("kcuf1");
  actions[1].fct = &move_right;
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


int		do_action(t_key_act actions[2], char *str)
{
  static int		cur_pos;
  char		buff[10];
  char		*new;
  int		i;

  i = -1;
  memset(buff, 0, 10);
  //  cursorforward(10);
  read(0, buff, 10);
  while (++i < 2)
    {
      if (strcmp(buff, actions[i].key) == 0)
	{
	  actions[i].fct(&cur_pos);
	  return (1);
	}
    }
  write(1, buff, strlen(buff));
  i = -1;
  while (buff[++i])
    {
      if (buff[i] == '\n')
	return (3);
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  char		*str;
  t_sh		sh;
  t_key_act	actions[2];
  int		a;

  if (check_env(&sh, env))
    return (-1);
  setupterm(NULL, 0, NULL);
  printf("%s\n", tigetstr("smkx"));
  init_actions(actions);
  change_read_mode(0, 100, 0);
  str = NULL;
  a = 3;
  while (42)
    {
      if (a == 3)
	write(1, "hey ->", 7);
      a = do_action(actions, str);
      /* if ((str = get_next_line(0)) == NULL */
      /* 	  || (str = epur(str)) == NULL) */
      /* 	return (-1); */
      free(str);
    }
  return (0);
}
