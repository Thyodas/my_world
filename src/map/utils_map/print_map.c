/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** print_map.c
*/

#include "my.h"
#include "myworld.h"

void print_map(sfVector2f **map)
{
    for (int i = 0; i < MAP_Y; ++i) {
        my_printf("{");
        for (int j = 0; j < MAP_X; ++j) {
            my_printf("{%.2f, %.2f}\n", map[i][j].x, map[i][j].y);
        }
        my_printf("}\n");
    }
}
