/*
** print_list_job.c for print_list_job in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat Jun  4 17:50:42 2016 marel_m
** Last update Sun Jun  5 04:33:17 2016 bougon_p
*/

#include <stdio.h>
#include "42s.h"

int		print_list(UNUSED t_sh *sh)
{
  t_job_list	*tmp;

  if (!g_job_list)
    {
      dprintf(2, "bg : no current job\n");
      return (0);
    }
  tmp = g_job_list;
  while (tmp->next != g_job_list)
    {
      printf("[%d] -> %s\n", tmp->num, tmp->cmd);
      tmp = tmp->next;
    }
  printf("[%d] -> %s\n", tmp->num, tmp->cmd);
  return (0);
}
