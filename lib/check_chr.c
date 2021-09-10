/*
** EPITECH PROJECT, 2021
** check_chr
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"
#include <unistd.h>
#include <stdlib.h>

int check_chr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        switch(str[i]) {
        case ' ':
            i++;
            break;
        case '\n':
            i++;
            break;
        case '#':
            i++;
            break;
        case 'X':
            i++;
            break;
        case 'O':
            i++;
            break;
        case 'P':
            i++;
            break;
        default:
            free(str);
            write(2, "Invalid map\n", 12);
            return (1);
        }
    }
    return (0);
}
