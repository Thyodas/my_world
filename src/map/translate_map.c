/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** translate_map.c
*/

#include "myworld.h"

void translate_map(data_t *data, sfVector2f vector)
{
    for (int i = 0; i < MAP_Y; ++i) {
        for (int j = 0; j < MAP_X; ++j) {
            data->map.tiles[i][j].coord_3d.x += vector.x;
            data->map.tiles[i][j].coord_3d.y += vector.y;
        }
    }
}