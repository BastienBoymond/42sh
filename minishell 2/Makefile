##
## EPITECH PROJECT, 2020
## MAkefile
## File description:
##  cp the libmy.a into lib/, then cp the my.h into include/, then clean the temp files
##

RM	=	rm -f

CC	=	gcc

AR	=	ar

CFLAGS		=	-w -Wall -Wextra -Werror
CPPFLAGS	=	-Iinclude

SRC	=	$(wildcard lib/my/*.c)

OBJ	=	$(SRC:.c=.o)

LIB	=	lib/my/libmy.a

TARGET	=	mysh

SRC1	=	$(wildcard src/*.c)
SRC_TEST = 	./src/my_cd.c 				\
			./src/pwd.c 				\
			./src/envgestion.c 			\
			./src/envgestion2.c 		\
			./src/executation.c 		\
			./src/comma.c 				\
			./src/my_exit.c				\
			./src/order_command.c		\
			./src/parser.c				\
			./src/parsing_side.c		\
			./src/pipe.c				\
			./src/redirect_two.c		\
			./src/redirect.c			\
			./src/run_command.c			\
			./tests/tests.c				\

all:	$(TARGET)

$(TARGET):	$(LIB)
	$(CC) $(CFLAGS) $(SRC1)  -o $@ $(CPPFLAGS) -Llib/my -lmy

$(LIB):	$(OBJ)
	$(AR) rsc $@ $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *.o
	$(RM) *~
	$(RM) *.gcda
	$(RM) *.gcno

fclean:	clean
	$(RM) $(LIB)
	$(RM) $(TARGET)
	$(RM) units_tests


tests_run: fclean $(LIB)
	$(CC) $(CFLAGS) -o ./units_tests $(SRC_TEST) $(CPPFLAGS) -Llib/my -lmy --coverage -lcriterion
	./units_tests

re:	fclean all