/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** draw_map.c
*/

#include "my.h"
#include "myworld.h"
#include <math.h>
#include <stdlib.h>

#define MAP_X 10
#define MAP_Y 10

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2, sfVector2f *point3, sfVector2f *point4)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfColor color = sfWhite;
    //color.a = 50;
    sfVertex vertex1 = {.position = *point1, .color = color, .texCoords = (sfVector2f){0, 0}};
    sfVertex vertex2 = {.position = *point2, .color = color, .texCoords = (sfVector2f){0, 2048}};
    sfVertex vertex3 = {.position = *point3, .color = color, .texCoords = (sfVector2f){2048, 2048}};
    sfVertex vertex4 = {.position = *point4, .color = color, .texCoords = (sfVector2f){2048, 0}};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType (vertex_array, sfQuads);
    return vertex_array;
}

int draw_2d_map(data_t data)
{
    sfVertexArray *vertex_array;
    for (int i = 0; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            sfRenderStates state;
            state.texture = data.textures.checker;
            state.blendMode = sfBlendAlpha;
            state.transform = sfTransform_Identity;
            state.shader = NULL;
            vertex_array = create_line(&data.map.array_2d[i][j], &data.map.array_2d[i][j + 1], &data.map.array_2d[i + 1][j + 1], &data.map.array_2d[i + 1][j]);
            sfRenderWindow_drawVertexArray(data.window, vertex_array, &state);
        }
    }
    free(vertex_array);
    return 0;
}
