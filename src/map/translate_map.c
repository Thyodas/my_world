/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** translate_map.c
*/

#include "myworld.h"

void translate_map_to_point(data_t *data)
{
    for (int i = 0; i < data->map.size; ++i) {
        for (int j = 0; j < data->map.size; ++j) {
            data->map.tiles[i][j].coord_2d.x += data->translation_point.x;
            data->map.tiles[i][j].coord_2d.y += data->translation_point.y;
        }
    }
}
