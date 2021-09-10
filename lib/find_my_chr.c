/*
** EPITECH PROJECT, 2020
** my_strchr
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"

int find_my_chr(char c, char *chr)
{
    for (int i = 0 ; chr[i] != '\0' ; i++) {
        if (c == chr[i]) {
            return (0);
        }
    }
    return (1);
}
