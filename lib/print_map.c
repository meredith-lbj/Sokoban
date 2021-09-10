/*
** EPITECH PROJECT, 2021
** print_map
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"
#include <stdlib.h>

void print_map(my_map_t *my_map)
{
    for (int i = 0 ; my_map->map[i] != NULL ; i++) {
        my_putstr(my_map->map[i]);
        my_putchar('\n');
    }
}
