##
## Makefile for makefile in /home/guillaume2.roux/rendu/PSU_2016_strace/
##
## Made by guillaume2.roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Thu Apr  6 17:30:10 2017 guillaume2.roux
## Last update Thu Apr  6 17:38:10 2017 guillaume2.roux
##

NAME=			strace

SRC=			$(wildcard ./src/*.c)

OBJ=			$(SRC:.c=.o)

CFLAGS=		-Wall -Werror -Wextra

all:			$(NAME)

$(NAME):	$(OBJ)
					gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
					rm -f $(OBJ)

fclean:		clean
					rm -f $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
