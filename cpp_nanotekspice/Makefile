##
## Makefile for makefile in /home/guillaume2.roux/rendu/cpp_nanotekspice/
##
## Made by guillaume2.roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Thu Feb  9 09:56:47 2017 guillaume2.roux
## Last update Mon Feb 13 10:01:53 2017 guillaume2.roux
##

NAME=	nanotekspice

SRC=	src/ASTParser.cpp \
			src/Components.cpp \
			src/chipset/2716.cpp \
			src/chipset/4001.cpp \
			src/chipset/4008.cpp \
			src/chipset/4011.cpp \
			src/chipset/4013.cpp \
			src/chipset/4017.cpp \
			src/chipset/4030.cpp \
			src/chipset/4040.cpp \
			src/chipset/4069.cpp \
			src/chipset/4071.cpp \
			src/chipset/4081.cpp \
			src/chipset/4094.cpp \
			src/chipset/4514.cpp \
			src/chipset/4801.cpp \
			src/main.cpp \
			src/Shell.cpp

OBJ=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
					g++ -o $(NAME) $(OBJ) -g -W -Wall -Werror -Wextra

clean:
					rm -f $(OBJ)

fclean:		clean
					rm -f $(NAME)

re:				fclean all

.PHONY:		all clean fclean re
