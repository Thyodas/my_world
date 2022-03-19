/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** sort
*/

#include "my.h"
#include "myworld.h"

sfVector2f project_iso_point(float x, float y, float z, sfVector2f factors);

static bool cmp_tile(data_t *data, tile_t *tile1, tile_t *tile2)
{
    return (tile1->coord_2d_flat.y < tile2->coord_2d_flat.y);
}

static void swap_tile(data_t *data, int pos1, int pos2)
{
    tile_t *temp;

    if (cmp_tile(data, data->map.draw_order[pos1],
        data->map.draw_order[pos2])) {
        temp = data->map.draw_order[pos1];
        data->map.draw_order[pos1] = data->map.draw_order[pos2];
        data->map.draw_order[pos2] = temp;
    }
}

void sort_tiles(data_t *data)
{
    for (int i = 0; i < data->map.size * data->map.size - 1; ++i) {
        data->map.draw_order[i]->coord_2d_flat = project_iso_point(
            data->map.draw_order[i]->coord_3d.x,
            data->map.draw_order[i]->coord_3d.y, 0, data->map.factors);
    }
    for (int i = data->map.size * data->map.size - 1 ; i > 0 ; i--) {
        for (int j = 0 ; j < i - 1 ; j++) {
            swap_tile(data, j + 1, j);
        }
    }
}
