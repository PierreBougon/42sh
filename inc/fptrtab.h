/*
** fptrtab.h for fptrtab in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh/parsing
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat May  7 17:14:02 2016 marel_m
** Last update Sun May 29 17:04:21 2016 bougon_p
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

enum		cd
  {
    HOME_CD,
    DASH_CD,
    GOOD_CD,
    ELSE_CD,
    MAX_CD
  };

typedef struct	s_cd
{
  int		(*ft_cd)(t_sh *);
}		t_cd;

enum		blt
  {
    SETENV,
    UNSETENV,
    ENV,
    CD,
    EXIT,
    ECHO,
    MAX_BLT
  };

typedef struct	s_blt
{
  char		*blt;
  int		(*ft_blt)(t_sh *);
}		t_blt;

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
