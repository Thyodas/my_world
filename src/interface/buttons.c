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
int button_size(data_t *data);
int button_pen_width(data_t *data);
int button_level(data_t *data);

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
    data->ui.buttons[BTN_BUCKET] = create_button(30, 351,
        data->ui.textures.bucket.texture, &button_bucket);
    data->ui.buttons[BTN_GRID_SIZE] = create_button(30, 429,
        data->ui.textures.size.texture, &button_size);
    data->ui.buttons[BTN_PEN_WIDTH] = create_button(30, 507,
        data->ui.textures.pen_width.texture, &button_pen_width);
    data->ui.buttons[BTN_LEVEL] = create_button(30, 585,
        data->ui.textures.level.texture, &button_level);
    data->ui.buttons[BTN_PICKER] = create_button(30, 663,
        data->ui.textures.picker.texture, &button_picker);
}