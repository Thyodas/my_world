/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** check_pos_in_tile.c
*/

#include "myworld.h"

int pnpoly(sfVector2f points[4], sfVector2i pos)
{
    int i, j, c = 0;
    for (i = 0, j = 3; i < 4; j = i++) {
        if ((((points[i].y <= pos.y) && (pos.y < points[j].y)) ||
            ((points[j].y <= pos.y) && (pos.y < points[i].y))) &&
            (pos.x < (points[j].x - points[i].x) *
            (pos.y - points[i].y) /
            (points[j].y - points[i].y) + points[i].x))
        c = !c;
    }
    return c;
}
