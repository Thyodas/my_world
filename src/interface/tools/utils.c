/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** utils for tool buttons
*/

#include "myworld.h"

int tool_bucket(data_t *data);
int tool_panning(data_t *data);
int tool_precision(data_t *data);
int tool_level(data_t *data);
int tool_picker(data_t *data);

int (*const TOOL_FUNCTION[])(data_t *data) = {
    tool_bucket,
    tool_panning,
    tool_precision,
    tool_level,
    tool_picker
};

void set_idle_tool(data_t *data, enum buttons_pos btn)
{
    sfSprite_setColor(data->interface.buttons[btn].sprite,
        (sfColor){255, 255, 255, 255});
    data->interface.buttons[btn].state = IDLE;
}

void set_selected_tool(data_t *data, enum buttons_pos btn)
{
    sfSprite_setColor(data->interface.buttons[btn].sprite,
        (sfColor){150, 150, 150, 255});
    data->interface.buttons[btn].state = SELECTED;
    data->selected_tool_func = TOOL_FUNCTION[btn];
}

void set_hovered_tool(data_t *data, enum buttons_pos btn)
{
    sfSprite_setColor(data->interface.buttons[btn].sprite,
        (sfColor){200, 200, 200, 255});
    data->interface.buttons[btn].state = HOVERED;
}

void reset_hovered_tool(data_t *data)
{
    for (int i = 0; i < NB_BUTTON; ++i) {
        if (data->interface.buttons[i].state == HOVERED)
            set_idle_tool(data, i);
    }
    data->interface.tooltip.is_visible = false;
}

void reset_selected_tool(data_t *data)
{
    for (int i = 0; i <= BTN_PICKER; ++i)
        set_idle_tool(data, i);
}
