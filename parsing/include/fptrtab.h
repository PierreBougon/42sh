/*
** fptrtab.h for fptrtab in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh/parsing
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Sat May  7 17:14:02 2016 marel_m
** Last update Sat May  7 17:19:29 2016 marel_m
*/

#ifndef FPTRTAB_H_
# define FPTRTAB_H_

#include "mysh.h"

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

#endif /* !FPTRTAB_H_ */
