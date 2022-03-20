/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** load_textures.c
*/

#include "myworld.h"

static void load_texture_data(texture_data_t *texture, char *path,
                                sfVector2u size, int id)
{
    texture->texture = sfTexture_createFromFile(path, NULL);
    texture->size = size;
    texture->loaded = 1;
    texture->txt = id;
}

static void load_tile_textures(data_t *data)
{
    load_texture_data(&data->textures.checker,
        "img/tiles/check.jpg", (sfVector2u){2048, 2048}, -1);
    load_texture_data(&data->textures.sand, "img/tiles/sand.png",
        (sfVector2u){16, 16}, SAND);
    load_texture_data(&data->textures.grass, "img/tiles/grass.png",
        (sfVector2u){16, 16}, GRASS);
    load_texture_data(&data->textures.dirt, "img/tiles/dirt.png",
        (sfVector2u){16, 16}, DIRT);
    load_texture_data(&data->textures.stone, "img/tiles/stone.png",
        (sfVector2u){16, 16}, STONE);
    load_texture_data(&data->interface.textures.grass_btn,
        "img/tiles/grass_btn.png", (sfVector2u){68, 68}, -1);
    load_texture_data(&data->interface.textures.dirt_btn,
        "img/tiles/dirt_btn.png", (sfVector2u){68, 68}, -1);
    load_texture_data(&data->interface.textures.sand_btn,
        "img/tiles/sand_btn.png", (sfVector2u){68, 68}, -1);
    load_texture_data(&data->interface.textures.stone_btn,
        "img/tiles/stone_btn.png", (sfVector2u){68, 68}, -1);
}

static void load_tool_textures(data_t *data)
{
    load_texture_data(&data->interface.textures.bucket,
        "img/tools/bucket.png", (sfVector2u){62, 62}, -1);
    load_texture_data(&data->interface.textures.panning,
        "img/tools/panning.png", (sfVector2u){62, 62}, -1);
    load_texture_data(&data->interface.textures.precision,
        "img/tools/precision.png", (sfVector2u){62, 62}, -1);
    load_texture_data(&data->interface.textures.level, "img/tools/level.png",
        (sfVector2u){62, 62}, -1);
    load_texture_data(&data->interface.textures.picker,
        "img/tools/picker.png", (sfVector2u){62, 62}, -1);
    load_texture_data(&data->interface.textures.minus_btn,
        "img/tools/minus_btn.png", (sfVector2u){62, 62}, -1);
    load_texture_data(&data->interface.textures.plus_btn,
        "img/tools/plus_btn.png", (sfVector2u){62, 62}, -1);
}

static void load_background_textures(data_t *data)
{
    load_texture_data(&data->interface.textures.tools_bg,
        "img/backgrounds/interface_background.png",
        (sfVector2u){135, 476}, -1);
    load_texture_data(&data->interface.textures.ui_bg,
        "img/backgrounds/ui_bg3_auto_x1.jpg", (sfVector2u){1920, 1080}, -1);
}

void load_textures(data_t *data)
{
    load_tile_textures(data);
    load_tool_textures(data);
    load_background_textures(data);
}
