/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main_loop.c
*/

#include "my.h"
#include "myworld.h"
#include <math.h>
#include <stdlib.h>

sfVector2f **create_2d_map(sfVector3f **map_3d, sfVector2f factors);
void check_event(data_t data);
int draw_2d_map(data_t data);

void main_loop(data_t data)
{
    //map[0][1].z = 2;
    sfVideoMode mode = {1920, 1080, 0};
    data.window = sfRenderWindow_create(mode, "my_world", sfClose, NULL);
    sfVector2f factors = {75, 25};
    sfRenderWindow_setFramerateLimit(data.window, 500);
    data.textures.sand.texture = sfTexture_createFromFile("img/sand.jpg", NULL);
    data.textures.sand.size = (sfVector2u){800, 709};
    data.textures.checker.texture = sfTexture_createFromFile("img/check.jpg",
                                                          NULL);
    data.textures.checker.size = (sfVector2u){2048, 2048};
    while (sfRenderWindow_isOpen(data.window)) {
        data.map.array_2d = create_2d_map(data.map.array_3d, factors);
        sfRenderWindow_clear(data.window, sfBlue);
        check_event(data);
        draw_2d_map(data);
        sfRenderWindow_display(data.window);
    }
}