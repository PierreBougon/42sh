/*
** kill_list_job.c for kill in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun Jun  5 03:58:14 2016 bougon_p
** Last update Sun Jun  5 11:20:16 2016 bougon_p
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "42s.h"

void		kill_list_job()
{
  t_job_list	*root;
  t_job_list	*tmp;
  t_job_list	*to_free;

  root = g_job_list;
  if (!g_job_list)
    return ;
  tmp = root;
  while (tmp->next != root)
    {
      to_free = tmp;
      kill(tmp->pid, SIGSTOP);
      if (tmp->cmd)
	free(tmp->cmd);
      tmp = tmp->next;
      free(to_free);
    }
  to_free = tmp;
  kill(tmp->pid, SIGSTOP);
  if (tmp->cmd)
    free(tmp->cmd);
  tmp = tmp->next;
  free(to_free);
  g_job_list = NULL;
}
