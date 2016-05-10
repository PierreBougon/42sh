/*
** 42s.h for 42.sh in /home/peau_c/rendu/PSU/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 18 00:15:01 2016 Poc
** Last update Mon May  9 15:06:11 2016 marel_m
*/

#ifndef _42s_H_
# define _42s_H_

typedef struct  s_node
{
  int           power;
  struct s_node *left;
  struct s_node *right;
}               t_node;

typedef struct  s_env
{
  char          **env;
  char          *pwd;
  char          *oldpwd;
  char          *home;
  char          **path;
  char          pst_pwd;
  char          pst_home;
  char          pst_oldpwd;
  char          pst_path;
}               t_env;

typedef struct  s_sh
{
  t_node        *tree;
  t_env         *env;
}               t_sh;

char            **my_str_to_word_tab(char *, char);
char            *my_strdup_e(char *, int);
char		*epur_str(char *);
int             check_env(t_sh *, char **);
int             check_path(t_sh *);
int             check_home(t_sh *);
int             check_pwd(t_sh *);
int             check_oldpwd(t_sh *);
char            *get_next_line(int);

#endif /* _42s_H_ */
