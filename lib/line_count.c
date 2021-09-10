/*
** EPITECH PROJECT, 2021
** line_count
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"

int line_count(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            count++;
        }
        i++;
    }
    return (count);
}
