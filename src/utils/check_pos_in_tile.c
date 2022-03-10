/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** check_pos_in_tile.c
*/

#include "myworld.h"

int pos_in_tile(sfVector2i pos_mouse, sfVertexArray *vertex_array)
{
    sfFloatRect bounds = sfVertexArray_getBounds(vertex_array);
    if (sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y))
        return 1;
    else
        return 0;
}
