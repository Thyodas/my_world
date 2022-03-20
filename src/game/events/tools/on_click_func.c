/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** tool functions executed on click
*/

#include "tool_precision.h"

void tool_precision_modify(data_t *data, tool_precision_t tool);
void set_precision_struct(data_t *data, tool_precision_t *tool);

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

float calc_newz(data_t *data, int i, int j, int new_y)
{
    int x = data->map.tiles[i][j].coord_3d.x;
    int y = data->map.tiles[i][j].coord_3d.y;
    float angle_x = DEG_TO_RAD(35);
    float angle_y = DEG_TO_RAD(25);
    return (sin(angle_y) * y + sin(angle_y) * x
        - data->pos_mouse.y / data->map.factors.y);
}

int tool_precision(data_t *data, sfEvent event)
{
    static tool_precision_t tool;
    if (data->map.hovered_tile == NULL)
        return;
    if (!sfMouse_isButtonPressed(sfMouseLeft) || !data->map.hovered_tile) {
        set_precision_struct(data, &tool);
        return (0);
    }
    tool_precision_modify(data, tool);
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
