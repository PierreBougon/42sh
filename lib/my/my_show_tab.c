/*
** my_show_tab.c for my_show_tab in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Jun  3 19:42:35 2016 marel_m
** Last update Sun Jun  5 11:01:05 2016 bougon_p
*/

#include <stdio.h>

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

void	my_show_tab_fd(char **str, int fd)
{
  int	i;

  i = 0;
  while (str && str[i] != '\0')
    {
      dprintf(fd, "%s\n", str[i]);
      i++;
    }
}
