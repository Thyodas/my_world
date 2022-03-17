/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** check_interface.c
*/

#include "myworld.h"
#include "my.h"

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