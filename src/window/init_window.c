/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** init_window.c
*/

#include "myworld.h"
#include <stdlib.h>

sfRenderWindow *init_window(int x, int y)
{
    sfVideoMode mode = {.width = x, .height = y, .bitsPerPixel = 0};
    sfRenderWindow *win = sfRenderWindow_create(mode, "my_world", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win, 500);
    return win;
}