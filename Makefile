##
## Makefile for make in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Thu Jan  7 16:17:02 2016 Clement Peau
## Last update Thu Jun  2 16:35:33 2016 marel_m
##

DEBUG	=	no



# Color variables

BLUE	=	\033[1;34m

WHITE   =       \033[0m

RED	=	\033[1;31m



# Sources variables

AUTO	=	auto_completion/

SRC	=	main.c				\
		print_tree.c			\
		free/free_exec.c		\
		ncurses.c			\
		actions.c			\
		erase.c				\
		history.c			\
		index.c				\
		cursor.c			\
		bang.c				\
		clear.c				\
		convert_base.c			\
		prompt.c			\
		$(AUTO)autocompletion.c		\
		$(AUTO)auto_completion_find.c	\
		$(AUTO)auto_completion_utility.c\
		$(AUTO)auto_completion_utility2.c\
		$(AUTO)auto_completion_utility3.c\
		free/free_tab.c			\
		conf/conf.c			\
		conf/42rc_create_alias.c	\
		conf/42rc_alias_checker.c	\
		conf/42rc_create_export.c	\
		lib/my_get_next_line.c		\
		lib/my_str_to_word_tab.c	\
		lib/my_strdup.c			\
		lib/my_strcpy.c			\
		lib/my_strdup_bt.c		\
		lib/my_strdup_e.c		\
		lib/my_strlen.c			\
		lib/my_strcat.c			\
		lib/my_realloc_tab.c		\
		lib/my_getnbr.c			\
		lib/my_put_nbr.c		\
		lib/my_putstr.c			\
		lib/my_putstr_error.c		\
		lib/my_strcmp.c			\
		lib/my_strncmp.c		\
		lib/my_putchar.c		\
		lib/my_putchar_error.c		\
		env/check_home.c		\
		env/check_oldpwd.c		\
		env/check_path.c		\
		env/check_pwd.c			\
		env/env.c			\
		env/verif_env.c			\
		parsing/rewrite_str.c		\
		parsing/epur.c			\
		parsing/parsing.c		\
		parsing/create_list.c		\
		parsing/create_tree.c		\
		parsing/parsing_sep.c		\
		parsing/copy_arg_sep_node.c	\
		parsing/fptrtab_sep_node.c	\
		parsing/redirections_left_double.c	\
		parsing/parsing_double_quote.c		\
		manag_error/verif_good_order_sep.c	\
		manag_error/check_if_missing_name.c	\
		manag_error/verif_good_synthax.c	\
		manag_error/check_good_double_quote.c	\
		exec/execute.c			\
		exec/builtin_or_exec.c		\
		exec/check_good_path.c		\
		exec/redirections.c		\
		exec/wrong_path.c		\
		exec/pipe.c			\
		builtins/check_builtins.c	\
		builtins/check_cd.c		\
		builtins/check_env.c		\
		builtins/check_exit.c		\
		builtins/check_setenv.c		\
		builtins/check_unsetenv.c	\
		builtins/check_which_cd.c	\
		builtins/echo.c			\
		builtins/parse_echo.c		\
		builtins/display_echo.c		\
		builtins/check_spe_opt.c	\
		builtins/print_spe_echo.c	\
		builtins/print_hexoct.c		\
		builtins/print_str.c		\
		builtins/init_echo.c		\
		builtins/history.c		\
		free/free_fptrtab.c		\
		suggest/check_all_path.c	\
		suggest/levenshtein.c		\
		suggest/suggest.c		\
		glob/glob_dep.c			\
		glob/glob_dep2.c		\
		glob/globing.c			\
		dollars/var_env.c		\
		dollars/var_env_str.c		\
		dollars/var_env_dep.c		\
		double_left.c

ARGS	=	actions_arg/

DISP	=	display/

OPTS	=	change_options/

TETRI	=	stock_check_tetriminos/

FREE	=	free/

TETFILE	=	main.c \
		$(ARGS)check_arg.c \
		$(ARGS)read_arg.c \
		$(ARGS)init_options.c \
		$(ARGS)verif_size_all.c \
		$(DISP)display_help.c \
		$(DISP)display_help_error.c \
		$(DISP)display_debug.c \
		$(DISP)display_debug_key.c \
		$(DISP)display_board.c \
		$(OPTS)change_key_drop.c \
		$(OPTS)change_key_left.c \
		$(OPTS)change_key_pause.c \
		$(OPTS)change_key_quit.c \
		$(OPTS)change_key_right.c \
		$(OPTS)change_key_turn.c \
		$(OPTS)change_level.c \
		$(OPTS)change_map_size.c \
		$(OPTS)hide_next.c \
		$(OPTS)wrong_options.c \
		ncurses/init.c \
		ncurses/movement.c \
		ncurses/collision.c \
		ncurses/print_game.c \
		ncurses/mechanic.c \
		ncurses/main_loop.c \
		ncurses/purge_tetri.c \
		ncurses/key.c \
		ncurses/key2.c \
		ncurses/cpy_tetri.c \
		ncurses/rotate.c \
		ncurses/get_star.c \
		ncurses/re_init.c \
		ncurses/check_high_score.c \
		ncurses/itoa.c \
		$(TETRI)check_tetriminos.c \
		$(TETRI)stock.c \
		$(TETRI)put_in_list.c \
		$(TETRI)stock_tetrimino.c \
		$(TETRI)check_empty.c \
		$(FREE)free_options.c \
		$(FREE)free_struct.c \

TETRSRC	=	$(addprefix tetris/, $(TETFILE))

SRC	+=	$(TETRSRC)



# Project variables

OBJ	=	$(addprefix src/, $(SRC:.c=.o))

RM	=	rm -f

ifeq ($(DEBUG), yes)
CFLAGS	=	-W -Wall -Wextra -g -D DEBUG -O0
else
CFLAGS	=	-W -Wall -Wextra -Werror
endif

NAME	=	42sh

HEAD	=	-I inc/

all:		$(NAME)

#Project Rules

$(NAME):		$(OBJ)
			@make -s ctags
ifeq ($(DEBUG), yes)
			@tput setaf 5; tput bold;
			@echo " ____________________ ________________________   ____ ___._________________";
			@echo "/   _____/\_   _____|/  _____/\_   _____/  _  \ |    |   \    | \__    ___/";
			@echo "\_____  \  |    ___|/   \  ___ |    __)/  / \  \|    |   /    |   |    |";
			@echo "/        \ |        \    \_\  \|     \/    |    \    |  /|    |___|    |";
			@echo "/________//_________/\________/\_____/\____|____/______/ |________|____|";
			@tput sgr0
endif
			@echo -e "\n\n$(RED)Linking with :$(WHITE)\n"
			@echo -e "$(RED)CC$(WHITE)     = $(CC)"
			@echo -e "$(RED)CFLAGS$(WHITE) = $(CFLAGS)"
			@$(CC) $(OBJ) -o $(NAME) -lncurses
			@echo -e "$(BLUE) \t \t \n \t ♩♪♫ $(NAME) Compiled® Created Sucesfully $(WHITE)"


ctags:
		rm -rf TAGS
		find . -type f -iname "*.[chS]" | xargs etags -a
all:			$(NAME)


clean:
			@$(RM) $(OBJ)
			@echo -e "[ $(RED)OK$(WHITE) ] clean sucessfull"

fclean: 		clean
			@$(RM) $(NAME)
			@echo -e "[ $(RED)OK$(WHITE) ] fclean succesfull"

re:			fclean all

%.o:                    %.c
			@echo -e "[ $(BLUE)OK$(WHITE) ] Compiling" $<
			@$(CC) -o $@ -c $< $(CFLAGS) $(HEAD)
