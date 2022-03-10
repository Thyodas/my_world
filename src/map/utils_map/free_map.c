/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** free_map.c
*/

#include <stdlib.h>
#include "myworld.h"

void free_2d_map(sfVector2f **map_2d)
{
    for (int i = 0; i < MAP_Y; ++i)
        free(map_2d[i]);
    free(map_2d);
}