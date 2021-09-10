/*
** EPITECH PROJECT, 2021
** get_player
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"
#include <stdlib.h>
#include <unistd.h>

void check_playerx(my_player_t *my_player)
{
    if (my_player->x == 0) {
        write(2, "Invalid map.\n", 13);
        exit(84);
    }
}

my_player_t *get_player(my_player_t *my_player, my_map_t *my_map)
{
    my_player->x = 0;

    for (int i = 0 ; my_map->map[i] != NULL ; i++) {
        for (int j = 0 ; my_map->map[i][j] != '\0' ; j++) {
            if (my_map->map[i][j] == 'P') {
                my_player->x = i;
                my_player->y = j;
                my_player->x_reset = i;
                my_player->y_reset = j;
            }
        }
    }
    check_playerx(my_player);
    return (my_player);
}
