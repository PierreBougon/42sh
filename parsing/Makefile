##
## Makefile for makefile in /home/marel_m/Rendu/Semestre_2/PSU/42sh
##
## Made by marel_m
## Login   <marel_m@epitech.net>
##
## Started on  Wed Apr 27 17:57:42 2016 marel_m
## Last update Fri Apr 29 18:24:51 2016 marel_m
##

NAME	=	try

SRC	=	src/main.c \
		src/env.c \
		src/my_get_next_line.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

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
