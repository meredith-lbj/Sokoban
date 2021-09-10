/*
** EPITECH PROJECT, 2021
** display_map
** File description:
** No file there, just an epitech header example
*/

#include <ncurses.h>
#include "my_sokoban.h"
#include <stdlib.h>
#include <stdio.h>

int display_map(char **map)
{
    int i = 0;
    int y = 0;

    clear();
    move(y++, 0);
    for (i = 0 ; map[i] != NULL ; i++) {
        printw(map[i]);
        move(y++, 0);
    }
    return (0);
}
