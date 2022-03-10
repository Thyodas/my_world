/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main_loop.c
*/

#include "myworld.h"

sfVector2f **create_2d_map(sfVector3f **map_3d, data_t data);
void check_event(data_t *data, int *recalc);
int draw_2d_map(data_t data);
sfRenderWindow *init_window(int x, int y);
void load_sand_texture(data_t *data);
void load_checker_texture(data_t *data);
void print_map(sfVector2f **map);
float calc_dist(sfVector2f point1, sfVector2f point2);
void load_hover_texture(data_t *data);

void init_data(data_t *data)
{
    data->window = init_window(1920, 1080);
    load_sand_texture(data);
    load_checker_texture(data);
    load_hover_texture(data);
    data->map.factors = (sfVector2f){100, 75};
}

void main_loop(data_t data)
{
    init_data(&data);
    int recalc = 1;
    while (sfRenderWindow_isOpen(data.window)) {
        data.pos_mouse = sfMouse_getPositionRenderWindow(data.window);
        if (recalc == 1) {
            data.map.array_2d = create_2d_map(data.map.array_3d, data);
            recalc = 0;
        }
        sfRenderWindow_clear(data.window, sfBlue);
        check_event(&data, &recalc);
        draw_2d_map(data);
        sfRenderWindow_display(data.window);
    }
}