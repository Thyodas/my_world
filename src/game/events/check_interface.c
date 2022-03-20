/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** check_interface.c
*/

#include "myworld.h"
#include "my.h"

void set_hovered_tool(data_t *data, enum buttons_pos btn);
void reset_selected_tool(data_t *data);
void set_idle_tool(data_t *data, enum buttons_pos btn);
void reset_hovered_tool(data_t *data);
void set_tooltip_text(data_t *data, char *text);
void set_tooltip_pos(data_t *data, float x, float y);

static const char *TOOLTIP_TEXT[] = {
    "B - Bucket\nLeft click on the tile you want to paint.",
    "M - Panning\nLeft click to move around the map.",
    "P - Precision\nGrab corner/tile with left click and use mouse to change \
height.",
    "L - Level\nLeft click to increase tile height, right click to decrease \
it.",
    "C - Picker\nLeft click on the tile you want to copy texture from."
};

static int check_buttons(data_t *data)
{
    for (int i = 0; i < NB_BUTTON; ++i) {
        sfFloatRect rect = sfSprite_getGlobalBounds(data->ui.buttons[i].sprite);
        if (sfFloatRect_contains(&rect, data->pos_mouse.x, data->pos_mouse.y)) {
            data->ui.buttons[i].on_click(data);
            return true;
        }
    }
    return false;
}

bool check_interface(data_t *data)
{
    if (check_buttons(data))
        return true;
}

int check_interface_hovering(data_t *data)
{
    reset_hovered_tool(data);
    for (int i = 0; i < NB_BUTTON; ++i) {
        sfFloatRect rect = sfSprite_getGlobalBounds(data->ui.buttons[i].sprite);
        if (!sfFloatRect_contains(&rect, data->pos_mouse.x, data->pos_mouse.y))
            continue;
        if (i < BTN_GRASS) {
            set_tooltip_text(data, TOOLTIP_TEXT[i]);
            sfVector2f pos = sfSprite_getPosition(data->ui.buttons[i].sprite);
            set_tooltip_pos(data, pos.x + 82, pos.y);
            data->ui.tooltip.is_visible = true;
        }
        if (data->ui.buttons[i].state == IDLE) {
            set_hovered_tool(data, i);
            return true;
        }
        if (data->ui.buttons[i].state == HOVERED)
            set_idle_tool(data, i);
    }
    return false;
}
