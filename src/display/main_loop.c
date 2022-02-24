/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main_loop.c
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>

sfVector2f **create_2d_map(sfVector3f **map_3d);
void check_event(sfEvent event, sfRenderWindow *win, float **map, sfVector2f **map_2d);
int draw_2d_map(sfRenderWindow *win, sfVector2f **map_2d);

void main_loop(sfVector3f **map)
{
    sfVector2f **map_2d;
    sfVideoMode mode = {1920, 1080, 0};
    sfRenderWindow *win = sfRenderWindow_create(mode, "my_world", sfClose, NULL);
    sfEvent event;
    sfRenderWindow_setFramerateLimit(win, 500);
    while (sfRenderWindow_isOpen(win)) {
        map_2d = create_2d_map(map);
        sfRenderWindow_clear(win, sfBlack);
        check_event(event, win, map, map_2d);
        draw_2d_map(win, map_2d);
        sfRenderWindow_display(win);
    }
}