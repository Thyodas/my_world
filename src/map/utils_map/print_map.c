/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** print_map.c
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>

#define MAP_X 6
#define MAP_Y 6

void print_map(sfVector2f **map)
{
    for (int i = 0; i < MAP_Y; i++) {
        my_printf("{");
        for (int j = 0; j < MAP_X; j++) {
            my_printf("{%.2f, %.2f}", map[i][j].x, map[i][j].y);
        }
        my_printf("}\n");
    }
}
