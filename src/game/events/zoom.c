/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** zoom.c
*/

#include "myworld.h"

void zoom_in(data_t *data)
{
    data->map.factors.x += 5;
    data->map.factors.y += 5;
}

void zoom_out(data_t *data)
{
    data->map.factors.x -= 5;
    data->map.factors.y -= 5;
}