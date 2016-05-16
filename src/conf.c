/*
** conf.c for conf in /home/peau_c/rendu/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon May 16 10:35:56 2016 Poc
** Last update Mon May 16 14:59:29 2016 Poc
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "42s.h"
#include "fptrtab.h"

int	joyeuse_fonction(t_conf *conf, char **env, char *str)
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
  tab->fp_conf[1] = joyeuse_fonction;
  return (0);
}

int	get_conf_file(t_conf *conf, t_env **env)
{
  int		fd;
  char		*str;
  int		i;
  t_conf_tab	tab;

  conf->head = NULL;
  if ((fd = open(".42rc", O_RDONLY)) == -1)
    return (0);
  prepare_fct_tab(&tab);
  while ((str = get_next_line(fd)))
    {
      i = 0;
      while (tab.dico[i])
	{
	  if (strncmp(tab.dico[i], str, strlen(tab.dico[i])) == 0)
	    tab.fp_conf[i](conf, env, str);
	    i++;
	}
      str = epur(str);
      printf("%s\n", str);
    }
  return (0);
}
