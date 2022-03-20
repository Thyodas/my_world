/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** tooltips
*/

#include "myworld.h"

void set_tooltip_pos(data_t *data, float x, float y)
{
    sfText_setPosition(data->interface.tooltip.text, (sfVector2f){x + 10, y + 10});
    sfSprite_setPosition(data->interface.tooltip.background.sprite,
        (sfVector2f){x, y});
}

void set_tooltip_text(data_t *data, char *text)
{
    sfText_setString(data->interface.tooltip.text, text);
    sfFloatRect text_rect = sfText_getGlobalBounds(data->interface.tooltip.text);
    sfFloatRect bg_rect = sfSprite_getGlobalBounds(
        data->interface.tooltip.background.sprite);
    sfVector2f bg_scale =
    sfSprite_getScale(data->interface.tooltip.background.sprite);
    sfVector2f new_scale =
    {(text_rect.width + 25) * bg_scale.x / bg_rect.width,
    (text_rect.height + 40) * bg_scale.y / bg_rect.height};
    sfSprite_setScale(data->interface.tooltip.background.sprite, new_scale);
}

void load_tooltips(data_t *data)
{
    sfTexture *texture = sfTexture_createFromImage(
        sfImage_createFromColor(10, 10, (sfColor){0, 0, 0, 200}), NULL);
    data->interface.tooltip.is_visible = true;
    data->interface.tooltip.background.sprite = sfSprite_create();
    sfSprite_setTexture(data->interface.tooltip.background.sprite, texture, false);
    data->interface.tooltip.text = sfText_create();
    sfText_setFont(data->interface.tooltip.text,
        sfFont_createFromFile("font/nunito.ttf"));
    sfText_setColor(data->interface.tooltip.text, sfWhite);
}
