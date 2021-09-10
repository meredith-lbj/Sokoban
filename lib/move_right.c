/*
** EPITECH PROJECT, 2021
** move_right
** File description:
** No file there, just an epitech header
*/

#include "my_sokoban.h"
#include <ncurses.h>
#include <stdlib.h>

my_map_t *stuck_box(my_map_t *my_map, my_player_t **my_player)
{
    if (my_map->map[(*my_player)->x][(*my_player)->y + 3] == '#' && my_map->map[(*my_player)->x - 1][(*my_player)->y + 2] == '#') {
        my_map->lose += 1;
    }
    else if(my_map->map[(*my_player)->x][(*my_player)->y + 3] == '#' && my_map->map[(*my_player)->x + 1][(*my_player)->y + 2] == '#') {
        my_map->lose += 1;
    }
    return (my_map);
}

my_map_t *move_right(my_map_t *my_map, my_player_t **my_player)
{
    if (my_map->map[(*my_player)->x][(*my_player)->y + 1] == ' ') {
        my_map->map[(*my_player)->x][(*my_player)->y + 1] = 'P';
        my_map->map[(*my_player)->x][(*my_player)->y] = ' ';
        if (my_map->map_reset[(*my_player)->x][(*my_player)->y] == 'O') {
            my_map->map[(*my_player)->x][(*my_player)->y] = 'O';
            my_map->stock_p -= 1;
            my_map->hole += 1;
        }
        (*my_player)->y = (*my_player)->y + 1;
    }
    else if (my_map->map[(*my_player)->x][(*my_player)->y + 1] == 'O') {
        my_map->map[(*my_player)->x][(*my_player)->y + 1] = 'P';
        my_map->map[(*my_player)->x][(*my_player)->y] = ' ';
        if (my_map->map_reset[(*my_player)->x][(*my_player)->y] == 'O')	{
            my_map->map[(*my_player)->x][(*my_player)->y] = 'O';
            my_map->stock_p -= 1;
            my_map->hole += 1;
	}
        my_map->hole -= 1;
        my_map->stock_p += 1;
        (*my_player)->y = (*my_player)->y + 1;
    }
    else if (my_map->map[(*my_player)->x][(*my_player)->y + 1] == 'X') {
        if (my_map->map[(*my_player)->x][(*my_player)->y + 2] == ' ') {
            my_map->map[(*my_player)->x][(*my_player)->y + 2] = 'X';
            my_map->map[(*my_player)->x][(*my_player)->y + 1] = 'P';
            my_map->map[(*my_player)->x][(*my_player)->y] = ' ';
            my_map = stuck_box(my_map, my_player);
            if (my_map->map_reset[(*my_player)->x][(*my_player)->y + 1] == 'O') {
                my_map->stock -= 1;
                my_map->stock_p += 1;
            }
            if (my_map->map_reset[(*my_player)->x][(*my_player)->y] == 'O') {
                my_map->map[(*my_player)->x][(*my_player)->y] = 'O';
                my_map->stock_p -= 1;
                my_map->hole += 1;
            }
            (*my_player)->y = (*my_player)->y + 1;
        }
        else if (my_map->map[(*my_player)->x][(*my_player)->y + 2] == 'O') {
            my_map->map[(*my_player)->x][(*my_player)->y + 2] = 'X';
            my_map->map[(*my_player)->x][(*my_player)->y + 1] = 'P';
            my_map->map[(*my_player)->x][(*my_player)->y] = ' ';
            if (my_map->map_reset[(*my_player)->x][(*my_player)->y] == 'O') {
                my_map->map[(*my_player)->x][(*my_player)->y] = 'O';
                my_map->hole += 1;
                my_map->stock_p -= 1;
            }
            my_map->hole -= 1;
            my_map->stock += 1;
            (*my_player)->y = (*my_player)->y + 1;
        }
    }
    return (my_map);
}
