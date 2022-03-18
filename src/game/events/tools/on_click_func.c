/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** tool functions executed on click
*/

#include "myworld.h"

int tool_bucket(data_t *data, sfEvent event)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft) || !data->map.is_tile_hovered)
        return (0);
    data->map.tiles[data->map.hovered_tile.y][data->map.hovered_tile.x].texture
        = data->selected_texture;
    return 0;
}

int tool_size(data_t *data, sfEvent event)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return (0);
    static bool mouse_set = false;
    static sfVector2i old_mouse_pos = {-1, -1};
    if (event.type == sfEvtMouseButtonPressed
        && event.mouseButton.button == sfMouseLeft) {
        old_mouse_pos = data->pos_mouse;
        mouse_set = true;
    }
    data->translation_point.x += data->pos_mouse.x - old_mouse_pos.x;
    data->translation_point.y += data->pos_mouse.y - old_mouse_pos.y;
    data->recalc = true;
    old_mouse_pos = data->pos_mouse;
    return 0;
}

int tool_pen_width(data_t *data, sfEvent event)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft) || !data->map.is_tile_hovered)
        return (0);
    return 0;
}

int tool_level(data_t *data, sfEvent event)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft) || !data->map.is_tile_hovered)
        return (0);
    data->map.tiles[data->map.hovered_tile.y]
        [data->map.hovered_tile.x].coord_3d.z += 0.1;
    data->recalc = 1;
    return 0;
}

int tool_picker(data_t *data, sfEvent event)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft) || !data->map.is_tile_hovered)
        return (0);
    data->selected_texture = data->map.tiles[data->map.hovered_tile.y]
        [data->map.hovered_tile.x].texture;
    return 0;
}
