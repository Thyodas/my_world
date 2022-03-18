/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** states
*/

#include "myworld.h"
#include "my.h"

void load_states(data_t *data)
{
    data->ui.selected_sprite = sfSprite_create();
    sfSprite_setTexture(data->ui.selected_sprite, data->ui.textures.selected.texture, true);
    return;
}