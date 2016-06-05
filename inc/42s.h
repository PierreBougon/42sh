/*
** 42s.h for 42.sh in /home/peau_c/rendu/PSU/PSU_2015_42sh
**
** Made by Poc
** Login   <peau_c@epitech.net>
**
** Started on  Mon Apr 18 00:15:01 2016 Poc
** Last update Sun Jun  5 15:40:48 2016 Poc
*/

#ifndef _42s_H_
# define _42s_H_

# define UNUSED __attribute__((unused))

# define ECHO_VERSION "echo 42.0.0\n\
Copyright (C) 2016 Free Software Foundation, Inc.\n\
This is free software; see the source for copying conditions.  There is NO\n\
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
# define NB_SPE_ECHO 14

# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "history.h"

typedef struct		s_key_action
{
  char			*key;
  void			(*fct)(char **, int *, t_head *, int *);
}			t_key_act;

typedef struct		s_auto_completion
{
  char			**tab_str;
  int			i_elem;
  int			show;
  int			show_all;
  char			*path;
  char			*elem;
}			t_autoc;

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

typedef enum		e_job_state
  {
    FG,
    BG
  }			t_job_state;

typedef	struct		s_job_list
{
  int			num;
  char			*cmd;
  pid_t			pid;
  t_job_state		state;
  struct s_job_list	*next;
  struct s_job_list	*prev;
}			t_job_list;

t_job_list		*g_job_list;
bool			g_zsig;
bool			g_need_check;
bool			g_last_fg;
bool			g_ctrlc;
char			*g_prompt;

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

typedef struct	s_echo	t_echo;

typedef	struct		s_echo
{
  bool			opt_e;
  bool			opt_n;
  bool			opt_E;
  bool			opt_help;
  bool			opt_vers;
  int			nb_opt;
  char			*opt_tab;
  void			(*ftab[NB_SPE_ECHO])(t_echo *);
  char			sequence[NB_SPE_ECHO];
  int			fd;
}			t_echo;

typedef struct		s_node
{
  char			*arg;
  t_type		type;
  struct s_node		*left;
  struct s_node		*right;
}			t_node;

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
  int			stop;
  t_type		type;
}			t_exec;

typedef struct		s_pid
{
  int	pid;
  struct s_pid		*next;
}			t_pid;

typedef struct		s_sh
{
  t_list_sh		*root;
  int			lenght;
  int			exit;
  t_node		*tree;
  t_env			*env;
  t_exec		*exec;
  t_conf		conf;
  t_head		*history;
  int			fd_history;
  int			actual_pipe;
  bool			reset_curs;
  bool			is_pipe;
  t_pid			*list;
  t_job_list		*job_list;
  char			*cwd;
}			t_sh;

char			*my_index(char *, char);
void			change_read_mode(int, int, int);
char			*my_itoa(int nb);

/*
** HISTORY
*/
void			get_history(t_sh *, t_head *);
void			create_history_file(t_sh *);

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
void			del(char **, int *, t_head *, int *);
void			ctrl_left(char **, int *, t_head *, int *);
void			ctrl_right(char **, int *, t_head *, int *);
void			ctrl_k(char **, int *, t_head *, int *);
void			ctrl_y(char **, int *, t_head *, int *);
bool			check_exit(char *);
void			do_shortcut_exit(t_sh *);
int			init_actions(t_key_act *);
int			do_action(t_key_act *, char **, t_sh *, char *);

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
char			*pars_pipe(t_list_sh *, char *, int);
char			*pars_redir(t_list_sh *, char *, int);
int			bang(char **, t_head *);
int			check_prior(char *);
int			arg_pipe(char **);
int			arg_redir_r(char **);
int			arg_redir_l(char **);
int			arg_redir_rr(char **);
int			arg_redir_ll(char **);
char			*rewrite_str(char *);
char			*pars_double_redirection_left(t_list_sh *, char *, int);
int			check_quote(char *, char, char);
int			pos_double_quote(char *, char);
int			double_quote_redir(char *);
char			*pars_redir_right(t_list_sh *, char *, int);
int			signal_gest(int, t_sh *, pid_t, bool);
char			*rewrite_redir_r_redir_l(char *);

/*
** ERROR
*/
int			check_if_missing_name(t_sh *, char *);
int			verif_good_synthax(char *);
int			verif_good_synthax_string(t_sh *, char *);
int			verif_good_order_sep(t_sh *, char *);
char			*check_good_quote_replace_quote(t_sh *, char *);
int			if_is_a_separator(char *, int *, int *);
int			check_synthax(char *, int, int);

/*
** AUTO-COMPLETION
*/
char			**find_match(char **, char **, int);
char			**find_routine(char **, char **, t_autoc *);
int			find_in_(char *, char *, char **, int);
char			*get_all_dir_path(char *, char *, int);
int			get_max_len(char **);
int			strlen_b_slash(char *);
char			*revstr(char *);
void			print_word_tab(char **, int);
char			**get_res(char **, char *, char *, struct stat *);
char			*get_elem(char *);
char			*get_path(char *);
int			nb_word_tab(char **);
int			get_commom_subtring(char **);
char			*get_new_str(char **, char *, char *, char *);
int			show_bin(t_autoc *);
int			find_in_env_path(char **, char *, char **);
int			auto_check_quote(char *);
void			free_autoc(t_autoc *);

/*
**BUILTINS
*/
int			my_setenv(t_sh *);
int			check_setenv_path(t_sh *);
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
int			my_echo(t_sh *);
void			parse_opt(t_echo *, t_sh *);
void			print_help();
void			print_echo(t_echo *, char **);
bool			version(char *);
bool			help(char *);
void			print_backslash(t_echo *);
void			print_alert(t_echo *);
void			print_backspace(t_echo *);
void			print_nomore(t_echo *);
void			print_escape(t_echo *);
void			print_formfeed(t_echo *);
void			print_newline(t_echo *);
void			print_carriageret(t_echo *);
void			print_tab(t_echo *);
void			print_verttab(t_echo *);
void			print_octal(t_echo *);
void			print_hexa(t_echo *);
void			print_squote(t_echo *);
void			print_dquote(t_echo *);
bool			opt_exist(char *, t_echo *);
int			print_octal_char(char *, t_echo *);
int			print_hexa_char(char *, t_echo *);
void			print_str_no_change(char *, t_echo *);
void			print_str_changed(char *, t_echo *);
void			invert(bool *, bool *, char);
void			init_tab(t_echo *);
int			blt_hist(t_sh *);
int			tetris(t_sh *);

/*
**EXEC
*/
int			check_which_config(t_sh *, t_list_sh *, t_node *);
int			execute_each_act(t_sh *);
int			check_good_path(t_sh *);
int			check_builtin(t_sh *);
int			builtin_or_exec(t_sh *);
int			redirection_right(t_sh *, t_node *);
int			redirection_left(t_sh *, t_node *);
int			pipes(t_sh *, t_node *);
int			double_redirection_right(t_sh *, t_node *);
int			no_separator(t_sh *, t_node *, t_node *);
int			check_wrong_path(t_sh *);
int			double_redir_left(t_sh *, t_node *);
int			close_all(int **);
int			wait_func(t_pid *, t_sh *);
void			add_to_back(t_pid **, int);
void			close_all_first_pipe(int **, int);
void			loop_execute(t_sh *, t_list_sh **, int *);

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
int			my_getnbr(char *);

/*
** FREE
*/
void			free_exec(t_exec *);
void			free_struct(t_sh *);
void			free_word_tab(char **);
void			print_tree(t_node *);
void			free_env(t_env *);
void			free_tab_int(int **, int);
void			my_free(void **);
void			free_list(t_sh *);
void			clear_list(t_pid *);

/*
** PROMPT
*/
char			*prompt_from_env(char **);
char			*get_prompt_value(char **);

/*
** SUGGEST
*/
int			suggest(t_sh *, char *);

/*
** CONVERT BASE
*/
unsigned int		my_getnbr_base_limit(char *, char *, unsigned int, int *);
void			change_read_mode(int, int, int);

/*
** Job list
*/
t_job_list		*update_job_list(t_job_list *, char *, pid_t);
t_job_list		*erase_job(t_job_list *, t_job_list *);
int			push_job_foreground(t_sh *);
int			print_list(t_sh *);
void			kill_list_job(void);

#endif /* _42s_H_ */
