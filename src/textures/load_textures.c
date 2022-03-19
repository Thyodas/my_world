/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** load_textures.c
*/

#include "myworld.h"

static void load_texture_data(texture_data_t *texture, char *path, int size_x,
int size_y)
{
    texture->texture = sfTexture_createFromFile(path, NULL);
    texture->size = (sfVector2u){size_x, size_y};
    texture->loaded = 1;
}

void load_textures(data_t *data)
{
    load_texture_data(&data->textures.checker, "img/check.jpg", 2048, 2048);
    load_texture_data(&data->textures.sand, "img/sand.jpg", 800, 709);
    load_texture_data(&data->ui.textures.bucket, "img/bucket.png", 62, 62);
    load_texture_data(&data->ui.textures.panning, "img/panning.png", 62, 62);
    load_texture_data(&data->ui.textures.precision,
        "img/precision.png", 62, 62);
    load_texture_data(&data->ui.textures.level, "img/level.png", 62, 62);
    load_texture_data(&data->ui.textures.picker, "img/picker.png", 62, 62);
    load_texture_data(&data->ui.textures.tools_bg, "img/tools_bg.png",
        135, 476);
    load_texture_data(&data->ui.textures.ui_bg, "img/ui_bg.png",
        1920, 1080);
}
