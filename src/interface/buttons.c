/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** buttons -> TODO: add description
*/

#include "myworld.h"
#include "interface.h"
#include "my.h"

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

int button_bucket(void) {
    my_printf("%s", "Tool bucket\n");
    return 0;
}

void load_buttons(data_t *data)
{
    data->ui.buttons[BTN_BUCKET] = create_button(0, 0,
        data->ui.textures.bucket.texture, &button_bucket);
}