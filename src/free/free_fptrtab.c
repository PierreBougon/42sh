/*
** free_fptrtab.c for free_fptrtab in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Mon May 30 22:00:34 2016 marel_m
** Last update Fri Jun  3 13:18:11 2016 marel_m
*/

#include <stdlib.h>
#include "fptrtab.h"

void	free_tab_act(t_act *fptrtab)
{
  int	i;

  i = -1;
  while (++i < MAX_ACT)
    free(fptrtab[i].act);
  free(fptrtab);
}
