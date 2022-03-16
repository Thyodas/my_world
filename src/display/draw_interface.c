/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** draw_interface
*/

#include "myworld.h"
#include "my.h"

static void draw_buttons(data_t *data)
{
    for (int i = 0 ; i < NB_BUTTON; ++i) {
        sfRenderWindow_drawSprite(data->window, data->ui.buttons[i].sprite, NULL);
    }
}

static void draw_backgrounds(data_t *data)
{
    return;
}

void draw_interface(data_t *data)
{
    draw_buttons(data);
}