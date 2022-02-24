/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** check_events.c
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846

void check_event(sfEvent event, sfRenderWindow *win, sfVector3f **map, sfVector2f **map_2d)
{
    while (sfRenderWindow_pollEvent(win, &event) == sfTrue) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {

        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    map[i][j].x = cos(0.2 * M_PI / 180) * map[i][j].x - sin(0.2 * M_PI / 180) * map[i][j].y;
                    map[i][j].y = cos(0.2 * M_PI / 180) * map[i][j].y + sin(0.2 * M_PI / 180) * map[i][j].x;
                }
            }
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    map[i][j].x = cos(-0.2 * M_PI / 180) * map[i][j].x - sin(-0.2 * M_PI / 180) * map[i][j].y;
                    map[i][j].y = cos(-0.2 * M_PI / 180) * map[i][j].y + sin(-0.2 * M_PI / 180) * map[i][j].x;
                }
            }
        }
    }
}
