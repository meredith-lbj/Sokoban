/*
** EPITECH PROJECT, 2021
** get_map
** File description:
** No file there, just an epitech header example
*/

#include "my_sokoban.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void fill_map(char ***map, char const *str)
{
    int x = 0;
    int y = 0;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == '\n') {
            (*map)[x][y] = '\0';
            x++;
            y = 0;
        }
        else {
            (*map)[x][y] = str[i];
            y++;
        }
    }
}

char **alloc_mem(char *str, char **map)
{
    int x = 0;
    int word = 0;
    int line = line_count(str);
    map = malloc(sizeof(char *) * (line + 1));
    map[line] = NULL;
    for (int i = 0 ; str[i] != '\0' ; i++) {
        word++;
        if (str[i] == '\n') {
            map[x] = malloc(sizeof(char) * (word + 1));
            map[x][word] = '\0';
            x++;
            word = 0;
        }
    }
    fill_map(&map, str);
    return (map);
}

char **load_file_1d(char const *filepath, char **map)
{
    int	fd;
    char *str = NULL;
    struct stat fileStat;

    if ((fd = open(filepath, O_RDONLY)) != -1) {
        stat(filepath, &fileStat);
        str = malloc(sizeof(char) * (fileStat.st_size + 1));
        str[fileStat.st_size] = '\0';
        read(fd, str, fileStat.st_size);
        if (check_chr(str) == 1) {
            close(fd);
            exit(84);
        }
        map = alloc_mem(str, map);
        free(str);
        close(fd);
    }
    else {
        write(2, "Invalid file\n", 13);
        exit(84);
    }
    return (map);
}

char **get_map(char *filepath, char **map)
{
    map = load_file_1d(filepath, map);
    return (map);
}
