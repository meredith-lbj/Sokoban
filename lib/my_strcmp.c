/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"

int my_strcmp(char const *str1, char *str2)
{
    int i = 0;

    if (my_strlen(str1) != my_strlen(str2)) {
        return (1);
    }
    while (str2[i] != '\0') {
        if (str2[i] == str1[i]) {
            i++;
        }
        else {
            return (1);
        }
    }
    return (0);
}
