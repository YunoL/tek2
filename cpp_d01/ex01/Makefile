##
## Makefile for Makefile in /home/guillaume2.roux/rendu/cpp_d01/ex01
## 
## Made by Guillaume Roux
## Login   <guillaume2.roux@epitech.net>
## 
## Started on  Wed Jan  4 08:43:45 2017 Guillaume Roux
## Last update Wed Jan  4 08:56:23 2017 Guillaume Roux
##

NAME	=	menger

SRC	=	main.c \
		menger.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -Wall -Wextra -Werror -std=gnu99

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
