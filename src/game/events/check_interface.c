/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** check_interface.c
*/

#include "myworld.h"
#include "my.h"

void set_hovered_tool(data_t *data, enum buttons_pos btn);
void reset_selected_tool(data_t *data);

static int check_buttons(data_t *data)
{
    for (int i = 0; i < NB_BUTTON; ++i) {
        sfFloatRect rect = sfSprite_getGlobalBounds(data->ui.buttons[i].sprite);
        if (sfFloatRect_contains(&rect, data->pos_mouse.x, data->pos_mouse.y)) {
            data->ui.buttons[i].on_click(data);
            return true;
        }
    }
    return false;
}

int check_interface(data_t *data)
{
    if (check_buttons(data))
        return true;
}

int check_interface_hovering(data_t *data)
{
    reset_selected_tool(data);
    for (int i = 0; i < NB_BUTTON; ++i) {
        sfFloatRect rect = sfSprite_getGlobalBounds(data->ui.buttons[i].sprite);
        if (sfFloatRect_contains(&rect, data->pos_mouse.x, data->pos_mouse.y)) {
            set_hovered_tool(data, i);
            return true;
        }
    }
    return false;
}
