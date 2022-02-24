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

void main_loop(sfVector3f **map);

int main(int argc, char **argv)
{
    sfVector3f **test = malloc(sizeof(sfVector3f *) * MAP_Y);
    for (int i = 0; i < MAP_Y; i++) {
        test[i] = malloc(sizeof(sfVector3f) * MAP_X);
        for (int j = 0; j < MAP_X; j++) {
            test[i][j].x = i;
            test[i][j].y = j;
            test[i][j].z = 0;
        }
    }
    main_loop(test);
    return 0;
}
