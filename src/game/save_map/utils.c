/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** utils
*/

#include "myworld.h"

void implement_texture(data_t *data, int id, int i, int j)
{
    if (id == SAND)
        data->map.tiles[i][j].texture = data->textures.sand;
    if (id == GRASS)
        data->map.tiles[i][j].texture = data->textures.grass;
    if (id == DIRT)
        data->map.tiles[i][j].texture = data->textures.dirt;
    if (id == STONE)
        data->map.tiles[i][j].texture = data->textures.stone;
}
