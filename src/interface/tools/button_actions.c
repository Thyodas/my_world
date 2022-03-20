/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** actions related to tool buttons
*/

#include "myworld.h"
#include "my.h"

void reset_selected_tool(data_t *data);
void set_selected_tool(data_t *data, enum buttons_pos btn);

int button_bucket(data_t *data)
{
    reset_selected_tool(data);
    data->map.use_hover_circle = false;
    set_selected_tool(data, BTN_BUCKET);
    return 0;
}

int button_panning(data_t *data)
{
    reset_selected_tool(data);
    data->map.use_hover_circle = false;
    set_selected_tool(data, BTN_PANNING);
    return 0;
}

int button_precision(data_t *data)
{
    reset_selected_tool(data);
    data->map.use_hover_circle = true;
    set_selected_tool(data, BTN_PRECISION);
    return 0;
}

int button_level(data_t *data)
{
    reset_selected_tool(data);
    data->map.use_hover_circle = false;
    set_selected_tool(data, BTN_LEVEL);
    return 0;
}

int button_picker(data_t *data)
{
    reset_selected_tool(data);
    data->map.use_hover_circle = false;
    set_selected_tool(data, BTN_PICKER);
    return 0;
}
