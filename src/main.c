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
sfVector2f project_iso_point(float x, float y, float z, sfVector2f factors);
void init_center_point(data_t *data);
void load_buttons(data_t *data);

void init_data(data_t *data)
{
    data->window = init_window(1920, 1080);
    data->map.is_tile_hovered = false;
    load_textures(data);
    load_buttons(data);
    init_map_tiles(data, MAP_X, MAP_Y);
    data->map.factors = (sfVector2f){15, 15};
    init_center_point(data);
}

int main(int argc, char **argv)
{
    data_t data;
    init_data(&data);
    main_loop(data);
    return 0;
}
