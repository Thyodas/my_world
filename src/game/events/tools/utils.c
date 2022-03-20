/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** click tools utils
*/

#include "tool_precision.h"
#include <math.h>

void tool_precision_modify(data_t *data, tool_precision_t tool)
{
    int x = tool.tile->index_x;
    int y = tool.tile->index_y;
    float new_y = data->pos_mouse.y - data->translation_point.y
        + tool.dist_tile;
    float calc = sin(DEG_TO_RAD(25)) * data->map.tiles[x][y].coord_3d.y
        + sin(DEG_TO_RAD(25)) * data->map.tiles[x][y].coord_3d.x
        - new_y / data->map.factors.y;
    if (tool.is_tile) {
        data->map.tiles[x][y].coord_3d.z = calc;
        data->map.tiles[x + 1][y].coord_3d.z = calc + tool.delta_z[0];
        data->map.tiles[x + 1][y + 1].coord_3d.z = calc + tool.delta_z[1];
        data->map.tiles[x][y + 1].coord_3d.z = calc + tool.delta_z[2];
        data->recalc = 1;
    } else if (tool.is_corner) {
        data->map.tiles[x][y].coord_3d.z = calc;
        data->recalc = 1;
    }
}

void set_precision_struct(data_t *data, tool_precision_t *tool)
{
    tool->tile = data->map.hovered_tile;
    int x = tool->tile->index_x;
    int y = tool->tile->index_y;
    tool->is_tile = data->map.is_tile_hovered;
    tool->is_corner = data->map.show_hover_circle;
    tool->dist_tile = data->map.tiles[x][y].coord_2d.y - data->pos_mouse.y;
    tool->delta_z[0] = data->map.tiles[x + 1][y].coord_3d.z
        - data->map.tiles[x][y].coord_3d.z;
    tool->delta_z[1] = data->map.tiles[x + 1][y + 1].coord_3d.z
        - data->map.tiles[x][y].coord_3d.z;
    tool->delta_z[2] = data->map.tiles[x][y + 1].coord_3d.z
        - data->map.tiles[x][y].coord_3d.z;
}
