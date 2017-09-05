##
## Makefile for Makefile in /home/guillaume2.roux/rendu/PSU_2016_malloc/
##
## Made by guillaume2.roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Mon Jan 23 10:48:45 2017 guillaume2.roux
## Last update Wed Feb  1 10:34:41 2017 guillaume2.roux
##

NAME	=	libmy_malloc.so

CFLAGS	=	-Wall -Wextra -fPIC

SRC	=	src/malloc.c		\
		src/realloc.c		\
		src/free.c	\
		src/list.c \
		src/calloc.c

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		gcc $(CFLAGS) $(OBJ) -shared -o $(NAME)

all	:	$(NAME)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	: fclean all
