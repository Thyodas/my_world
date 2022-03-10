/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** rotate.c
*/

#include "myworld.h"
#include "math.h"

void rotate_right(sfVector3f **map)
{
    float angle = DEG_TO_RAD(1);
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            float x  = map[i][j].x;
            float y = map[i][j].y;
            map[i][j].x = cos(angle) * x - sin(angle) * y;
            map[i][j].y = cos(angle) * y + sin(angle) * x;
        }
    }
}

void rotate_left(sfVector3f **map)
{
    float angle = DEG_TO_RAD(1);
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            float x = map[i][j].x;
            float y = map[i][j].y;
            map[i][j].x = cos(-angle) * x - sin(-angle) * y;
            map[i][j].y = cos(-angle) * y + sin(-angle) * x;
        }
    }
}