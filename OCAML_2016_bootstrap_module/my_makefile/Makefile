##
## Makefile for makefile in /home/guillaume2.roux/rendu/my_makefile/
##
## Made by guillaume2.roux
## Login   <guillaume2.roux@epitech.eu>
##
## Started on  Tue Apr  4 10:27:12 2017 guillaume2.roux
## Last update Tue Apr  4 10:55:50 2017 guillaume2.roux
##

NAME	=	a.out

ML		=	$(wildcard ./*.ml)

MLI		=	$(wildcard ./*.mli)

CMI = $(MLI:.mli=.cmi)
CMO = $(ML:.ml=.cmo)
CMX = $(ML:.ml=.cmx)

OCAMLDPE = ocamldep
CAMLFLAGS = -w Aelz -warn-error A
OCAMLC = ocamlc $(CAMLFLAGS)
OCAMLOPT = ocamlopt $(CAMLFLAGS)
OCAMLDOC = ocamldoc -html -d $(ROOT)/doc

all:		.depend $(CMI) $(NAME)

byte:		.depend $(CMI) $(NAME).byte

$(NAME):	$(CMX)
					@$(OCAMLOPT) -o $@ $(CMX)
					@echo "[OK] $(NAME) linked"

$(NAME).byte:	$(CMO)
							@$(OCAMLC) -o $@ $(CMO)
							@echo "[OK] $(NAME).byte linked"

%.cmx:		%.ml
					@$(OCAMLOPT) -c $<

%.cmo:		%.ml
					@$(OCAMLC) -c $<

%.cmi:		%.mli
					@$(OCAMLC) -c $<

documentation:  $(CMI)
								@$(OCAMLDOC) $(MLI)

clean:
				@/bin/rm -f *.cm* *.o .depend *~

fclean:		clean
					@/bin/rm -f $(NAME) $(NAME).byte

re:				fclean all

.depend:
					@/bin/rm -f .depend
					@$(OCAMLDPE) $(MLI) $(ML) > .depend

.PHONY:		all clean fclean re
