/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** check_events.c
*/

#include "myworld.h"
#include "my.h"

void rotate_right(sfVector3f **map);
void rotate_left(sfVector3f **map);

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
    if (event.type == sfEvtMouseWheelScrolled) {
        float result_x = data->map.factors.x + event.mouseWheelScroll.delta;
        float result_y = data->map.factors.y + event.mouseWheelScroll.delta;
        if (result_x > 0 && result_y > 0) {
            data->map.factors.x = result_x;
            data->map.factors.y = result_y;
            *recalc = 1;
        }
    }
}

void tool_event(sfEvent event, data_t *data, int *recalc)
{
    if (event.type == sfEvtMouseButtonPressed && data->map.is_tile_hovered) {
        if (event.mouseButton.button == sfMouseLeft) {
            int i = data->map.hovered_tile.x;
            int j = data->map.hovered_tile.y;
            data->map.array_3d[i][j].z += 1;
            data->map.array_3d[i + 1][j].z += 1;
            data->map.array_3d[i][j + 1].z += 1;
            data->map.array_3d[i + 1][j + 1].z += 1;
            *recalc = 1;
        }
        if (event.mouseButton.button == sfMouseRight) {
            int i = data->map.hovered_tile.x;
            int j = data->map.hovered_tile.y;
            data->map.array_3d[i][j].z -= 1;
            data->map.array_3d[i + 1][j].z -= 1;
            data->map.array_3d[i][j + 1].z -= 1;
            data->map.array_3d[i + 1][j + 1].z -= 1;
            *recalc = 1;
        }
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
        tool_event(event, data, recalc);
    }
}
