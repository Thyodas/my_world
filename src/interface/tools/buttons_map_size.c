/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** buttons_map_size
*/

#include "myworld.h"
#include "my.h"

static const char *SIZE_STEP[] = {
    "8",
    "16",
    "32",
    "64"
};

int button_plus(data_t *data)
{
    if (data->map.size_step >= 3)
        return 0;
    const char *nb = SIZE_STEP[++data->map.size_step];
    sfText_setString(data->interface.map_size_text, nb);
    data->map.new_map_size = my_getnbr(nb);
    return 0;
}

int button_minus(data_t *data)
{
    if (data->map.size_step <= 0)
        return 0;
    const char *nb = SIZE_STEP[--data->map.size_step];
    sfText_setString(data->interface.map_size_text, nb);
    data->map.new_map_size = my_getnbr(nb);
    return 0;
}
