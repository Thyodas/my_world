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

int button_grass(data_t *data)
{
    data->selected_texture = data->textures.grass;
    return 0;
}

int button_dirt(data_t *data)
{
    data->selected_texture = data->textures.dirt;
    return 0;
}

int button_sand(data_t *data)
{
    data->selected_texture = data->textures.sand;
    return 0;
}

int button_stone(data_t *data)
{
    data->selected_texture = data->textures.stone;
    return 0;
}
