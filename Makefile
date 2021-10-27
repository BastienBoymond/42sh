##
## EPITECH PROJECT, 2020
## MAkefile
## File description:
##  cp the libmy.a into lib/, then cp the my.h into include/, then clean the temp files
##

RM	=	rm -f

CC	=	gcc -g3

AR	=	ar

CFLAGS		=	-w -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter
CPPFLAGS	=	-Iinclude

SRC	=	$(wildcard lib/my/*.c)

OBJ	=	$(SRC:.c=.o)

LIB	=	lib/my/libmy.a

TARGET	=	42sh

SRC1	=	$(wildcard src/*.c)	\
			$(wildcard src/termios/*.c)

SRC_TEST = 	./src/my_cd.c 				\
			./src/pwd.c 				\
			./src/envgestion.c 			\
			./src/envgestion2.c 		\
			./src/executation.c 		\
			./src/comma.c 				\
			./src/backstick.c 			\
			./src/my_exit.c				\
			./src/order_command.c		\
			./src/parser.c				\
			./src/parse_cmd.c			\
			./src/parsing_side.c		\
			./src/local_var.c			\
			./src/pipe.c				\
			./src/redirect_two.c		\
			./src/redirect.c			\
			./src/run_command.c			\
			./src/my_echo.c				\
			./src/double_pipe.c			\
			./src/and_and.c				\
			./src/checker.c				\
			./src/var_checker.c			\
			./src/utilities.c			\
			./src/my_alias.c			\
			./src/my_globing.c			\
			./src/history.c				\
			./src/inhibitor.c			\
			./src/precmd.c				\
			./src/which_where.c			\
			./src/repeater.c			\
			./src/change_local.c		\
			./src/termios/arrow_down.c	\
			./src/termios/arrow_left.c	\
			./src/termios/arrow_right.c	\
			./src/termios/arrow_up.c	\
			./src/termios/auto_completion.c	\
			./src/termios/backspace.c	\
			./src/termios/jimmy_word_arr.c	\
			./src/termios/modify_terminal.c	\
			./src/termios/new_getline_events.c	\
			./src/termios/new_getline.c	\
			./src/termios/parse_wods_completion.c \
			./src/termios/utilites.c \
			./src/termios/write_mid_string.c \
			./tests/tests.c				\
			./src/var.c	\
			./src/if.c	\

all:	$(TARGET)

$(TARGET):	$(LIB)
	$(CC) $(CFLAGS) $(SRC1)  -o $@ $(CPPFLAGS) -Llib/my -lmy -lncurses

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