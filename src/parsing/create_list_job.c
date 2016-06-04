/*
** create_list_job.c for list in /home/bougon_p/rendu/PSU_2015_42sh
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Jun  3 16:38:09 2016 bougon_p
** Last update Sat Jun  4 17:51:14 2016 marel_m
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "42s.h"

static void	clean_elem(t_job_list *elem)
{
  if (elem->cmd)
    free(elem->cmd);
  free(elem);
}

/*
** Use this function to erase an elem of your list
** Return null if your list is now empty
** Else return root of the list
*/
t_job_list		*erase_job(t_job_list *to_erase, t_job_list *root)
{
  t_job_list		*next;

  if (to_erase->next == to_erase)
    {
      clean_elem(to_erase);
      return (NULL);
    }
  else
    {
      next = to_erase->next;
      if (to_erase == root)
	root = next;
      to_erase->next->prev = to_erase->prev;
      to_erase->prev->next = to_erase->next;
      clean_elem(to_erase);
    }
  return (root);
}

static t_job_list	*create_list_job(char *cmd,
					 pid_t pid)
{
  t_job_list		*new;

  if (!(new = malloc(sizeof(t_job_list))))
    exit(1);
  new->next = new;
  new->prev = new;
  new->num = 1;
  new->state = BG;
  if (!(new->cmd = strdup(cmd)))
      exit(1);
  new->pid = pid;
  return (new);
}

static t_job_list	*push_back_job(t_job_list *root,
				       char *cmd, pid_t pid)
{
  t_job_list		*new;

  if (!(new = malloc(sizeof(t_job_list))))
    exit(1);
  new->next = root;
  new->prev = root->prev;
  root->prev->next = new;
  root->prev = new;
  new->num = new->prev->num + 1;
  new->state = BG;
  if (!(new->cmd = strdup(cmd)))
      exit(1);
  new->pid = pid;
  return (new);
}

/*
** Use this function to update the list
** Need the comand line and the pid of the
** Process you just launched
** Return pointer on root
*/
t_job_list	*update_job_list(t_job_list *root,
				 char *cmd, pid_t pid)
{
  if (!root)
    root = create_list_job(cmd, pid);
  else
    push_back_job(root, cmd, pid);
  return (root);
}
