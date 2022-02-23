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

void check_event(sfEvent event, sfRenderWindow *win, float **map)
{
    while (sfRenderWindow_pollEvent(win, &event) == sfTrue) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
            map[3][3]++;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
            map[3][3]--;
        }
    }
}
