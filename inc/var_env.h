/*
** var_env.h for azd in /home/debrau_c/Documents/cours/PSU/save_var_env/srcs
**
** Made by debrau_c
** Login   <debrau_c@epitech.net>
**
** Started on  Tue May 31 13:17:48 2016 debrau_c
** Last update Wed Jun  1 10:43:59 2016 marel_m
*/

#ifndef VAR_ENV_H
# define VAR_ENV_H

# include "42s.h"

int	var_env_format(t_sh *, char **, char **);
char	*var_env_strcdup(char *str, char c);
int	var_env_strclen(char *str, char c);
int	var_env_strlen(char *str);
int	var_env_modify(char **str, char **env, int index, char *talon);
int	var_env_copy_fin(char *new, char **str, int j, int m);
int	var_env_place_k(char *env);
int	var_env_place_j(char *new, char *str, int index);

#endif /* !VAR_ENV_H */
