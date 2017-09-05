##
## Makefile for makefile in /home/guillaume2.roux/rendu/PSU_2016_zappy/
##
## Made by Guillaume Roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Thu Jun 15 11:39:36 2017 Guillaume Roux
## Last update Wed Jun 21 12:53:19 2017 Guillaume Roux
##

SERVER=	zappy_server

CLIENT=	zappy_ai

XX=		g++

CXXFLAGS=	-g -W -Wall -Wextra -std=c++11

SRC_SERVER=	$(wildcard ./server_src/*.c)

SRC_CLIENT=	$(wildcard ./ai_src/*.cpp)

OBJ_SERVER=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT=	$(SRC_CLIENT:.cpp=.o)

all:	$(SERVER) $(CLIENT)

$(SERVER):	$(OBJ_SERVER)
						gcc -o $(SERVER) $(OBJ_SERVER) -W -Werror -Wextra -lm

$(CLIENT):	$(OBJ_CLIENT)
						@$(XX) -o $(CLIENT) $(OBJ_CLIENT) $(CXXFLAGS)

clean:
						rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:			clean
						rm -f $(SERVER) $(CLIENT)

re:					fclean all

.PHONY:			all clean fclean re

.cpp.o:
						@$(XX) -c $< -o $@ $(CXXFLAGS)
