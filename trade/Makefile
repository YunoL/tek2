NAME=		trade

SRC=		main.cpp \
				trade.cpp
XX=		g++

OBJ=		$(SRC:.cpp=.o)

CXXFLAGS=	-g -W -Wextra -std=c++03

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(XX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
