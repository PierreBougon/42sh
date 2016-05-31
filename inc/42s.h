/*
** 42s.h for 42.sh in /home/peau_c/rendu/PSU/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 18 00:15:01 2016 Poc
** Last update Tue May 31 12:22:35 2016 Poc
*/

#ifndef _42s_H_
# define _42s_H_

# define UNUSED __attribute__((unused))

# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
# include "history.h"

typedef struct		s_key_action
{
  char			*key;
  void			(*fct)(char **, int *, t_head *, int *);
}			t_key_act;

typedef enum		e_type
  {
    SEMICOLON,
    DOUBLE_AND,
    DOUBLE_PIPE,
    PIPE,
    REDIR_RIGHT,
    REDIR_LEFT,
    DOUBLE_REDIR_RIGHT,
    DOUBLE_REDIR_LEFT,
    NO_ONE
  }			t_type;

typedef struct		s_node
{
  char			*arg;
  t_type		type;
  struct s_node		*left;
  struct s_node		*right;
}			t_node;

typedef struct		s_aliases
{
  char			*alias;
  char			*original;
  struct s_aliases	*next;
}			t_aliases;

typedef struct		s_conf
{
  t_aliases		*head;
}			t_conf;

typedef struct		s_list_sh
{
  t_node		*node;
  t_type		type;
  char			*arg;
  int			nb;
  struct s_list_sh	*next;
  struct s_list_sh	*prev;
}			t_list_sh;

typedef struct		s_env
{
  char			**env;
  char			*pwd;
  char			*oldpwd;
  char			*home;
  char			**path;
  char			pst_pwd;
  char			pst_home;
  char			pst_oldpwd;
  char			pst_path;
}			t_env;

typedef struct		s_exec
{
  char			**arg;
  char			*exec;
  int			**fd;
  char			*good_path;
  int			exit;
  int			stop;
  t_type		type;
}			t_exec;

typedef struct		s_sh
{
  t_list_sh		*root;
  int			lenght;
  t_node		*tree;
  t_env			*env;
  t_exec		*exec;
  t_history		*history;
  t_conf		conf;
  int			fd_history;
}			t_sh;

char			**my_str_to_word_tab(char *, char);
char			*my_strdup_e(char *, int);
char			*epur_str(char *);
int			check_env(t_sh *, char **);
int			check_path(t_sh *);
int			check_home(t_sh *);
int			check_pwd(t_sh *);
int			check_oldpwd(t_sh *);
char			*get_next_line(int);
char			*my_index(char *, char);
char			*epur(char  *);

/*
** ACTION
*/
void			move_left(char **, int *, t_head *, int *);
void			move_right(char **, int *, t_head *, int *);
void			debut(char **, int *, t_head *, int *);
void			end(char **, int *, t_head *, int *);
void			backspace(char **, int *, t_head *, int *);
void			auto_complet(char **, int *, t_head *, int *);
void			clear_scr(char **, int *, t_head *, int *);

/*
** 42RC
*/
int			check_alias(t_aliases *, char **);
int			get_conf_file(t_conf *, char ***);
int			create_alias(t_conf *, char ***, char *);
int			create_export(t_conf *, char ***, char *);

/*
** CURSOR
*/
void			cursor_forward(int x);
void			cursor_backward(int x);
void			cursor_erase(int x);
void			cursor_save();
void			cursor_restore();

/*
** PARSING
*/
char			*epur(char *);
int			parsing(t_sh *, char *);
t_node			**insert_node(t_node **, char *, char *, t_type);
int			create_list(t_sh *);
t_list_sh		*add_list_after(t_sh *);
char			*pars_pipe(t_list_sh *, char *);
char			*pars_redir(t_list_sh *, char *);
int			check_prior(char *);
int			arg_pipe(char **);
int			arg_redir_r(char **);
int			arg_redir_l(char **);
int			arg_redir_rr(char **);
int			arg_redir_ll(char **);

/*
** AUTO-COMPLETION
*/
char			**find_match(char **);
char			**find_routine(char **, char *, char *);
int			find_in_(char *, char *, char **);
char			*get_all_dir_path(char *, char *);
int			get_max_len(char **);
int			strlen_b_slash(char *);
char			*revstr(char *);
void			print_word_tab(char **, int);
char			**get_res(char **, char *, char *, struct stat *);
char			*get_elem(char *);
char			*get_path(char *);

/*
**BUILTINS
*/
int			my_setenv(t_sh *);
int			check_path_setenv(t_sh *);
int			my_unsetenv(t_sh *);
int			my_exit(t_sh *);
int			my_env(t_sh *);
int			my_cd(t_sh *);
int			check_cd_home(t_sh *);
int			check_cd_dash(t_sh *);
int			check_cd_good(t_sh *);
int			check_cd_else(t_sh *);
int			cd_action(t_sh *);
void			my_show_tab(char **);

/*
**EXEC
*/
int			execute_each_act(t_sh *);
int			check_good_path(t_sh *);
int			check_builtin(t_sh *);
int			builtin_or_exec(t_sh *);
int			redirection_right(t_sh *, t_node *);
int			redirection_left(t_sh *, t_node *);
int			double_redirection_right(t_sh *, t_node *);
int			no_separator(t_sh *, t_node *, t_node *);
int			verif_good_synthax(char *);

/*
** ENV
*/
int			check_env(t_sh *, char **);
int			check_path(t_sh *);
int			check_home(t_sh *);
int			check_pwd(t_sh *);
int			check_oldpwd(t_sh *);
int			check_if_present_env(t_sh *);

/*
** LIB
*/
char			*get_next_line(int);
char			*my_strdup_bt(char *, int, int);
char			**my_str_to_word_tab(char *, char);
char			*my_strdup_e(char *, int);
int			my_strlen(char *);
char			**my_realloc_tab(char **, int);
void			free_tab(char **);
char			*my_strcat(char *, char *);

/*
** FREE
*/
void			free_exec(t_exec *);
void			free_struct(t_sh *);
void			print_tree(t_node *);
void			free_env(t_env *);
void			free_tab_int(int **);

/*
** PROMPT
*/
char			*prompt_from_env(char **);
char			*get_prompt_value(char **);

/*
** Suggest algorithm
*/
int	suggest(t_sh *, char *);

#endif /* _42s_H_ */
