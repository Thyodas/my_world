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

void resize_map(data_t *data)
{
    free_map(data);
    data->map.size = data->map.new_map_size;
    init_map_tiles(data, data->map.size, data->map.size);
    data->recalc = true;
    data->map.new_map_size = -1;
}
