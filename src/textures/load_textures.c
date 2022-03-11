/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** load_textures.c
*/

#include "myworld.h"

void load_sand_texture(data_t *data)
{
    data->textures.sand.texture = sfTexture_createFromFile("img/sand.jpg",
                                                            NULL);
    data->textures.sand.size = (sfVector2u){800, 709};
    data->textures.sand.loaded = 1;
}

void load_checker_texture(data_t *data)
{
    data->textures.checker.texture = sfTexture_createFromFile("img/check.jpg",
                                                            NULL);
    data->textures.checker.size = (sfVector2u){2048, 2048};
    data->textures.checker.loaded = 1;
}

void load_hover_texture(data_t *data)
{
    data->textures.hover.texture = sfTexture_createFromFile("img/hover.png",
                                                                NULL);
    data->textures.hover.size = (sfVector2u){2048, 2048};
    data->textures.hover.loaded = 1;
}
