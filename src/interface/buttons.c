/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** buttons -> TODO: add description
*/

#include "myworld.h"
#include "interface.h"
#include "my.h"

int button_picker(data_t *data);
int button_bucket(data_t *data);
int button_panning(data_t *data);
int button_precision(data_t *data);
int button_level(data_t *data);
int button_grass(data_t *data);
int button_dirt(data_t *data);
int button_sand(data_t *data);
int button_stone(data_t *data);
int button_plus(data_t *data);
int button_minus(data_t *data);

static button_t create_button(float pos_x, float pos_y, sfTexture *texture,
int (*on_click)())
{
    button_t btn;
    btn.sprite = sfSprite_create();
    sfSprite_setTexture(btn.sprite, texture, true);
    sfSprite_setPosition(btn.sprite, (sfVector2f){pos_x, pos_y});
    btn.is_visible = true;
    btn.state = IDLE;
    btn.on_click = on_click;
    return btn;
}

static void load_texture_button(data_t *data)
{
    data->interface.buttons[BTN_GRASS] = create_button(30, 660,
        data->interface.textures.grass_btn.texture, &button_grass);
    data->interface.buttons[BTN_DIRT] = create_button(30, 738,
        data->interface.textures.dirt_btn.texture, &button_dirt);
    data->interface.buttons[BTN_SAND] = create_button(30, 816,
        data->interface.textures.sand_btn.texture, &button_sand);
    data->interface.buttons[BTN_STONE] = create_button(30, 894,
        data->interface.textures.stone_btn.texture, &button_stone);
}

static void load_tool_button(data_t *data)
{
    data->interface.buttons[BTN_BUCKET] = create_button(30, 270,
        data->interface.textures.bucket.texture, &button_bucket);
    data->interface.buttons[BTN_PANNING] = create_button(30, 348,
        data->interface.textures.panning.texture, &button_panning);
    data->interface.buttons[BTN_PRECISION] = create_button(30, 426,
        data->interface.textures.precision.texture, &button_precision);
    data->interface.buttons[BTN_LEVEL] = create_button(30, 504,
        data->interface.textures.level.texture, &button_level);
    data->interface.buttons[BTN_PICKER] = create_button(30, 582,
        data->interface.textures.picker.texture, &button_picker);
    data->interface.buttons[BTN_PLUS] = create_button(74, 168,
        data->interface.textures.plus_btn.texture, &button_plus);
    data->interface.buttons[BTN_MINUS] = create_button(109, 168,
        data->interface.textures.minus_btn.texture, &button_minus);
}

void load_buttons(data_t *data)
{
    load_tool_button(data);
    load_texture_button(data);
}
