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

#define MAP_X 6
#define MAP_Y 6

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite, .texCoords = *point1};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite, .texCoords = *point2};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType (vertex_array, sfLinesStrip);
    return vertex_array;
}

int draw_2d_map(sfRenderWindow *win, sfVector2f **map_2d, sfRenderStates state)
{
    sfVertexArray *vertex_array;
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            if (j != MAP_X - 1) {
                vertex_array = create_line(&map_2d[i][j], &map_2d[i][j + 1]);
                sfRenderWindow_drawVertexArray(win, vertex_array, &state);
            }
            if (i != MAP_Y - 1) {
                vertex_array = create_line(&map_2d[i][j], &map_2d[i + 1][j]);
                sfRenderWindow_drawVertexArray(win, vertex_array, &state);
            }
        }
    }
    free(vertex_array);
    return 0;
}
