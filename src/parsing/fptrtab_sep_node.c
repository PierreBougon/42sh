/*
** fptrtab_sep_node.c for fptrtab_sep_node in /home/marel_m/Rendu/Semestre_2/PSU/PSU_2015_42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Mon May 30 21:23:16 2016 marel_m
** Last update Mon May 30 21:30:39 2016 marel_m
*/

#include <stdlib.h>
#include "fptrtab.h"
#include "42s.h"

t_arg_act	*init_tab_arg_sep()
{
  t_arg_act	*tab;

  if ((tab = malloc(sizeof(t_arg_act) * MAX_ACT)) == NULL)
    return (NULL);
  tab[REDIR_RR].arg_act = DOUBLE_REDIR_RIGHT;
  tab[REDIR_RR].ft_arg_act = &arg_redir_rr;
  tab[REDIR_R].arg_act = REDIR_RIGHT;
  tab[REDIR_R].ft_arg_act = &arg_redir_r;
  tab[REDIR_L].arg_act = REDIR_LEFT;
  tab[REDIR_L].ft_arg_act = &arg_redir_l;
  tab[REDIR_LL].arg_act = DOUBLE_REDIR_LEFT;
  tab[REDIR_LL].ft_arg_act = &arg_redir_ll;
  tab[PIPE_INF].arg_act = PIPE;
  tab[PIPE_INF].ft_arg_act = &arg_pipe;
  return (tab);
}
