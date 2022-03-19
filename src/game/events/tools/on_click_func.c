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
    data->map.hovered_tile->texture = data->selected_texture;
    return 0;
}

int tool_panning(data_t *data, sfEvent event)
{
    static sfVector2i old_mouse_pos = {-1, -1};
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        old_mouse_pos = data->pos_mouse;
        return (0);
    }
    data->translation_point.x += data->pos_mouse.x - old_mouse_pos.x;
    data->translation_point.y += data->pos_mouse.y - old_mouse_pos.y;
    data->recalc = true;
    old_mouse_pos = data->pos_mouse;
    return 0;
}

int tool_precision(data_t *data, sfEvent event)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft) || !data->map.is_tile_hovered)
        return (0);
    return 0;
}

int tool_level(data_t *data, sfEvent event)
{
    if (!data->map.is_tile_hovered)
        return (0);
    int x = data->map.hovered_tile->index_x;
    int y = data->map.hovered_tile->index_y;
    sfColor color = data->map.tiles[x][y].color;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        data->map.tiles[x][y].coord_3d.z += 0.1;
        data->map.tiles[x + 1][y].coord_3d.z += 0.1;
        data->map.tiles[x + 1][y + 1].coord_3d.z += 0.1;
        data->map.tiles[x][y + 1].coord_3d.z += 0.1;
        data->recalc = 1;
    } else if (sfMouse_isButtonPressed(sfMouseRight)) {
        data->map.tiles[x][y].coord_3d.z -= 0.1;
        data->map.tiles[x + 1][y].coord_3d.z -= 0.1;
        data->map.tiles[x + 1][y + 1].coord_3d.z -= 0.1;
        data->map.tiles[x][y + 1].coord_3d.z -= 0.1;
        data->recalc = 1;
    }
    return 0;
}

int tool_picker(data_t *data, sfEvent event)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft) || !data->map.is_tile_hovered)
        return (0);
    data->selected_texture = data->map.hovered_tile->texture;
    return 0;
}
