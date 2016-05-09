##
## Makefile for makefile in /home/marel_m/Rendu/Semestre_2/PSU/42sh
##
## Made by marel_m
## Login   <marel_m@epitech.net>
##
## Started on  Wed Apr 27 17:57:42 2016 marel_m
## Last update Sat May  7 21:30:35 2016 marel_m
##

NAME	=	try

SRC	=	src/main.c \
		src/env.c \
		src/my_get_next_line.c \
		src/epur.c \
		src/check_home.c \
		src/check_oldpwd.c \
		src/check_path.c \
		src/check_pwd.c \
		src/my_str_to_word_tab.c \
		src/my_strdup_e.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

CFLAGS	=	-W -Wall -Wextra

CFLAGS	+=	-Iinclude/

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
