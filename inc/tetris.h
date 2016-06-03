/*
** tetris.h for tetris in /home/marel_m/Rendu/Semestre_2/Systeme_Unix/PSU_2015_tetris
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Sat Feb 27 23:25:21 2016 maud marel
** Last update Fri Jun  3 18:59:41 2016 marel_m
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <curses.h>
# include "my.h"
# include "42s.h"

enum		check_opt
  {
    LEVEL,
    LEFT,
    RIGHT,
    TURN,
    DROP,
    QUIT,
    PAUSE,
    SIZE,
    NEXT,
    NEXT_S,
    MAX_CHECK_OPT
  };

enum		check_opt_simp
  {
    LEVEL_S,
    LEFT_S,
    RIGHT_S,
    TURN_S,
    DROP_S,
    QUIT_S,
    PAUSE_S,
    MAX_CHECK_OPT_SIMP
  };

typedef	struct	s_tetrimino
{
  int		max;
  int		height;
  int		width;
  int		color;
  int		x;
  int		y;
  char		*name;
  char		**tetrimino;
}		t_tetri;

typedef	struct			s_list_tetrimino
{
  t_tetri			*tetrimino;
  int				nb_tetri;
  int				nb_error;
  struct s_list_tetrimino	*next;
  struct s_list_tetrimino	*prev;
}				t_list_tetri;

typedef struct	s_options
{
  int		level;
  int		row;
  int		col;
  int		hide_next;
  char		*left;
  char		*right;
  char		*turn;
  char		*drop;
  char		*quit;
  char		*pause;
}		t_options;

typedef struct	s_key_fct t_key_fct;

typedef	struct	s_tetris
{
  WINDOW	*wgame;
  WINDOW	*wscore;
  WINDOW	*wnext;
  t_key_fct	*key_tab;
  t_options	*options;
  t_list_tetri	*list_tetri;
  char		**board;
  int		high_score;
  int		score;
  int		lines;
  int		start_time;
  int		save_time;
  int		time;
  int		level;
  float		speed;
  bool		pause;
  bool		quit;
  bool		moved;
  float		i;
  int		nb_tetri;
}		t_tetris;

typedef struct	s_check_opt
{
  char		*opt;
  bool		(*ft_com)(t_tetris *, char *);
}		t_check_opt;

typedef struct	s_check_opt_smp
{
  char		*opt;
  bool		(*ft_simp)(t_tetris *, char *);
}		t_check_opt_simp;

typedef struct	s_key_fct
{
  char		*key;
  void		(*ft_simp)(t_tetris *, t_tetri *);
}		t_key_fct;

/*
** Init list
*/

t_list_tetri	*add_list_before(t_list_tetri *);
t_list_tetri	*which_order(t_tetris *, char *);
int		tcreate_list(t_tetris *);

/*
** Stock infos
*/

int		check_form(t_list_tetri *, int);
int		stock(char *, t_tetris *, int, char *);
int		check_tetriminos(t_tetris *);
int		init_tetris(t_tetris *);
int		check_empty(t_tetris *, char *);

/*
** Change options
*/

int		check_arg(t_tetris *, int, char **);
int		read_arg(t_tetris *, int, char **);
int		check_complex_arg(t_tetris *, char *);
int		check_simp_arg(t_tetris *, char *, char *);
bool		change_level(t_tetris *, char *);
bool		change_key_left(t_tetris *, char *);
bool		change_key_right(t_tetris *, char *);
bool		change_key_turn(t_tetris *, char *);
bool		change_key_drop(t_tetris *, char *);
bool		change_key_quit(t_tetris *, char *);
bool		change_key_pause(t_tetris *, char *);
bool		change_map_size(t_tetris *, char *);
bool		hide_next(t_tetris *, char *);
bool		change_without_next(t_tetris *, char *);
bool		change_level_simp(t_tetris *, char *);
bool		change_key_left_simp(t_tetris *, char *);
bool		change_key_right_simp(t_tetris *, char *);
bool		change_key_turn_simp(t_tetris *, char *);
bool		change_key_drop_simp(t_tetris *, char *);
bool		change_key_quit_simp(t_tetris *, char *);
bool		change_key_pause_simp(t_tetris *, char *);
bool		change_without_next_simp(t_tetris *, char *);
void		wrong_options(char *);
void		verif_size_all(t_tetris *);

/*
** Display
*/

int		display_debug(t_tetris *, int);
void		display_debug_key(char *);
void		display_key(t_tetris *);
void		display_help(char *);
void		display_help_error();

/*
** Fonctions Lib
*/

char		*get_next_line(const int);
char		*my_realloc(char *, int);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int);
char		*my_strcpy(char *, char *);
char		*my_strdup(char *);
int		my_strlen(char *);
int		my_put_nbr(int);
void		my_putchar(char);
void		my_putstr(char *);
int		my_getnbr(char *);
char		*my_strcat(char *, char *);
void		my_putstr_error(char *);
void		my_putchar_error(char);
void		mode_canon(int i, int time, int nb_char);

/*
**GAME PART
*/

WINDOW		*create_newwin(int, int, int, int);
void		show_score(WINDOW *, t_tetris *);
void		init_tetri(t_tetri *tetri);
void		print_tetri(WINDOW *game, t_tetri *tetri);
void		check_color();
void		print_game(WINDOW *game, t_tetris *data, t_tetri *tetri);
bool		space_occupied_down(t_tetris *data, t_tetri *tetri);
bool		space_occupied_right(t_tetris *data, t_tetri *tetri);
bool		space_occupied_left(t_tetris *data, t_tetri *tetri);
bool		can_move_left(t_tetris *data, t_tetri *tetri);
bool		can_move_right(t_tetris *data, t_tetri *tetri);
t_list_tetri	*add_tetri(t_list_tetri *list, t_tetri *tetri);
int		max_tetri(t_list_tetri *list_tetri);
t_tetri		*cpy_tetri(t_tetri *tetri);
t_tetri		*random_tetri(t_list_tetri *list_tetri, int nb_tetri);
bool		can_move_down(t_tetris *data, t_tetri *tetri);
void		show_next(WINDOW *wnext, t_tetri *next);
void		update_board(t_tetris *tetris, t_tetri *tetri);
void		clear_line(t_tetris *data, int line);
void		fall(WINDOW *game, t_tetris *data);
void		line_completion(t_tetris *data, WINDOW *game);
t_list_tetri	*get_valid_tetri(t_list_tetri *all_tetri);
t_tetri		*rotate_tetri(t_tetri *tetri, t_tetris *tetris);
void		start_loop(t_tetris *tetris);
bool		init_ncurses();
char		**init_board(t_tetris *tetris);
void		init_score(t_tetris *data);
void		center_tetri(t_list_tetri *list_tetri);
bool		check_window(t_tetris *tetris);
int		get_first_star_on_x(t_tetri *tetri);
void		rotate(t_tetris *data, t_tetri *tetri);
void		tmove_left(t_tetris *data, t_tetri *tetri);
void		tmove_right(t_tetris *data, t_tetri *tetri);
void		drop(t_tetris *data, t_tetri *tetri);
void		quit(t_tetris *data, t_tetri *tetri);
void		do_pause(t_tetris *data, t_tetri *tetri);
t_key_fct	*get_fct_key(t_tetris *tetris);
int		key(t_tetris *tetris,
		    char *buffer, t_tetri *tetri);
void		read_key(t_tetris *data, t_tetri *tetri);
t_tetri		*cpy_tetri(t_tetri *tetri);
int		max_tetri(t_list_tetri *list_tetri);
void		reset_buffer(char *buffer);
t_tetri		*random_tetri(t_list_tetri *list_tetri, int nb_tetri);
t_tetri		*init_first_loop(t_tetris *tetris);
int		get_last_star_on_x(t_tetri *tetri);
int		get_last_star_on_y(t_tetri *tetri);
void		show_logo(WINDOW *);
void		you_loose(t_tetris *data);
void		clear_board(t_tetris *data);

/*
**HIGH_SCORE
*/

int		recup_high_score(t_tetris *);
int		check_high_score(t_tetris *);
char		*itoa(int, char *, int);

/*
**FREE
*/
void	free_tetri(t_tetri *tetri);
void	tfree_struct(t_tetris *tetris);
void	free_options(t_tetris *tetris);

/*
** FREE
*/

void		free_options(t_tetris *);
void		tfree_struct(t_tetris *);

int		tetris(t_sh *);

#endif /* !TETRIS_H_ */
