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

void rotate_right(sfVector3f **map);
void rotate_left(sfVector3f **map);
void zoom_in(data_t *data);
void zoom_out(data_t *data);

void rotate(sfEvent event, sfVector3f **map, int *recalc)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        rotate_right(map);
        *recalc = 1;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        rotate_left(map);
        *recalc = 1;
    }
}

void zoom(sfEvent event, data_t *data, int *recalc)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown) {
        zoom_out(data);
        *recalc = 1;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
        zoom_in(data);
        *recalc = 1;
    }
}

void check_event(data_t *data, int *recalc)
{
    sfVector3f **map = data->map.array_3d;
    sfEvent event = data->event;
    while (sfRenderWindow_pollEvent(data->window, &event) == sfTrue) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        rotate(event, map, recalc);
        zoom(event, data, recalc);
    }
}
