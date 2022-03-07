/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** draw_map.c
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <math.h>
#include <stdlib.h>

#define MAP_X 10
#define MAP_Y 10

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2, sfVector2f *point3, sfVector2f *point4)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfColor color = sfWhite;
    //color.a = 50;
    sfVertex vertex1 = {.position = *point1, .color = color, .texCoords = *point1};
    sfVertex vertex2 = {.position = *point2, .color = color, .texCoords = *point2};
    sfVertex vertex3 = {.position = *point3, .color = color, .texCoords = *point3};
    sfVertex vertex4 = {.position = *point4, .color = color, .texCoords = *point4};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType (vertex_array, sfQuads);
    return vertex_array;
}

int draw_2d_map(sfRenderWindow *win, sfVector2f **map_2d, sfRenderStates state)
{
    sfVertexArray *vertex_array;
    for (int i = 0; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            vertex_array = create_line(&map_2d[i][j], &map_2d[i][j + 1], &map_2d[i + 1][j + 1], &map_2d[i + 1][j]);
            sfRenderWindow_drawVertexArray(win, vertex_array, &state);
        }
    }
    free(vertex_array);
    return 0;
}
