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
    data->map.draw_order = malloc(sizeof(tile_t *) * (map_x * map_y));
    int pos = 0;
    for (int i = 0 ; i < map_y ; ++i) {
        data->map.tiles[i] = malloc(sizeof(tile_t) * (map_x));
        for (int j = 0 ; j < map_x ; ++j) {
            data->map.tiles[i][j].coord_3d.x = i;
            data->map.tiles[i][j].coord_3d.y = j;
            data->map.tiles[i][j].index_x = i;
            data->map.tiles[i][j].index_y = j;
            data->map.tiles[i][j].coord_3d.z = 0;
            data->map.tiles[i][j].texture = data->textures.grass;
            data->map.draw_order[pos++] = &data->map.tiles[i][j];
        }
    }
}

void init_center_point(data_t *data)
{
    sfVector2f center_point = calculate_center_point(data);
    data->pos_board_center = center_point;
    center_point.x = 930 - center_point.x;
    center_point.y = 510 - center_point.y;
    data->translation_point.x = center_point.x;
    data->translation_point.y = center_point.y;
}
