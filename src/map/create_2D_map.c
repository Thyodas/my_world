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

#define MAP_X 10
#define MAP_Y 10
#define M_PI 3.14159265358979323846

sfVector2f project_iso_point(float x, float y, float z, sfVector2f factors)
{
    sfVector2f vector;
    float angle_x = 35 * M_PI / 180;
    float angle_y = 25 * M_PI / 180;
    vector.x = (cos(angle_x) * x - cos(angle_x) * y) * factors.x;
    vector.y = (sin(angle_y) * y + sin(angle_y) * x - z) * factors.y;
    return vector;
}

void translate_map(sfVector2f **map_2d, sfVector3f **map_3d,
                    sfVector2f factors)
{
    sfVector2f center_tile;
    float rad_x = 35 * M_PI / 180;
    float rad_y = 25 * M_PI / 180;
    float c_x = map_3d[5][5].x;
    float c_y = map_3d[5][5].y;
    center_tile.x = (cos(rad_x) * c_x - (cos(rad_x) * c_y)) * factors.x;
    center_tile.y = (sin(rad_y) * c_y + sin(rad_y) * c_x) * factors.y;
    int offset_x = 930 - center_tile.x;
    int offset_y = 510 - center_tile.y;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map_2d[i][j].x += offset_x;
            map_2d[i][j].y += offset_y;
        }
    }
}

sfVector2f **create_2d_map(sfVector3f **map_3d, sfVector2f factors)
{
    sfVector2f **output = malloc(sizeof(sfVector2f *) * MAP_Y);
    for (int i = 0; i < MAP_Y; i++) {
        output[i] = malloc(sizeof(sfVector2f) * MAP_X);
        for (int j = 0; j < MAP_X; j++) {
            float x = map_3d[i][j].x;
            float y = map_3d[i][j].y;
            float z = map_3d[i][j].z;
            output[i][j] = project_iso_point(x, y, z, factors);
        }
    }
    translate_map(output, map_3d, factors);
    return output;
}
