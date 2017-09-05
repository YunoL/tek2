##
## Makefile for template in /home/Maxoulakin/lib
##
## Made by Maxime Maisonnas
## Login   <Maxoulakin@epitech.net>
##
## Started on  Wed Jan  4 09:17:21 2017 Maxime Maisonnas
## Last update Sat Jan 14 19:23:56 2017 John Doe
##

NAME	= santa4

CC	= g++

RM	= rm -f

CXXFLAGS += -Wall -Wextra -Werror -std=c++03 -I../

SRCS	= main.cpp \
	  ../ConveyorBeltPePeNoel.cpp \
	  ../GiftPaper.cpp \
	  ../Box.cpp \
	  ../Object.cpp \
	  ../TablePePeNoel.cpp \
	  ../Teddy.cpp \
	  ../Toy.cpp \
	  ../Wrap.cpp \
	  ../LittlePony.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)
	@echo '==== END BUILDING CHAPTER4 ===='

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CXXLIB) $(LDFLAGS)
	@mv $(NAME) ../../.

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.cpp.o:
	@$(CC) -c $< -o $@ $(CXXFLAGS)
