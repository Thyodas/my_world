/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main.c
*/

#include "myworld.h"

void main_loop(data_t data);
sfVector3f **init_map_3d(int map_x, int map_y);
void free_3d_map(sfVector3f **map_3d);
void load_textures(data_t *data);
sfRenderWindow *init_window(int x, int y);
void init_map_tiles(data_t *data, int map_x, int map_y);

void init_data(data_t *data)
{
    data->window = init_window(1920, 1080);
    data->map.is_tile_hovered = false;
    load_textures(data);
    init_map_tiles(data, MAP_X, MAP_Y);
    data->map.factors = (sfVector2f){15, 15};
}

int main(int argc, char **argv)
{
    data_t data;
    init_data(&data);
    data.map.array_3d = init_map_3d(MAP_X, MAP_Y);
    main_loop(data);
    free_3d_map(data.map.array_3d);
    return 0;
}
