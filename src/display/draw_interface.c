/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** draw_interface
*/

#include "myworld.h"
#include "my.h"

static void draw_backgrounds(data_t *data)
{
    for (int i = 0 ; i < NB_BACKGROUND; ++i) {
        sfRenderWindow_drawSprite(data->window,
        data->interface.backgrounds[i].sprite, NULL);
    }
}

static void draw_tooltips(data_t *data)
{
    if (data->interface.tooltip.is_visible) {
        sfRenderWindow_drawSprite(data->window,
            data->interface.tooltip.background.sprite, NULL);
        sfRenderWindow_drawText(data->window,
                                data->interface.tooltip.text, NULL);
    }
}

static void draw_buttons(data_t *data)
{
    for (int i = 0 ; i < NB_BUTTON; ++i) {
        sfRenderWindow_drawSprite(data->window,
                                data->interface.buttons[i].sprite, NULL);
    }
}

void draw_interface(data_t *data)
{
    draw_backgrounds(data);
    draw_buttons(data);
    draw_tooltips(data);
}
