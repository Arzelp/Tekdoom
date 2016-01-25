##
## Makefile for tekdoom in /home/alies/rendu/gfx_tekdoom
##
## Made by Arnaud Alies
## Login   <alies_a@epitech.net>
##
## Started on  Tue Jan 12 17:04:21 2016 Arnaud Alies
## Last update Mon Jan 25 14:36:51 2016 Arthur Josso
##

NAME    =       tekdoom

CC	=	gcc

LIB	=	./lib/

INC	=	./include/

CFLAGS	=	-I/home/${USER}/.froot/include \
		-L/home/${USER}/.froot/lib \
		-llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm \
		-I$(INC) \
		-W -Wall -Werror -ansi -pedantic \
		-lpthread -O3

SRC	=	./src/

ENGINE	=	./src/engine/

MAP	=	./src/map/

MY	=	./src/my/

DISP	=	./src/display/

CTRL	=	./src/control/

INIT	=	./src/init/

MOB	=	./src/mob/

SPRITE	=	./src/sprite/

DELETE	=	./src/delete/

SRCS	=	$(SRC)main.c \
		$(SRC)tekpixel.c \
		$(SRC)stretch.c \
		$(SRC)vecnorm.c \
		$(SRC)show_texture.c \
		$(INIT)load_bmp.c \
		$(INIT)init.c \
		$(MAP)gen.c \
		$(MAP)pos.c \
		$(MAP)map_check_pos.c \
		$(MAP)map_create_block.c \
		$(MAP)map_delete_block.c \
		$(MAP)map_change_block.c \
		$(MAP)texture.c \
		$(MAP)save_map.c \
		$(MAP)load_map.c \
		$(MAP)tnt.c \
		$(CTRL)control.c \
		$(CTRL)drawjauge.c \
		$(CTRL)fly.c \
		$(CTRL)jump.c \
		$(CTRL)move.c \
		$(DISP)arithmetic.c \
		$(DISP)find_k.c \
		$(DISP)display.c \
		$(DISP)test_axes.c \
		$(DISP)viseur.c \
		$(MOB)mob.c \
		$(MOB)test_mob.c \
		$(MOB)mob_loop.c \
		$(MOB)kill_boss.c \
		$(SPRITE)gun.c \
		$(DELETE)delete.c \
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
