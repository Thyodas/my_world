/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** check_events.c
*/

#include "myworld.h"
#include "my.h"

void rotate_right(data_t *data);
void rotate_left(data_t *data);

void rotate(sfEvent event, data_t *data, int *recalc)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        rotate_right(data);
        *recalc = 1;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        rotate_left(data);
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
    if (data->map.is_tile_hovered) {
        int y = data->map.hovered_tile.y;
        int x = data->map.hovered_tile.x;
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button ==
        sfMouseLeft) {
            data->map.tiles[y][x].coord_3d.z += 1;
            data->map.tiles[y + 1][x].coord_3d.z += 1;
            data->map.tiles[y][x + 1].coord_3d.z += 1;
            data->map.tiles[y + 1][x + 1].coord_3d.z += 1;
            *recalc = 1;
        }
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button ==
        sfMouseRight) {
            data->map.tiles[y][x].coord_3d.z -= 1;
            data->map.tiles[y + 1][x].coord_3d.z -= 1;
            data->map.tiles[y][x + 1].coord_3d.z -= 1;
            data->map.tiles[y + 1][x + 1].coord_3d.z -= 1;
            *recalc = 1;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
            data->map.tiles[y][x].texture = data->textures.sand;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyW) {
            data->map.tiles[y][x].texture = data->textures.checker;
        }
    }
}

void check_event(data_t *data, int *recalc)
{
    sfEvent event = data->event;
    while (sfRenderWindow_pollEvent(data->window, &event) == sfTrue) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        rotate(event, data, recalc);
        zoom(event, data, recalc);
        tool_event(event, data, recalc);
    }
}
