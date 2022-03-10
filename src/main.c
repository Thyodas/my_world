/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main.c
*/

#include "myworld.h"

void main_loop(data_t data);
sfVector3f **init_map_3d(int map_x, int map_y);

int main(int argc, char **argv)
{
    data_t data;
    data.map.array_3d = init_map_3d(MAP_X, MAP_Y);
    main_loop(data);
    return 0;
}
