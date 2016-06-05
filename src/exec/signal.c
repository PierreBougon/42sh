/*
** bultin_or_exec.c for builtin_or_exec in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed May 18 17:16:18 2016 marel_m
** Last update Sun Jun  5 17:59:13 2016 DEBRAUWERE Carl
*/

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "42s.h"

void    signal_gest_init(char *ref[11])
{
  ref[0] = "Hangup";
  ref[1] = "";
  ref[2] = "Quit";
  ref[3] = "Illegal instruction";
  ref[4] = "Trace/breakpoint trap";
  ref[5] = "Aborted";
  ref[6] = "Bus Error";
  ref[7] = "Floating point exception";
  ref[8] = "";
  ref[9] = "";
  ref[10] = "Segmentation fault";
}

int     signal_gest(int status, t_sh *sh, pid_t pid, bool stock)
{
  char  *ref[11];
  int   index;

  change_read_mode(0, 100, 1);
  if (g_zsig && !WIFEXITED(status) && stock)
    g_job_list = update_job_list(g_job_list, sh->exec->exec, pid);
  else if (g_job_list && g_job_list->prev->state == FG
  	   && g_last_fg && !g_zsig)
    g_job_list = erase_job(g_job_list->prev, g_job_list);
  g_zsig = false;
  signal_gest_init(ref);
  if (WIFSIGNALED(status))
    {
      index = (WTERMSIG(status) - 1);
      index %= 11;
      printf("%s", ref[index]);
      if (WCOREDUMP(status))
	printf(" (core dumped)\n");
      return (1);
    }
  return (0);
}
