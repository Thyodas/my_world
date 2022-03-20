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

void load_buttons(data_t *data)
{
    data->ui.buttons[BTN_BUCKET] = create_button(30, 270,
        data->ui.textures.bucket.texture, &button_bucket);
    data->ui.buttons[BTN_PANNING] = create_button(30, 348,
        data->ui.textures.panning.texture, &button_panning);
    data->ui.buttons[BTN_PRECISION] = create_button(30, 426,
        data->ui.textures.precision.texture, &button_precision);
    data->ui.buttons[BTN_LEVEL] = create_button(30, 504,
        data->ui.textures.level.texture, &button_level);
    data->ui.buttons[BTN_PICKER] = create_button(30, 582,
        data->ui.textures.picker.texture, &button_picker);
    data->ui.buttons[BTN_GRASS] = create_button(30, 660,
        data->ui.textures.grass_btn.texture, &button_grass);
    data->ui.buttons[BTN_DIRT] = create_button(30, 738,
        data->ui.textures.dirt_btn.texture, &button_dirt);
    data->ui.buttons[BTN_SAND] = create_button(30, 816,
        data->ui.textures.sand_btn.texture, &button_sand);
    data->ui.buttons[BTN_STONE] = create_button(30, 894,
        data->ui.textures.stone_btn.texture, &button_stone);
}
