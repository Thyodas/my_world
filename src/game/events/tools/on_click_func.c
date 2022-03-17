/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** tool functions executed on click
*/

#include "myworld.h"

int tool_bucket(data_t *data, sfEvent event)
{
    data->map.tiles[data->map.hovered_tile.y][data->map.hovered_tile.x].texture
        = data->selected_texture;
    return 0;
}

int tool_size(data_t *data, sfEvent event)
{
    return 0;
}

int tool_pen_width(data_t *data, sfEvent event)
{
    return 0;
}

int tool_level(data_t *data, sfEvent event)
{
    data->map.tiles[data->map.hovered_tile.y][data->map.hovered_tile.x].coord_3d.z
        += 0.1;
    data->recalc = 1;
    return 0;
}

int tool_picker(data_t *data, sfEvent event)
{
    return 0;
}
