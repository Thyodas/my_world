/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** rotate.c
*/

#include "myworld.h"
#include "math.h"

float calc_dist(sfVector2f point1, sfVector2f point2);

void rotate_right(data_t *data)
{
    float cx = (data->map.tiles[MAP_Y - 1][MAP_X - 1].coord_3d.x
        + data->map.tiles[0][0].coord_3d.x) / 2;
    float cy = (data->map.tiles[MAP_Y - 1][MAP_X - 1].coord_3d.y
        + data->map.tiles[0][0].coord_3d.y) / 2;
    float angle = DEG_TO_RAD(1);
    for (int i = 0; i < MAP_Y; ++i) {
        for (int j = 0; j < MAP_X; ++j) {
            float x = data->map.tiles[i][j].coord_3d.x;
            float y = data->map.tiles[i][j].coord_3d.y;
            x -= cx;
            y -= cy;
            data->map.tiles[i][j].coord_3d.x = cos(angle) * x - sin(angle) * y
                + cx;
            data->map.tiles[i][j].coord_3d.y = cos(angle) * y + sin(angle) * x
                + cy;
        }
    }
}

void rotate_left(data_t *data)
{
    float cx = (data->map.tiles[MAP_Y - 1][MAP_X - 1].coord_3d.x
        + data->map.tiles[0][0].coord_3d.x) / 2;
    float cy = (data->map.tiles[MAP_Y - 1][MAP_X - 1].coord_3d.y
        + data->map.tiles[0][0].coord_3d.y) / 2;
    float angle = -DEG_TO_RAD(1);
    for (int i = 0; i < MAP_Y; ++i) {
        for (int j = 0; j < MAP_X; ++j) {
            float x = data->map.tiles[i][j].coord_3d.x;
            float y = data->map.tiles[i][j].coord_3d.y;
            x -= cx;
            y -= cy;
            data->map.tiles[i][j].coord_3d.x = cos(angle) * x - sin(angle) * y
                + cx;
            data->map.tiles[i][j].coord_3d.y = cos(angle) * y + sin(angle) * x
                + cy;
        }
    }
}
