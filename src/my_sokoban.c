/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** No file there, just an epitech header exampel
*/

#include "my_sokoban.h"
#include <stdlib.h>
#include <ncurses.h>

int my_sokoban(char *filepath)
{
    my_player_t *my_player = NULL;
    my_map_t *my_map = NULL;
    char **map = NULL;

    initscr();
    noecho();
    my_map = (struct my_map_s *)malloc(sizeof(my_map_t));
    my_player = (struct my_player_s *)malloc(sizeof(my_player_t));
    my_map->lose = 0;
    my_map->stock_p = 0;
    my_map->map = get_map(filepath, map);
    my_map->map_reset = get_map(filepath, map);
    my_player = get_player(my_player, my_map);
    infos_map(&my_map);
    display_map(my_map->map);
    while (1) {
        check_screen(my_map);
        my_map = get_move(my_map, &my_player);
        display_map(my_map->map);
        check_win(my_map);
        refresh();
    }
    return (0);
}

int play(char *filepath)
{
    if (my_strcmp(filepath, "-h") == 0) {
        print_helper();
    }
    else {
        my_sokoban(filepath);
    }
    return (0);
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        play(argv[1]);
    }
    else {
        return (84);
    }
    return (0);
}
