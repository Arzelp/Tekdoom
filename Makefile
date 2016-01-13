##
## Makefile for tekdoom in /home/alies/rendu/gfx_tekdoom
## 
## Made by Arnaud Alies
## Login   <alies_a@epitech.net>
## 
## Started on  Tue Jan 12 17:04:21 2016 Arnaud Alies
## Last update Wed Jan 13 18:01:34 2016 Arnaud Alies
##

NAME    =       tekdoom

CC	=	gcc

LIB	=	./lib/

INC	=	./include/

CFLAGS	=	-I/home/${USER}/.froot/include \
		-L/home/${USER}/.froot/lib \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
		-I$(INC) \
		-W -Wall -ansi -pedantic

SRC	=	./src/

ENGINE	=	./src/engine/

MAP	=	./src/map/

MY	=	./src/my/

SRCS	=	$(SRC)main.c \
		$(SRC)load_bmp.c \
		$(SRC)tekpixel.c \
		$(MAP)gen.c \
		$(MAP)print.c \
		$(MY)my_putchar.c \
		$(MY)my_putstr.c \
		$(MY)my_strcat.c \
		$(MY)my_strcpy.c \
		$(MY)my_strdup.c \
		$(MY)my_strlen.c \
		$(MY)my_str_to_nbr.c

OBJS	=	$(SRCS:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
