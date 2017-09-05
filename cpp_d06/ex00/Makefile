##
## Makefile for Makefile in /home/guillaume2.roux/rendu/cpp_d06/ex00
## 
## Made by Guillaume Roux
## Login   <guillaume2.roux@epitech.net>
## 
## Started on  Mon Jan  9 09:02:53 2017 Guillaume Roux
## Last update Mon Jan  9 09:02:54 2017 Guillaume Roux
##

NAME	=	my_cat

SRC		=	main.cpp

OBJ		=	$(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
					g++ -o $(NAME) $(OBJ) -Werror -Wall -Wextra -std=c++03

clean:
					rm -f $(OBJ)

fclean:	clean
				rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re