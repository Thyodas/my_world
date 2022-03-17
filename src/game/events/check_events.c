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
bool check_interface(data_t *data);

void rotate(data_t *data, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        rotate_right(data);
        data->recalc = true;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft) {
        rotate_left(data);
        data->recalc = true;
    }
}

void zoom(data_t *data, sfEvent event)
{
    if (event.type == sfEvtMouseWheelScrolled) {
        float result_x = data->map.factors.x + event.mouseWheelScroll.delta;
        float result_y = data->map.factors.y + event.mouseWheelScroll.delta;
        if (result_x > 0 && result_y > 0) {
            data->map.factors.x = result_x;
            data->map.factors.y = result_y;
            data->pos_center.x = data->pos_mouse.x - data->pos_board_center.x;
            data->pos_center.y = data->pos_mouse.y - data->pos_board_center.x;
            data->recalc = true;
        }
    }
}

void tool_event(data_t *data, sfEvent event)
{
    if (data->map.is_tile_hovered) {
        int y = data->map.hovered_tile.y;
        int x = data->map.hovered_tile.x;
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button ==
        sfMouseRight) {
            data->map.tiles[y][x].coord_3d.z += 1;
            /*data->map.tiles[y + 1][x].coord_3d.z -= 1;
            data->map.tiles[y][x + 1].coord_3d.z -= 1;
            data->map.tiles[y + 1][x + 1].coord_3d.z -= 1;*/
            data->recalc = true;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
            data->map.tiles[y][x].texture = data->textures.sand;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyW) {
            data->map.tiles[y][x].texture = data->textures.checker;
        }
    }
}

void mouse_event(data_t *data, sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) || !data->mouse_released) {
        data->mouse_released = false;
        if (!check_interface(data))
            data->selected_tool_func(data, event);
    }
    if (event.type == sfEvtMouseButtonReleased && event.mouseButton.button ==
        sfMouseLeft) {
        data->mouse_released = true;
    }
}

void check_event(data_t *data)
{
    sfEvent event = data->event;
    while (sfRenderWindow_pollEvent(data->window, &event) == sfTrue) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        rotate(data, event);
        zoom(data, event);
        tool_event(data, event);
        mouse_event(data, event);
    }
}
