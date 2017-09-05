##
## Makefile for  in /Users/pichar_v/Documents/tek2/cpp_santa/src/chapter2/
##
## Made by Valentin Pichard
## Login   <pichar_v@epitech.eu>
##
## Started on  Sat Jan 14 14:57:25 2017 Valentin Pichard
## Last update Sat Jan 14 15:35:09 2017 Valentin Pichard
##

SRC=		main.cpp \
		../Box.cpp \
		../ConveyorBeltPePeNoel.cpp \
		../ElfOfPePeNoel.cpp \
		../GiftPaper.cpp \
		../LittlePony.cpp \
		../Object.cpp \
		../TablePePeNoel.cpp \
		../Teddy.cpp \
		../Toy.cpp \
		../Wrap.cpp

NAME=		santa3

XX=		g++

OBJ=		$(SRC:.cpp=.o)

CXXFLAGS=	-g -W -Wall -Wextra -std=c++03

INC=		-I../

all:		$(NAME)
			@echo '==== END BUILDING CHAPTER3 ===='

$(NAME):	$(OBJ)
		@$(XX) -o $(NAME) $(OBJ) $(INC) $(CXXFLAGS)
		@mv $(NAME) ../../.

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

.cpp.o:
		@$(XX) -c $< -o $@ $(INC) $(CXXFLAGS)
