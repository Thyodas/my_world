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

sfVertexArray *create_line(sfVector2f points[4], texture_data_t texture)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = points[0], .color = sfWhite, .texCoords =
                        (sfVector2f){0, 0}};
    sfVertex vertex2 = {.position = points[1], .color = sfWhite, .texCoords =
                        (sfVector2f){0, texture.size.y}};
    sfVertex vertex3 = {.position = points[2], .color = sfWhite, .texCoords =
                        (sfVector2f){texture.size.x, texture.size.y}};
    sfVertex vertex4 = {.position = points[3], .color = sfWhite, .texCoords =
                        (sfVector2f){texture.size.x, 0}};
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
    sfRenderStates state;
    state.texture = data.textures.checker.texture;
    state.blendMode = sfBlendAlpha;
    state.transform = sfTransform_Identity;
    state.shader = NULL;
    for (int i = 0; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            sfVector2f points[4] = {data.map.array_2d[i][j],
                                    data.map.array_2d[i][j + 1],
                                    data.map.array_2d[i + 1][j + 1],
                                    data.map.array_2d[i + 1][j]};
            vertex_array = create_line(points, data.textures.checker);
            sfRenderWindow_drawVertexArray(data.window, vertex_array, &state);
            free(vertex_array);
        }
    }
    return 0;
}
