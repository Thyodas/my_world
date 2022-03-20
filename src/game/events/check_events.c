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
void sort_tiles(data_t *data);
void set_selected_tool(data_t *data, enum buttons_pos btn);
int button_bucket(data_t *data);
int button_panning(data_t *data);
int button_precision(data_t *data);
int button_level(data_t *data);
int button_picker(data_t *data);

void rotate(data_t *data, sfEvent event)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyRight) {
        rotate_right(data);
        sort_tiles(data);
        data->recalc = true;
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyLeft) {
        rotate_left(data);
        sort_tiles(data);
        data->recalc = true;
    }
}

void zoom(data_t *data, sfEvent event)
{
    if (event.type == sfEvtMouseWheelScrolled) {
        float delta = event.mouseWheelScroll.delta;
        float result_x = data->map.factors.x + delta * 5;
        float result_y = data->map.factors.y + delta * 5;
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

int tool_shortcut(data_t *data, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        switch (event.key.code) {
            case sfKeyB:
                return (button_bucket(data));
            case sfKeyM:
                return (button_panning(data));
            case sfKeyP:
                return (button_precision(data));
            case sfKeyL:
                return (button_level(data));
            case sfKeyC:
                return (button_picker(data));
            default:
                break;
        }
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
        tool_shortcut(data, event);
        tool_event(data, event);
    }
}
