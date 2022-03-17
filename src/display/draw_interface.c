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
        sfRenderWindow_drawSprite(data->window, data->ui.backgrounds[i].sprite, 
            NULL);
    }
}

static void draw_buttons(data_t *data)
{
    for (int i = 0 ; i < NB_BUTTON; ++i) {
        /*if (data->ui.buttons[i].state == SELECTED) {
            sfSprite_setColor(data->ui.buttons[i].sprite, (sfColor){100, 100, 100, 255});
            sfRenderStates state = {
                sfBlendAlpha,
                sfSprite_getTransform(data->ui.buttons[i].sprite),
                data->ui.textures.selected.texture,
                NULL
            };
            sfRenderWindow_drawSprite(data->window, data->ui.selected_sprite, 
                &state);
        } else*/
        sfRenderWindow_drawSprite(data->window, data->ui.buttons[i].sprite, 
            NULL);
    }
}

void draw_interface(data_t *data)
{
    draw_backgrounds(data);
    draw_buttons(data);
}