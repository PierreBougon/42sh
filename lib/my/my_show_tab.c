/*
** my_show_tab.c for my_show_tab in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Jun  3 19:42:35 2016 marel_m
** Last update Sat Jun  4 20:29:34 2016 debrau_c
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
