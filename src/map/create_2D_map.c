/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** create_2D_map.c
*/

#include <math.h>
#include <stdlib.h>
#include "myworld.h"

float calc_dist(sfVector2f point1, sfVector2f point2);
void init_center_point(data_t *data);

sfVector2f project_iso_point(float x, float y, float z, sfVector2f factors)
{
    sfVector2f vector;
    float angle_x = DEG_TO_RAD(35);
    float angle_y = DEG_TO_RAD(25);
    vector.x = (cos(angle_x) * x - cos(angle_x) * y) * factors.x;
    vector.y = (sin(angle_y) * y + sin(angle_y) * x - z) * factors.y;
    return vector;
}

sfVector2f project_3D_to_2D(sfVector3f coords_3D, sfVector2f factors, int i,
                            int j)
{
    float x  = coords_3D.x;
    float y = coords_3D.y;
    float z = coords_3D.z;
    sfVector2f coords_2D = project_iso_point(x, y, z, factors);
    return coords_2D;
}

void translate_map_to_point(data_t *data)
{
    for (int i = 0; i < MAP_Y; ++i) {
        for (int j = 0; j < MAP_X; ++j) {
            data->map.tiles[i][j].coord_2d.x += data->pos_center.x;
            data->map.tiles[i][j].coord_2d.y += data->pos_center.y;
        }
    }
}

sfVector2f calculate_center_point(data_t *data)
{
    float c_x = (data->map.tiles[0][0].coord_3d.x
                 + data->map.tiles[MAP_Y - 1][MAP_X - 1].coord_3d.x) / 2;
    float c_y = (data->map.tiles[MAP_X - 1][0].coord_3d.y
                 + data->map.tiles[0][MAP_Y - 1].coord_3d.y) / 2;
    return (project_iso_point(c_x, c_y, 0, data->map.factors));
}

void calculate_2d_tiles(data_t *data)
{
    init_center_point(data);
    for (int i = 0; i < MAP_Y; ++i) {
        for (int j = 0; j < MAP_X; ++j)
            data->map.tiles[i][j].coord_2d = project_3D_to_2D(data->map
                .tiles[i][j].coord_3d, data->map.factors, i, j);
    }
    translate_map_to_point(data);
}