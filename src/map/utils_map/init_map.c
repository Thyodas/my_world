/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** init_map.c
*/

#include <stdlib.h>
#include "myworld.h"

sfVector2f calculate_center_point(data_t *data);

void init_map_tiles(data_t *data, int map_x, int map_y)
{
    data->map.tiles = malloc(sizeof(tile_t *) * (map_y));
    for (int i = 0 ; i < map_y ; ++i) {
        data->map.tiles[i] = malloc(sizeof(tile_t) * (map_x));
        for (int j = 0 ; j < map_x ; ++j) {
            data->map.tiles[i][j].coord_3d.x = i;
            data->map.tiles[i][j].coord_3d.y = j;
            data->map.tiles[i][j].coord_3d.z = 0;
            data->map.tiles[i][j].texture = data->textures.checker;
        }
    }
}

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

void init_center_point(data_t *data)
{
    sfVector2f center_point = calculate_center_point(data);
    data->pos_board_center = center_point;
    center_point.x = 930 - center_point.x;
    center_point.y = 510 - center_point.y;
    data->pos_center.x = center_point.x;
    data->pos_center.y = center_point.y;
}
