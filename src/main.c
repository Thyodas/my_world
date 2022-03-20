/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main.c
*/

#include "myworld.h"
#include <stdlib.h>

void main_loop(data_t *data);
void free_3d_map(sfVector3f **map_3d);
void load_textures(data_t *data);
sfRenderWindow *init_window(int x, int y);
void init_map_tiles(data_t *data, int map_x, int map_y);
sfVector2f project_iso_point(float x, float y, float z, sfVector2f factors);
void init_translation_point(data_t *data);
void load_buttons(data_t *data);
void load_backgrounds(data_t *data);
void load_states(data_t *data);
void load_tooltips(data_t *data);
void set_selected_tool(data_t *data, enum buttons_pos btn);
void save_map(data_t *data, char *name);
void sort_tiles(data_t *data);
void init_hover_circle(data_t *data);
int load_map(data_t *data, char *path);

int init_data(data_t *data, int argc, char **argv)
{
    data->map.is_tile_hovered = false;
    data->map.use_hover_circle = false;
    data->map.hovered_tile = NULL;
    data->recalc = true;
    load_textures(data);
    load_buttons(data);
    load_backgrounds(data);
    load_tooltips(data);
    set_selected_tool(data, BTN_BUCKET);
    if (argc == 1)
        init_map_tiles(data, data->map.size, data->map.size);
    else if (load_map(data, argv[1]) == 0)
        return 0;
    data->window = init_window(1920, 1080);
    init_hover_circle(data);
    data->map.factors = (sfVector2f){15, 15};
    data->selected_texture = data->textures.grass;
    sort_tiles(data);
    init_translation_point(data);
    return 1;
}

int main(int argc, char **argv)
{
    data_t data;
    data.map.size = 32;
    if (argc != 1 && argc != 2) {
        my_printf("Wrong number of arguments\n");
        return 84;
    }
    if (!init_data(&data, argc, argv))
        return 84;
    main_loop(&data);
    save_map(&data, "autosave");
    return 0;
}
