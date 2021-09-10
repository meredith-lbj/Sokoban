##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No file there, just an epitech header example
##

SRC	=	lib/my_putchar.c	\
		lib/my_putstr.c	\
		lib/my_strlen.c	\
		lib/my_getnbr.c	\
		lib/my_strcmp.c	\
		lib/my_strdup.c	\
		lib/my_strcpy.c	\
		lib/find_my_chr.c	\
		lib/my_put_nbr.c	\
		lib/line_count.c	\
		lib/infos_map.c	\
		lib/check_chr.c	\
		lib/print_map.c	\
		lib/get_move.c	\
		lib/move_right.c	\
		lib/move_left.c	\
		lib/move_up.c	\
		lib/move_down.c	\
		lib/get_player.c	\
		lib/reset_map.c	\
		lib/check_screen.c	\
		lib/display_map.c	\
		lib/get_map.c	\
		lib/check_win.c	\
		lib/print_helper.c	\
		lib/free_chaine.c

INCLUDE	=        -I include/

OBJ	=	$(SRC:.c=.o)

TARGET	=	libmy.a

CFLAGS =	-W -Wall -Wextra -g

all:	GCC

%.o:	%.c
	gcc $(INCLUDE) -g -c $< -o $@

libmy.a:	$(OBJ)
	ar rc $(TARGET) $(OBJ)

GCC:	fclean libmy.a
	gcc -o my_sokoban src/my_sokoban.c -L./ -lmy -I./include/ -lncurses

debug:	fclean libmy.a
	gcc -o my_sokoban src/my_sokoban.c -L./ -lmy -I./include/ -lncurses $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)
	rm -f ./my_sokoban

re:	fclean libmy.a

unit_tests:
	gcc -o unit_tests tests/test_bubble_sort_array.c src/pushswap.c -I./include/ -L./ -lmy -lcriterion --coverage

run_tests:	libmy.a unit_tests
	./unit_tests

.PHONY:	libmy.a GCC
