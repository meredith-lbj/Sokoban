/*
** EPITECH PROJECT, 2021
** check_screen
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"
#include <ncurses.h>

void check_screen(my_map_t *my_map)
{
    char str[] = "Enlarge the terminal\n";

    if (LINES < my_map->lines || COLS < my_map->cols) {
        clear();
        mvprintw(LINES / 2, (COLS - my_strlen(str)) / 2, str);
        refresh();
    }
}
