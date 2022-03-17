/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** utils for tool buttons
*/

#include "myworld.h"

int tool_bucket(data_t *data, sfEvent event);
int tool_size(data_t *data, sfEvent event);
int tool_pen_width(data_t *data, sfEvent event);
int tool_level(data_t *data, sfEvent event);
int tool_picker(data_t *data, sfEvent event);

int (*tool_function[])(data_t *data, sfEvent event) = {
    tool_bucket,
    tool_size,
    tool_pen_width,
    tool_level,
    tool_picker
};

void set_idle_tool(data_t *data, enum buttons_pos btn)
{
    sfSprite_setColor(data->ui.buttons[btn].sprite,
        (sfColor){255, 255, 255, 255});
    data->ui.buttons[btn].state = IDLE;
}

void set_selected_tool(data_t *data, enum buttons_pos btn)
{
    sfSprite_setColor(data->ui.buttons[btn].sprite,
        (sfColor){182, 237, 255, 255});
    data->ui.buttons[btn].state = SELECTED;
    data->selected_tool_func = tool_function[btn];
}

void set_hovered_tool(data_t *data, enum buttons_pos btn)
{
    sfSprite_setColor(data->ui.buttons[btn].sprite,
        (sfColor){227, 248, 250, 255});
    data->ui.buttons[btn].state = HOVERED;
}

void reset_hovered_tool(data_t *data)
{
    for (int i = 0; i <= BTN_PICKER; ++i) {
        if (data->ui.buttons[i].state == HOVERED)
            set_idle_tool(data, i);
    }
    data->ui.tooltip.is_visible = false;
}

void reset_selected_tool(data_t *data)
{
    for (int i = 0; i <= BTN_PICKER; ++i)
        set_idle_tool(data, i);
}
