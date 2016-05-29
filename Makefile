##
## Makefile for make in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Thu Jan  7 16:17:02 2016 Clement Peau
## Last update Sun May 29 18:45:27 2016 bougon_p
##

DEBUG=	no

SRC=	main.c				\
	free_exec.c			\
	ncurses.c			\
	actions.c			\
	erase.c				\
	history.c			\
	index.c				\
	cursor.c			\
	autocompletion.c		\
	free_tab.c			\
	conf/conf.c			\
	conf/42rc_create_alias.c	\
	conf/42rc_alias_checker.c	\
	lib/my_get_next_line.c		\
	lib/my_str_to_word_tab.c	\
	lib/my_strdup_bt.c		\
	lib/my_strdup_e.c		\
	lib/my_strlen.c			\
	lib/my_strcat.c			\
	lib/my_realloc_tab.c		\
	env/check_home.c		\
	env/check_oldpwd.c		\
	env/check_path.c		\
	env/check_pwd.c			\
	env/env.c			\
	env/verif_env.c			\
	parsing/epur.c			\
	parsing/parsing.c		\
	parsing/create_list.c		\
	parsing/create_tree.c		\
	parsing/parsing_sep.c		\
	exec/execute.c			\
	exec/builtin_or_exec.c		\
	exec/check_good_path.c		\
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
	suggest/check_all_path.c	\
	suggest/levenshtein.c		\
	suggest/suggest.c

OBJ=	$(addprefix src/, $(SRC:.c=.o))

RM=	rm -f

ifeq ($(DEBUG), yes)
	CFLAGS=		-W -Wall -Wextra -g -D DEBUG -O0
else
	CFLAGS=		-W -Wall -Wextra
endif

NAME=	42sh

HEAD=	-I inc/

$(NAME):                $(OBJ)
ifeq ($(DEBUG), yes)
	@tput setaf 1; tput bold
	@echo " ____________________ ________________________   ____ ___._________________";
	@echo "/   _____/\_   _____|/  _____/\_   _____/  _  \ |    |   \    | \__    ___/";
	@echo "\_____  \  |    ___|/   \  ___ |    __)/  / \  \|    |   /    |   |    |";
	@echo "/        \ |        \    \_\  \|     \/    |    \    |  /|    |___|    |";
	@echo "/________//_________/\________/\_____/\____|____/______/ |________|____|";
	@tput sgr0
	rm -rf TAGS
	find . -type f -iname "*.[chS]" | xargs etags -a
endif
	@ echo "CC = $(CC)"
	@ echo "CFLAGS = $(CFLAGS)"
	@ $(CC) $(OBJ) -o $(NAME) -lncurses
	@ echo -e "\033[1;31m \t \t \n \t ♩♪♫ $(NAME) Compiled\033[0;31m®\033[1;31m Created Sucesfully \033[0m"

all:		$(NAME)

clean:
		@ $(RM) $(OBJ)
		@ echo "[ OK ] clean sucessfull"
fclean: clean
		@ $(RM) $(NAME)
		@ echo "[ OK ] fclean succesfull"

re:	fclean all
%.o:                    %.c
			@ echo "[ OK ] Compiling" $<
			@ $(CC) -o $@ -c $< $(CFLAGS) $(HEAD)
