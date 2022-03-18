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
sfVector2f calculate_center_point(data_t *data);

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
        float result_x = data->map.factors.x + event.mouseWheelScroll.delta * 5;
        float result_y = data->map.factors.y + event.mouseWheelScroll.delta * 5;
        if (result_x > 0 && result_y > 0) {
            sfVector2f rel_pos_mouse = {data->pos_mouse.x
                - data->translation_point.x,
                data->pos_mouse.y - data->translation_point.y};
            sfVector2f new_rel_mouse_pos = {rel_pos_mouse.x
                / data->map.factors.x * result_x,
                rel_pos_mouse.y / data->map.factors.y * result_y};
            sfVector2f map_shift = {new_rel_mouse_pos.x - rel_pos_mouse.x,
                new_rel_mouse_pos.y - rel_pos_mouse.y};
            data->map.factors.x = result_x;
            data->map.factors.y = result_y;
            data->translation_point.x -= map_shift.x;
            data->translation_point.y -= map_shift.y;
            data->recalc = true;
        }
    }
}

void tool_event(data_t *data, sfEvent event)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && check_interface(data))
        return;
    data->selected_tool_func(data, event);
}

void mouse_event(data_t *data, sfEvent event)
{
    return;
    /*if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft
        || !sfFloatRect_contains(&(sfFloatRect){0, 0, 1920, 1080},
        data->pos_mouse.x, data->pos_mouse.y)) {
        data->mouse_released = true;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) || !data->mouse_released) {
        data->mouse_released = false;
    }*/
}

void check_event(data_t *data)
{
    sfEvent event = data->event;
    while (sfRenderWindow_pollEvent(data->window, &event) == sfTrue) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        rotate(data, event);
        zoom(data, event);
        mouse_event(data, event);
        tool_event(data, event);
    }
}
