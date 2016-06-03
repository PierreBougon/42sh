/*
** free_tab.c for free_tab in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_minishell2
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Tue Mar 29 21:49:28 2016 marel_m
** Last update Fri Jun  3 13:27:32 2016 marel_m
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

void	free_tab_int(int **tab, int nb)
{
  int	l;

  l = 0;
  while (l < nb - 1)
    {
      free(tab[l]);
      l++;
    }
}
