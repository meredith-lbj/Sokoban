/*
** EPITECH PROJECT, 2021
** get_move
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"
#include <stdlib.h>
#include <ncurses.h>

my_map_t *get_move(my_map_t *my_map, my_player_t **my_player)
{
    int c;

    keypad(stdscr, TRUE);
    c = wgetch(stdscr);
    switch(c) {
    case KEY_UP:
        my_map = move_up(my_map, my_player);
        refresh();
        break;
    case KEY_DOWN:
        my_map = move_down(my_map, my_player);
        refresh();
        break;
    case KEY_LEFT:
        my_map = move_left(my_map, my_player);
        refresh();
        break;
    case KEY_RIGHT:
        my_map = move_right(my_map, my_player);
        refresh();
        break;
    case 32:
        clear();
        display_map(my_map->map_reset);
        my_map = reset_map(my_map, my_player);
        refresh();
        return (my_map);
    case 33:
        endwin();
        print_map(my_map);
        free_chaine(my_map->map_reset);
        free_chaine(my_map->map);
        free(my_map);
        exit(0);
    default:
        refresh();
        return (my_map);
    }
    return (my_map);
}
