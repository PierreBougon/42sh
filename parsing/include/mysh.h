/*
** mysh.h for mysh in /home/marel_m/Rendu/Semestre_2/PSU/42sh
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Wed Apr 27 18:01:43 2016 marel_m
** Last update Sat May  7 18:30:14 2016 marel_m
*/

#ifndef MYSH_H_
# define MYSH_H_

typedef struct	s_node
{
  int		power;
  struct s_node	*left;
  struct s_node	*right;
}		t_node;

typedef struct	s_env
{
  char		**env;
  char		*pwd;
  char		*oldpwd;
  char		*home;
  char		**path;
  char		pst_pwd;
  char		pst_home;
  char		pst_oldpwd;
  char		pst_path;
}		t_env;

typedef struct	s_sh
{
  t_node	*tree;
  t_env		*env;
}		t_sh;

char		**my_str_to_word_tab(char *, char);
char		*my_strdup_e(char *, int);
int		check_env(t_sh *, char **);
int		check_path(t_sh *);
int		check_home(t_sh *);
int		check_pwd(t_sh *);
int		check_oldpwd(t_sh *);
char		*get_next_line(int);

#endif /* MYSH_H_ */
