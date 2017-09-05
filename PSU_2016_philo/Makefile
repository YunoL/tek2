##
## Makefile for makefile in /home/guillaume/rendu/PSU_2016_philo/
##
## Made by Guillaume Roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Wed Mar  8 12:50:26 2017 Guillaume Roux
## Last update Thu Jul  6 19:42:00 2017 Guillaume Roux
##

NAME=			philo

SRC=			$(wildcard ./src/*.c)

OBJ=			$(SRC:.c=.o)

CFLAGS=		-Wall -Wextra -Werror -lpthread

all:			$(NAME)

$(NAME):	$(OBJ)
					gcc -o $(NAME) -L. -lriceferee $(OBJ) $(CFLAGS)

clean:
					rm -f $(OBJ)

fclean:		clean
					rm -f $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
