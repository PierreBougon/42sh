/*
** 42s.h for 42.sh in /home/peau_c/rendu/PSU/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 18 00:15:01 2016 Poc
** Last update Mon May 16 16:01:05 2016 Mathieu Sauvau
*/

#ifndef _42s_H_
# define _42s_H_

# define UNUSED __attribute__((unused))

# include "history.h"

typedef struct	s_key_action
{
  char		*key;
  void		(*fct)(char **, int *, t_head *, int *);
}		t_key_act;

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
  t_history	*history;
  int		fd_history;
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

/*
** ACTION
*/
void		move_left(char **, int *, t_head *, int *);
void		move_right(char **, int *, t_head *, int *);
void		debut(char **, int *, t_head *, int *);
void		end(char **, int *, t_head *, int *);
void		backspace(char **, int *, t_head *, int *);
void		auto_complet(char **, int *, t_head *, int *);

/*
** CURSOR
*/
void	cursor_forward(int x);
void	cursor_backward(int x);
void	cursor_erase(int x);
void	cursor_save();
void	cursor_restore();

#endif /* !_42s_H_ */
