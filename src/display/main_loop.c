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

sfVector2f **create_2d_map(sfVector3f **map_3d, sfVector2f angles, sfVector2f factors);
void check_event(sfEvent event, sfRenderWindow *win, sfVector3f **map);
int draw_2d_map(sfRenderWindow *win, sfVector2f **map_2d, sfTexture *text);

void main_loop(sfVector3f **map)
{
    //map[0][1].z = 2;
    sfVector2f **map_2d;
    sfVideoMode mode = {1920, 1080, 0};
    sfRenderWindow *win = sfRenderWindow_create(mode, "my_world", sfClose, NULL);
    sfEvent event;
    sfVector2f angles = {35, 25};
    sfVector2f factors = {75, 25};
    sfRenderWindow_setFramerateLimit(win, 500);
    sfTexture *sand = sfTexture_createFromFile("img/check.jpg", NULL);
    sfRenderStates state;
    state.texture = sand;
    state.blendMode = sfBlendNone;
    state.transform = sfTransform_Identity;
    state.shader = NULL;
    while (sfRenderWindow_isOpen(win)) {
        map_2d = create_2d_map(map, angles, factors);
        sfRenderWindow_clear(win, sfBlue);
        check_event(event, win, map);
        draw_2d_map(win, map_2d, sand);
        sfRenderWindow_display(win);
    }
}