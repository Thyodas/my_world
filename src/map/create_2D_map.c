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

#define MAP_X 6
#define MAP_Y 6
#define M_PI 3.14159265358979323846

sfVector2f project_iso_point(float x, float y, float z)
{
    sfVector2f vector;
    float angle_x = 35 * M_PI / 180;
    float angle_y = 25 * M_PI / 180;
    vector.x = (cos(angle_x) * x - cos(angle_x) * y) * 100 + 800;
    vector.y = (sin(angle_x) * y + sin(angle_y) * x - z) * 50 + 300;
    return vector;
}

sfVector2f **create_2d_map(sfVector3f **map_3d)
{
    sfVector2f **output = malloc(sizeof(sfVector2f *) * MAP_Y);
    for (int i = 0; i < MAP_Y; i++) {
        output[i] = malloc(sizeof(sfVector2f) * MAP_X);
        for (int j = 0; j < MAP_X; j++) {
            output[i][j] = project_iso_point(map_3d[i][j].x, map_3d[i][j].y, map_3d[i][j].z);
        }
    }
    return output;
}
