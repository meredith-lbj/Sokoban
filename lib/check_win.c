/*
** EPITECH PROJECT, 2021
** check_win
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"
#include <stdlib.h>

void check_win(my_map_t *my_map)
{
    if (my_map->hole == 0 && my_map->stock_p == 0) {
        endwin();
        print_map(my_map);
        free_chaine(my_map->map_reset);
        free_chaine(my_map->map);
        free(my_map);
        exit(0);
    }
    if (my_map->lose == my_map->box) {
        endwin();
        print_map(my_map);
        free_chaine(my_map->map_reset);
        free_chaine(my_map->map);
        free(my_map);
        exit(1);
    }
}
