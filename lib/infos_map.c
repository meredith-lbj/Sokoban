/*
** EPITECH PROJECT, 2021
** infos_map
** File description:
** No file there, just an epictech header example
*/

#include "my_sokoban.h"
#include <stdlib.h>
#include <unistd.h>

void check_value(my_map_t **my_map)
{
    if ((*my_map)->hole != (*my_map)->box) {
        write(2, "Invalid map.\n", 13);
        exit (84);
    }
}

void get_hole(my_map_t **my_map)
{
    (*my_map)->hole = 0;
    for (int i = 0 ; (*my_map)->map[i] != NULL ; i++) {
        for (int j = 0 ; (*my_map)->map[i][j] != '\0' ; j++) {
            if ((*my_map)->map[i][j] == 'O') {
                (*my_map)->hole += 1;
	    }
        }
    }
    check_value(my_map);
}

void get_box(my_map_t **my_map)
{
    (*my_map)->box = 0;
    for (int i = 0 ; (*my_map)->map[i] != NULL ; i++) {
        for (int j = 0 ; (*my_map)->map[i][j] != '\0' ; j++) {
            if ((*my_map)->map[i][j] == 'X') {
                (*my_map)->box += 1;
            }
        }
    }
    get_hole(my_map);
}

void infos_map(my_map_t **my_map)
{
    int i;
    int columns = my_strlen((*my_map)->map[0]);

    for (i = 1 ; (*my_map)->map[i] != NULL ; i++) {
        if (columns < my_strlen((*my_map)->map[i])) {
            columns = my_strlen((*my_map)->map[i]);
        }
    }
    (*my_map)->x_max = i;
    (*my_map)->y_max = columns;
    (*my_map)->lines = i + 1;
    (*my_map)->cols = columns + 1;
    get_box(my_map);
}
