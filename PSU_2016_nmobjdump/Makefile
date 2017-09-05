##
## Makefile for makefile in /home/guillaume2.roux/rendu/PSU_2016_nmobjdump/
##
## Made by guillaume2.roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Tue Feb 14 11:36:08 2017 guillaume2.roux
## Last update Fri Feb 17 15:52:55 2017 Guillaume Roux
##

NM= 				my_nm

OBJDUMP= 		my_objdump

SRC=				nm/my_nm.c

SRC2= 			objdump/my_objdump.c \
						objdump/objdump32.c \
						objdump/objdump64.c

OBJ=				$(SRC:.c=.o)

OBJ2=				$(SRC2:.c=.o)

all:				$(NM) $(OBJDUMP)

nm: 				$(NM)

objdump: 		$(OBJDUMP)

$(NM):			$(OBJ)
						gcc -o $(NM) $(OBJ) -W -Wall -Wextra -Werror

$(OBJDUMP):	$(OBJ2)
						gcc -o $(OBJDUMP) $(OBJ2) -W -Wall -Wextra -Werror

clean:
					rm -f $(OBJ) $(OBJ2)

fclean:		clean
					rm -f $(NM) $(OBJDUMP)

re:				fclean all

.PHONY:		all clean fclean re
