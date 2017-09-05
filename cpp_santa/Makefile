##
## Makefile :D
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Sat Jul  2 21:56:26 2016 David Zeng
##

all:
	@(cd src/chapter2/. && $(MAKE) -C .)
	@(cd src/chapter3/. && $(MAKE) -C .)
	@(cd src/chapter4/. && $(MAKE) -C .)
	@(cd src/chapter5/. && $(MAKE) -C .)

clean:
	@(cd src/chapter2/. && make clean)
	@(cd src/chapter3/. && make clean)
	@(cd src/chapter4/. && make clean)
	@(cd src/chapter5/. && make clean)

fclean:		clean
	@(cd src/chapter2/. && make fclean)
	@(cd src/chapter3/. && make fclean)
	@(cd src/chapter4/. && make fclean)
	@(cd src/chapter5/. && make fclean)

re:		fclean all

.PHONY:		all clean fclean re
