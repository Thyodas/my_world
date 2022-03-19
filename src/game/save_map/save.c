/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** save.c
*/

#include "myworld.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

void save_map(data_t *data, char *name)
{
    char *str = malloc(sizeof(char) * 10);
    my_strcpy(str, ".legends/");
    my_strcat(str, name);
    int fd = open(str, O_RDWR | O_CREAT, 777);
    my_fprintf(fd, "%d\n", data->map.size);
    for (int i = 0; i < data->map.size; ++i) {
        for (int j = 0; j < data->map.size; ++j) {
            float x = data->map.tiles[i][j].coord_3d.x;
            float y = data->map.tiles[i][j].coord_3d.y;
            float z = data->map.tiles[i][j].coord_3d.z;
            int txt = data->map.tiles[i][j].texture.txt;
            my_fprintf(fd, "%.2f %.2f %.2f %d\n", x, y, z, txt);
        }
    }
}