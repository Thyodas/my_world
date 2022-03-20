/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** free_map.c
*/

#include "myworld.h"
#include <stdlib.h>

void free_map(data_t *data)
{
    for (int i = 0; i < data->map.size; ++i)
        free(data->map.tiles[i]);
    free(data->map.tiles);
    free(data->map.draw_order);
}