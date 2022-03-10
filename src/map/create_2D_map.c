/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** create_2D_map.c
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>
#include "myworld.h"

float calc_dist(sfVector2f point1, sfVector2f point2);

sfVector2f project_iso_point(float x, float y, float z, sfVector2f factors)
{
    sfVector2f vector;
    float angle_x = DEG_TO_RAD(35);
    float angle_y = DEG_TO_RAD(25);
    vector.x = (cos(angle_x) * x - cos(angle_x) * y) * factors.x;
    vector.y = (sin(angle_y) * y + sin(angle_y) * x - z) * factors.y;
    return vector;
}

void translate_map(sfVector2f **map_2d, sfVector3f **map_3d,
                    sfVector2f factors)
{
    float c_x = (map_3d[0][0].x + map_3d[MAP_Y - 1][MAP_X - 1].x) / 2;
    float c_y = (map_3d[MAP_X - 1][0].y + map_3d[0][MAP_Y - 1].y) / 2;
    sfVector2f center_point = project_iso_point(c_x, c_y, 0, factors);
    int offset_x = 930 - center_point.x;
    int offset_y = 510 - center_point.y;
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            map_2d[i][j].x += offset_x;
            map_2d[i][j].y += offset_y;
        }
    }
}

sfVector2f project_3D_to_2D(sfVector3f coords_3D, sfVector2f factors)
{
    float x  = coords_3D.x;
    float y = coords_3D.y;
    float z = coords_3D.z;
    sfVector2f coords_2D = project_iso_point(x, y, z, factors);
    return coords_2D;
}

sfVector2f **create_2d_map(sfVector3f **map_3d, data_t data)
{
    sfVector2f **output = malloc(sizeof(sfVector2f *) * MAP_Y);
    for (int i = 0; i < MAP_Y; i++) {
        output[i] = malloc(sizeof(sfVector2f) * MAP_X);
        for (int j = 0; j < MAP_X; j++)
            output[i][j] = project_3D_to_2D(map_3d[i][j], data.map.factors);
    }
    translate_map(output, map_3d, data.map.factors);
    return output;
}
