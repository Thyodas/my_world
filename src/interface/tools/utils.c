/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** utils for tool buttons
*/

#include "myworld.h"

void reset_selected_tool(data_t *data)
{
    for (int i = 0; i <= BTN_PICKER; ++i) {
        data->ui.buttons[i].state = IDLE;
        sfSprite_setColor(data->ui.buttons[i].sprite,
            (sfColor){255, 255, 255, 255});
    }
}

void set_selected_tool(data_t *data, enum buttons_pos btn)
{
    // TODO: Hover color (sfColor){227, 248, 250, 255}
    sfSprite_setColor(data->ui.buttons[btn].sprite,
        (sfColor){182, 237, 255, 255});
    data->ui.buttons[btn].state = SELECTED;
}
