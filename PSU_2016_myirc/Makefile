##
## Makefile for makefile in /home/guillaume2.roux/rendu/PSU_2016_myirc/
##
## Made by Guillaume Roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Tue May 23 14:13:50 2017 Guillaume Roux
## Last update Tue Jun  6 12:37:26 2017 Guillaume Roux
##

SERVER=	server

CLIENT=	client

SRC_SERVER=	$(wildcard ./server_src/*.c) \
						$(wildcard ./utility/*.c)

SRC_CLIENT=	$(wildcard ./client_src/*.c) \
						$(wildcard ./utility/*.c)

OBJ_SERVER=	$(SRC_SERVER:.c=.o)

OBJ_CLIENT=	$(SRC_CLIENT:.c=.o)

all:	$(SERVER) $(CLIENT)

$(SERVER):	$(OBJ_SERVER)
						gcc -o $(SERVER) $(OBJ_SERVER) -W -Werror -Wextra

$(CLIENT):	$(OBJ_CLIENT)
						gcc -o $(CLIENT) $(OBJ_CLIENT) -Wall -Werror -Wextra

clean:
						rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:			clean
						rm -f $(SERVER) $(CLIENT)

re:					fclean all

.PHONY:			all clean fclean re
