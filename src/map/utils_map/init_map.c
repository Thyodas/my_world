/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** init_map.c
*/

#include <stdlib.h>
#include "myworld.h"

sfVector3f **init_map_3d(int map_x, int map_y)
{
    sfVector3f **output = malloc(sizeof(sfVector3f *) * (map_y));
    for (int i = 0; i < map_y; ++i) {
        output[i] = malloc(sizeof(sfVector3f) * (map_x));
        for (int j = 0; j < map_x; ++j) {
            output[i][j].x = i;
            output[i][j].y = j;
            output[i][j].z = 0;
        }
    }
    return output;
}
