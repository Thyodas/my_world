/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main.c
*/

#include "my.h"
#include "myworld.h"
#include <math.h>
#include <stdlib.h>

void main_loop(data_t data);

int main(int argc, char **argv)
{
    data_t data;
    data.map.array_3d = malloc(sizeof(sfVector3f *) * MAP_Y);
    for (int i = 0; i < MAP_Y; i++) {
        data.map.array_3d[i] = malloc(sizeof(sfVector3f) * MAP_X);
        for (int j = 0; j < MAP_X; j++) {
            data.map.array_3d[i][j].x = i;
            data.map.array_3d[i][j].y = j;
            data.map.array_3d[i][j].z = 0;
        }
    }
    main_loop(data);
    return 0;
}
