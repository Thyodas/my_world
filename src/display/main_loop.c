/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main_loop.c
*/

#include "myworld.h"
#include <stdlib.h>

sfVector2f **create_2d_map(sfVector3f **map_3d, data_t data);
void calculate_2d_tiles(data_t *data);
void check_event(data_t *data, int *recalc);
int draw_2d_map(data_t *data);
void print_map(sfVector2f **map);
float calc_dist(sfVector2f point1, sfVector2f point2);
void draw_interface(data_t *data);
int check_interface_hovering(data_t *data);

void main_loop(data_t data)
{
    int recalc = 1;
    while (sfRenderWindow_isOpen(data.window)) {
        data.pos_mouse = sfMouse_getPositionRenderWindow(data.window);
        if (recalc == 1) {
            calculate_2d_tiles(&data);
            recalc = 0;
        }
        sfRenderWindow_clear(data.window, (sfColor){52, 192, 235, 30});
        check_interface_hovering(&data);
        check_event(&data, &recalc);
        draw_2d_map(&data);
        draw_interface(&data);
        sfRenderWindow_display(data.window);
    }
}
