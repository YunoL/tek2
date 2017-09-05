##
## Makefile for makefile in /home/guillaume2.roux/rendu/cpp_plazza/
##
## Made by guillaume2.roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Tue Apr 11 16:36:43 2017 guillaume2.roux
## Last update Tue Apr 25 15:36:33 2017 guillaume2.roux
##

NAME=	plazza

SRC=	$(wildcard ./src/*.cpp)

OBJ=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
					g++ -o $(NAME) $(OBJ) -g -W -Wall -Wextra -pthread

clean:
					rm -rf $(OBJ)

fclean:		clean
					rm -rf $(NAME)

re:				fclean all

.PHONY:	all clean fclean re
