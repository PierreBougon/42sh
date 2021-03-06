/*
** conf.c for conf in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon May 16 10:35:56 2016 Poc
** Last update Sat Jun  4 21:53:24 2016 bougon_p
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "42s.h"
#include "fptrtab.h"

int	joyeuse_fonction(UNUSED t_conf *conf, UNUSED char **env, UNUSED char *str)
{
  printf("Je suis une joyeuse fonction\n");
  return (0);
}

int	prepare_fct_tab(t_conf_tab *tab)
{
  tab->dico[0] = "alias";
  tab->dico[1] = "export";
  tab->dico[2] = NULL;
  tab->fp_conf[0] = create_alias;
  tab->fp_conf[1] = create_export;
  return (0);
}

void	showlist(t_aliases *alias)
{
  while (alias)
    {
      printf("\nOriginal = %s\nAlias = %s\n", alias->original, alias->alias);
      alias = alias->next;
    }
}

int	get_conf_file(t_conf *conf, char ***env)
{
  int		fd;
  char		*str;
  char		*new_str;
  int		i;
  t_conf_tab	tab;

  conf->head = NULL;
  if ((fd = open(".42rc", O_RDONLY)) == -1)
    return (/* write(2, "Unable to locale .42rc\n", 23) -  */23);
  prepare_fct_tab(&tab);
  while ((str = get_next_line(fd)))
    {
      i = 0;
      new_str = epur(str);
      while (tab.dico[i])
	{
	  if (strncmp(tab.dico[i], new_str, strlen(tab.dico[i])) == 0)
	    tab.fp_conf[i](conf, env, new_str);
	  i++;
	}
      free(new_str);
    }
  close(fd);
  return (0);
}
