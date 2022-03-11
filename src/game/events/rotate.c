/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** rotate.c
*/

#include "myworld.h"
#include "math.h"

void rotate_right(data_t *data)
{
    float angle = DEG_TO_RAD(1);
    for (int i = 0; i < MAP_Y; ++i) {
        for (int j = 0; j < MAP_X; ++j) {
            float x  = data->map.tiles[i][j].coord_3d.x;
            float y = data->map.tiles[i][j].coord_3d.y;
            data->map.tiles[i][j].coord_3d.x = cos(angle) * x - sin(angle) * y;
            data->map.tiles[i][j].coord_3d.y = cos(angle) * y + sin(angle) * x;
        }
    }
}

void rotate_left(data_t *data)
{
    float angle = DEG_TO_RAD(1);
    for (int i = 0; i < MAP_Y; ++i) {
        for (int j = 0; j < MAP_X; ++j) {
            float x  = data->map.tiles[i][j].coord_3d.x;
            float y = data->map.tiles[i][j].coord_3d.y;
            data->map.tiles[i][j].coord_3d.x = cos(-angle) * x - sin(-angle)
            * y;
            data->map.tiles[i][j].coord_3d.y = cos(-angle) * y + sin(-angle)
            * x;
        }
    }
}
