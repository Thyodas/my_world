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

static int check_if_char_valid(char c)
{
    if (c == '.' || c == '-' || c == '\n' || c == ' ')
        return 1;
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int check_line(char *line)
{
    for (int i = 0; line[i] != '\0'; ++i) {
        if (!check_if_char_valid(line[i]))
            return 0;
    }
    return 1;
}
