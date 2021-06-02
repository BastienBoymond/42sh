##
## EPITECH PROJECT, 2020
## libmy
## File description:
## makefile
##

SRC 	= $(wildcard *.c)

OBJ 	= $(SRC:.c=.o)

LIB 	= lib/libmy.a

all:	$(LIB)
	cp ./libmy.a ../libmy.a
	cp ./my.h ../../include/my.h

$(LIB): $(OBJ)
	$(AR) rsc libmy.a $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) #*#

fclean: clean
	$(RM) ../libmy.a
	$(RM) ../../include/my.h

re:	fclean all
