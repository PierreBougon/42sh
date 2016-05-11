/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:00:58 2016 marel_m
** Last update Wed May 11 18:48:12 2016 Mathieu Sauvau
*/

#include <ncurses/curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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


#define cursorforward(x) printf("\033[%dC", (x))
#define cursorbackward(x) printf("\033[%dD", (x))

int	main(int ac, char **av, char **env)
{
  char	*str;
  t_sh	sh;
  char	c[2];

  if (check_env(&sh, env))
    return (-1);
  setupterm(NULL, 0, NULL);
  c[0] = 0;
  str = malloc(1000);
  str[0] = 0;
  while (42)
    {
      write(1, "hey ->", 7);
      memset(str, 0, 1000);
      while ((c[0] = getchar()) != '\n')
	{
	  c[1] = 0;
	  strcat(str, c);
	}
      /* if ((str = get_next_line(0)) == NULL) */
      /* 	/\* || (str = epur(str)) == NULL) *\/ */
      /* 	return (-1); */
      printf("bite %s\n", str);
      printf("left %s\n", tigetstr("kcub1"));
      //      printf("right %d %d %d\n", s[0], s[1], s[2]);
      if (strcmp(str, tigetstr("kcub1")) == 0)
      	cursorbackward(1);
      if (strcmp(str, tigetstr("kcuf1")) == 0)
      	cursorforward(1);
    }
  return (0);
}
