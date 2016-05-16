##
## Makefile for make in /home/peau_c/rendu/PSU/minishell/PSU_2015_minishell1
##
## Made by Clement Peau
## Login   <peau_c@epitech.net>
##
## Started on  Thu Jan  7 16:17:02 2016 Clement Peau
## Last update Mon May 16 15:48:09 2016 Poc
##

DEBUG=	no

SRC=	main.c			\
	epur.c			\
	env/check_home.c	\
	env/check_oldpwd.c	\
	env/check_path.c	\
	env/check_pwd.c		\
	env/env.c		\
	conf.c			\
	42rc_create_alias.c	\
	my_get_next_line.c	\
	my_str_to_word_tab.c	\
	my_strdup_e.c		\
	ncurses.c		\
	actions.c		\
	erase.c			\
	history.c		\
	index.c			\

OBJ=	$(addprefix src/, $(SRC:.c=.o))

RM=	rm -f

ifeq ($(DEBUG), yes)
	CFLAGS=		-W -Wall -Wextra -g -D DEBUG -O0
else
	CFLAGS=		-W -Wall -Wextra -Werror
endif

NAME=	mysh

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
