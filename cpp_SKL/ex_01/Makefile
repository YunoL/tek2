##
## Makefile for default in /home/mei/Projets/Tek2/cpp_SKL/ex_01
##
## Made by Meï
## Login   <main.meixdev@gmail.com>
##
## Started on  Sat Jan 07 23:37:22 2017 Meï
## Last update Sat Jan  7 23:38:18 2017 Meï
##

RM		= \rm -f

CC		= gcc

NAME		= ex1

SRCS		=	ex_01.c \
			new.c \
			point.c \

OBJS		= $(SRCS:.c=.o)

SHEETIES	= $(OBJS)

CFLAGS		= -W -Wall -Werror -Wextra -std=gnu99

LIB		= 

all:            $(NAME)

$(NAME):       $(OBJS)
		@echo -e "\e[0m"
		@$(CC) $(OBJS) $(LIB) -o $(NAME)
		@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME) "\e[32mcreated !\e[0m"

clean:
		@echo -en "\e[0mCleaning .o && .c~ files..."
		@$(RM) $(SHEETIES)
		@echo -e "	 [\e[32mOk !\e[0m]"

fclean:         clean
		@echo -en "\e[39mCleaning executable..."
		@$(RM) $(NAME)
		@echo -e "		 [\e[32mOk !\e[0m]"

re:             fclean all

comp:           re
		@echo -en "\e[0mCleaning .o && .c~ files..."
		@$(RM) $(SHEETIES)
		@echo -e "	 [\e[32mOk !\e[0m]"

.c.o:           %.c
		@$(CC) -c $< -o $@ $(CFLAGS) && \
		echo -e "\e[32m[OK]" $< "\e[93m"|| \
		echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"

.PHONY:         all clean fclean re comp
