/*
** fptrtab.h for fptrtab in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh/parsing
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat May  7 17:14:02 2016 marel_m
** Last update Mon May 16 14:59:42 2016 Poc
*/

#ifndef FPTRTAB_H_
# define FPTRTAB_H_

#include "42s.h"

enum		env
  {
    PATH,
    HOME,
    PWD,
    OLDPWD,
    MAX_ELEM_ENV
  };

typedef struct	s_env_elem
{
  char		*env_elem;
  int		(*ft_env_elem)(t_sh *);
}		t_env_elem;

enum		conf_tab
  {
    ALIASES,
    EXPORTS,
  };

typedef struct	s_conf_tab
{
  int		(*(fp_conf[2]))(t_conf *, char **, char *);
  char		*(dico[5]);
}		t_conf_tab;

#endif /* !FPTRTAB_H_ */
