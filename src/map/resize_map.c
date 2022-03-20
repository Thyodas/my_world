/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** resize_map.c
*/

#include "myworld.h"
#include <stdlib.h>

void free_map(data_t *data);
void init_map_tiles(data_t *data, int map_x, int map_y);

void resize_map(data_t *data, int new_size)
{
    free_map(data);
    data->map.size = new_size;
    init_map_tiles(data, new_size, new_size);
}
