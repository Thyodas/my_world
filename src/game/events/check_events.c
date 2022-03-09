/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** check_events.c
*/

#include "my.h"
#include "myworld.h"
#include <math.h>
#include <stdlib.h>

void check_event(data_t data)
{
    float angle = 1 * M_PI / 180;
    sfVector3f **map = data.map.array_3d;
    while (sfRenderWindow_pollEvent(data.window, &data.event) == sfTrue) {
        if (data.event.type == sfEvtClosed)
            sfRenderWindow_close(data.window);
        if (data.event.type == sfEvtKeyPressed && data.event.key.code ==
        sfKeyDown) {
            //for (int i = 0; i < 10; i++) {
            //    for (int j = 0; j  < 10; j++) {
            //        map[i][j].x = (1 - (1 - cos(angle)) / 2) * map[i][j].x - ((1 - cos(angle)) / 2) * map[i][j].y - ((sin(angle)) / sqrt(2)) * map[i][j].z;
            //        map[i][j].y = (1 - (1 - cos(angle)) / 2) * map[i][j].y - ((1 - cos(angle)) / 2) * map[i][j].x - ((sin(angle)) / sqrt(2)) * map[i][j].z;
            //        map[i][j].z = (sin(angle) / sqrt(2)) * map[i][j].x + (sin(angle) / sqrt(2)) * map[i][j].y + cos(angle) * map[i][j].z;
            //    }
            //}
            data.map.factors.x -= 5;
            data.map.factors.y -= 5;
        }
        if (data.event.type == sfEvtKeyPressed && data.event.key.code ==
        sfKeyUp) {
            //for (int i = 0; i < 10; i++) {
            //    for (int j = 0; j  < 10; j++) {
            //        map[i][j].x = (1 - (1 - cos(-angle)) / 2) * map[i][j].x - ((1 - cos(-angle)) / 2) * map[i][j].y - ((sin(-angle)) / sqrt(2)) * map[i][j].z;
            //        map[i][j].y = (1 - (1 - cos(-angle)) / 2) * map[i][j].y - ((1 - cos(-angle)) / 2) * map[i][j].x - ((sin(-angle)) / sqrt(2)) * map[i][j].z;
            //        map[i][j].z = (sin(-angle) / sqrt(2)) * map[i][j].x + (sin(-angle) / sqrt(2)) * map[i][j].y + cos(-angle) * map[i][j].z;
            //    }
            //}
            data.map.factors.x += 5;
            data.map.factors.y += 5;
        }
        if (data.event.type == sfEvtKeyPressed && data.event.key.code ==
        sfKeyRight) {
            for (int i = 0; i < MAP_Y; i++) {
                for (int j = 0; j < MAP_X; j++) {
                    map[i][j].x = cos(angle) * map[i][j].x - sin(angle) * map[i][j].y;
                    map[i][j].y = cos(angle) * map[i][j].y + sin(angle) * map[i][j].x;
                }
            }
        }
        if (data.event.type == sfEvtKeyPressed && data.event.key.code ==
        sfKeyLeft) {
            for (int i = 0; i < MAP_Y; i++) {
                for (int j = 0; j < MAP_X; j++) {
                    map[i][j].x = cos(-angle) * map[i][j].x - sin(-angle) * map[i][j].y;
                    map[i][j].y = cos(-angle) * map[i][j].y + sin(-angle) * map[i][j].x;
                }
            }
        }
    }
}
