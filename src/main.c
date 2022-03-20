/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main.c
*/

#include "myworld.h"
#include <stdlib.h>
#include "my.h"

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
void load_map_size_text(data_t *data);

static void loading_data(data_t *data)
{
    load_textures(data);
    load_buttons(data);
    load_backgrounds(data);
    load_tooltips(data);
    load_map_size_text(data);
}

int init_data(data_t *data, int argc, char **argv)
{
    data->map.new_map_size = -1;
    data->map.is_tile_hovered = false;
    data->map.use_hover_circle = false;
    data->map.hovered_tile = NULL;
    data->map.size_step = 2;
    data->recalc = true;
    loading_data(data);
    if (argc == 1)
        init_map_tiles(data, data->map.size, data->map.size);
    else if (load_map(data, argv[1]) == 0)
        return 0;
    set_selected_tool(data, BTN_BUCKET);
    data->window = init_window(1920, 1080);
    init_hover_circle(data);
    data->map.factors = (sfVector2f){15, 15};
    data->selected_texture = data->textures.grass;
    sort_tiles(data);
    init_translation_point(data);
    return 1;
}

void display_usage_second(void)
{
    my_printf("Allows the user to level the map, either up");
    my_printf("(with left click) or down (with right click)\n");
    my_printf("\tPICKER (key : C)\t\t");
    my_printf("Allows the user to pick the default texture");
    my_printf("directly on the map\n\n");
}

void display_usage(void)
{
    my_printf("USAGE\n\t./my_world [save_file]\n\n");
    my_printf("DESCRPTION\n\tsave_file\t\tOptional, path to a file");
    my_printf("representing a saved map\n\nUSER INPUT\n\t");
    my_printf("Right/Left click\tAllows the user to modify the map");
    my_printf(" based on the tool selected\n\tMouse wheel\t");
    my_printf("\tAllows the user to zoom in/out of the map\n\t");
    my_printf("Left/Right arrow\tAllows the user to rotate horizontally");
    my_printf(" the map\n\nTOOLS\n\t");
    my_printf("BUCKET (key : B)\t\tAllows the user to change ");
    my_printf("the texture of the tile\n\t\t\t\t\t(the user can choose");
    my_printf(" the default texture via a box in the bottom left corner)");
    my_printf("\n\tPANNING (key : M)\t\t");
    my_printf("Allows the user to move with the mouse");
    my_printf("\n\tPRECISION (key : P)\t\t");
    my_printf("Allows the user to level the terrain more");
    my_printf("precisely (by either picking a corner of a tile or a tile)\n");
    my_printf("\tLEVEL (key : L)\t\t\t");
    display_usage_second();
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        display_usage();
        return 0;
    }
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
