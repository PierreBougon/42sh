/*
** jobs.c for  in /home/sauvau_m/rendu/PSU_2015_42sh
**
** Made by Mathieu Sauvau
** Login   <sauvau_m@epitech.net>
**
** Started on  Sun Jun  5 15:09:32 2016 Mathieu Sauvau
** Last update Sun Jun  5 15:23:20 2016 Mathieu Sauvau
*/

#include <signal.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "42s.h"

void	reset_keyboard_term()
{
  char	*str;

  if ((str = tigetstr("smkx")) != (char *)-1)
    {
      printf("%s", str);
      fflush(stdout);
    }
}

int	push_job_foreground(t_sh *sh)
{
  int	status;

  if (sh->is_pipe)
    {
      dprintf(2, "You can't resume a job in a pipe ;)\n");
      return (1);
    }
  if (g_job_list)
    {
      g_last_fg = true, g_job_list->prev->state = FG;
      kill(g_job_list->prev->pid, SIGCONT);
      g_need_check = true;
      if (waitpid(g_job_list->prev->pid, &status, WUNTRACED) == -1)
  	return (1);
      g_need_check = false;
      if (signal_gest(status, sh, g_job_list->prev->pid, false))
  	{
  	  sh->exit = status;
  	  sh->exec->stop = 1;
  	}
      g_last_fg = false, reset_keyboard_term();
    }
  else
    dprintf(2, "bg : no current job\n");
  return (0);
}

void		catch_ctrlz()
{
  if (g_need_check)
    g_zsig = true;
  g_need_check = false;
}

void		catch_ctrlc()
{
  printf("\n%s", g_prompt);
  g_ctrlc = true;
  fflush(stdout);
}

void		init_data(t_sh *sh)
{
  #ifndef DEBUG
  signal(SIGINT, catch_ctrlc);
  #endif
  signal(SIGTSTP, catch_ctrlz);
  g_job_list = NULL;
  g_zsig = false;
  g_need_check = false;
  g_last_fg = false;
  g_ctrlc = false;
  atexit(kill_list_job);
  sh->cwd = NULL;
  if (!(sh->cwd = getcwd(sh->cwd, 0)))
    exit(1);
}
