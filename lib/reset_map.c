/*
** EPITECH PROJECT, 2021
** reset_map
** File description:
** No file there, just an epitech header example
*/

#include <stdlib.h>
#include "my_sokoban.h"

my_map_t *reset_map(my_map_t *my_map, my_player_t **my_player)
{
    free_chaine(my_map->map);
    my_map->map = malloc(sizeof(char *) * (my_map->x_max));
    my_map->map[my_map->x_max] = NULL;
    for (int i = 0 ; my_map->map_reset[i] != NULL ; i++) {
        my_map->map[i] = my_strdup(my_map->map[i], my_map->map_reset[i]);
    }
    (*my_player)->x = (*my_player)->x_reset;
    (*my_player)->y = (*my_player)->y_reset;
    return (my_map);
}
