##
## EPITECH PROJECT, 2020
## MAkefile
## File description:
##  cp the libmy.a into lib/, then cp the my.h into include/, then clean the temp files
##

RM	=	rm -f

CC	=	gcc

AR	=	ar

CFLAGS		=	-w -Wall -Wextra -Werror -g
CPPFLAGS	=	-Iinclude

SRC	=	$(wildcard lib/my/*.c)

OBJ	=	$(SRC:.c=.o)

LIB	=	lib/my/libmy.a

TARGET	=	mysh

SRC1	=	$(wildcard *.c)

all:	$(TARGET)

$(TARGET):	$(LIB)
	$(CC) $(CFLAGS) $(SRC1)  -o $@ $(CPPFLAGS) -Llib/my -lmy

$(LIB):	$(OBJ)
	$(AR) rsc $@ $(OBJ)

clean:
	$(RM) $(OBJ)
	$(RM) *.o
	$(RM) *~

fclean:	clean
	$(RM) $(LIB)
	$(RM) $(TARGET)

re:	fclean all