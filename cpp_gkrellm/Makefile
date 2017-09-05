SRC=		src/main.cpp \
				src/Monitor.cpp \
				src/ScreenNCurse.cpp \
				src/ModRam.cpp \
				src/Module.cpp

NAME=		mygkrellm

XX=		g++

OBJ=		$(SRC:.cpp=.o)

CXXFLAGS=	-g -W -Wall -Wextra -std=c++03

INC=		-Isrc/

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(XX) -o $(NAME) $(OBJ) $(INC) -lncurses $(CXXFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

.cpp.o:
		@$(XX) -c $< -o $@ $(INC) $(CXXFLAGS)
