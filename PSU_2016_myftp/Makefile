##
## Makefile for makefile in /home/guillaume2.roux/rendu/PSU_2016_myftp/
##
## Made by Guillaume Roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Wed May 10 10:18:07 2017 Guillaume Roux
## Last update Wed May 10 10:18:12 2017 Guillaume Roux
##


NAME=	server

SRC=	$(wildcard ./src/*.c)

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
					gcc -o $(NAME) $(OBJ) -Wall -Werror -Wextra

clean:
					rm -f $(OBJ)

fclean:		clean
					rm -f $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
