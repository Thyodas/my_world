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
    set_selected_tool(data, BTN_BUCKET);
    my_printf("%s", "Tool bucket\n");
    return 0;
}

int button_size(data_t *data)
{
    reset_selected_tool(data);
    set_selected_tool(data, BTN_GRID_SIZE);
    my_printf("%s", "Tool size\n");
    return 0;
}

int button_pen_width(data_t *data)
{
    reset_selected_tool(data);
    set_selected_tool(data, BTN_PEN_WIDTH);
    my_printf("%s", "Tool pen width\n");
    return 0;
}

int button_level(data_t *data)
{
    reset_selected_tool(data);
    set_selected_tool(data, BTN_LEVEL);
    my_printf("%s", "Tool level\n");
    return 0;
}

int button_picker(data_t *data)
{
    reset_selected_tool(data);
    set_selected_tool(data, BTN_PICKER);
    my_printf("%s", "Tool picker\n");
    return 0;
}
