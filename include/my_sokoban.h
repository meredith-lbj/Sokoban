/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** No file there, just an epitech header example
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_
#include <ncurses.h>
typedef struct my_player_s
{
    int x;
    int y;
    int x_reset;
    int y_reset;
}my_player_t;
typedef struct my_map_s
{
    int lose;
    int stock;
    int stock_p;
    int hole;
    int box;
    int y_max;
    int x_max;
    int lines;
    int cols;
    char **map;
    char **map_reset;
}my_map_t;
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_strcmp(char const *str1, char *str2);
int my_put_nbr(int nb);
int find_my_chr(char c, char *chr);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *str, char const *src);
int display_map(char **map);
int check_chr(char *str);
my_player_t *get_player(my_player_t *my_player, my_map_t *my_map);
my_map_t *get_move(my_map_t *my_map, my_player_t **my_player);
my_map_t *move_right(my_map_t *my_map, my_player_t **my_player);
my_map_t *move_left(my_map_t *my_map, my_player_t **my_player);
my_map_t *move_up(my_map_t *my_map, my_player_t **my_player);
my_map_t *move_down(my_map_t *my_map, my_player_t **my_player);
my_map_t *reset_map(my_map_t *my_map, my_player_t **my_player);
void check_screen(my_map_t *my_map);
void infos_map(my_map_t **my_map);
int line_count(char const *str);
char **get_map(char *filepath, char **map);
void print_helper();
void check_win(my_map_t *my_map);
void print_map(my_map_t *my_map);
void free_chaine(char **str);
#endif
