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

#define M_PI 3.14159265358979323846

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
            map[1][1].z -= 1;
            map[3][3].z -= 1;
            map[8][8].z -= 1;
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
            map[1][1].z += 1;
            map[3][3].z += 1;
            map[8][8].z += 1;
        }
        if (data.event.type == sfEvtKeyPressed && data.event.key.code ==
        sfKeyRight) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    map[i][j].x = cos(angle) * map[i][j].x - sin(angle) * map[i][j].y;
                    map[i][j].y = cos(angle) * map[i][j].y + sin(angle) * map[i][j].x;
                }
            }
        }
        if (data.event.type == sfEvtKeyPressed && data.event.key.code ==
        sfKeyLeft) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    map[i][j].x = cos(-angle) * map[i][j].x - sin(-angle) * map[i][j].y;
                    map[i][j].y = cos(-angle) * map[i][j].y + sin(-angle) * map[i][j].x;
                }
            }
        }
    }
}
