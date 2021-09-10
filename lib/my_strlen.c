/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"

int my_strlen(char const *str)
{
    int i;
    int x = 0;

    for (i = 0 ; str[i] != '\0' ; i++) {
            x++;
    }
    return (x);
}
