##
## Makefile for makefile in /home/guillaume2.roux/rendu/PSU_2016_lemipc/
##
## Made by guillaume2.roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Sun Apr  2 14:03:58 2017 guillaume2.roux
## Last update Sun Apr  2 14:06:43 2017 guillaume2.roux
##

NAME=	lemipc

SRC=	src/main.c

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
					gcc -o $(NAME) $(SRC) -Wall -Werror -Wextra

clean:
					rm -f $(OBJ)

fclean:		clean
					rm -f $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
