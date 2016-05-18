/*
** free_tab.c for free_tab in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_minishell2
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Mar 29 21:49:28 2016 marel_m
** Last update Wed May 18 18:39:49 2016 marel_m
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	l;

  l = 0;
  while (tab && tab[l] != '\0')
    {
      free(tab[l]);
      l++;
    }
}
