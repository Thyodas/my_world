/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** main.c
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>

#define MAP_X 6
#define MAP_Y 6

void main_loop(float **map);

int main(int argc, char **argv)
{
    float **map = malloc(sizeof(float *) * MAP_Y);
    for (int i = 0; i < MAP_Y; i++) {
        map[i] = malloc(sizeof(float) * MAP_X);
        for (int j = 0; j < MAP_X; j++)
            map[i][j] = 0;
    }
    main_loop(map);
    return 0;
}
