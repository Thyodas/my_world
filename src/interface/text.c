/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** text
*/

#include "myworld.h"

void load_map_size_text(data_t *data)
{
    data->interface.map_size_text = sfText_create();
    sfText_setFont(data->interface.map_size_text,
        sfText_getFont(data->interface.tooltip.text));
    sfText_setColor(data->interface.map_size_text, sfWhite);
    sfText_setPosition(data->interface.map_size_text, (sfVector2f){92, 119});
    sfText_setString(data->interface.map_size_text, "32");
}
