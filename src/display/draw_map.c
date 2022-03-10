/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** draw_map.c
*/

#include "myworld.h"
#include <math.h>
#include <stdlib.h>

int pnpoly(sfVector2f points[4], sfVector2i pos);

sfRenderStates create_state(sfTexture *text)
{
    sfRenderStates state;
    state.texture = text;
    state.blendMode = sfBlendAlpha;
    state.transform = sfTransform_Identity;
    state.shader = NULL;
    return state;
}

sfVertexArray *create_tile(sfVector2f points[4], texture_data_t texture,
                            int hover)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfColor color = sfWhite;
    if (!hover)
        color.a = 150;
    sfVertex vertex1 = {.position = points[0], .color = color, .texCoords =
                        (sfVector2f){0, 0}};
    sfVertex vertex2 = {.position = points[1], .color = color, .texCoords =
                        (sfVector2f){0, texture.size.y}};
    sfVertex vertex3 = {.position = points[2], .color = color, .texCoords =
                        (sfVector2f){texture.size.x, texture.size.y}};
    sfVertex vertex4 = {.position = points[3], .color = color, .texCoords =
                        (sfVector2f){texture.size.x, 0}};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType (vertex_array, sfQuads);
    return vertex_array;
}

void draw_vertex_array(data_t data, sfRenderStates states[2], int i,
                        int *hovered)
{
    sfVertexArray *vertex_array;
    sfVertexArray *hover;
    for (int j = 0; j < MAP_X - 1; ++j) {
        sfVector2f points[4] = {data.map.array_2d[i][j],
                                data.map.array_2d[i][j + 1],
                                data.map.array_2d[i + 1][j + 1],
                                data.map.array_2d[i + 1][j]};
        vertex_array = create_tile(points, data.textures.sand, 1);
        if (pnpoly(points, data.pos_mouse)) {
            hover = create_tile(points, data.textures.hover, 0);
            sfRenderWindow_drawVertexArray(data.window, vertex_array,
                                            &states[0]);
            sfRenderWindow_drawVertexArray(data.window, hover, &states[1]);
            free(hover);
            *hovered = 1;
        } else
            sfRenderWindow_drawVertexArray(data.window, vertex_array,
                                            &states[0]);
        free(vertex_array);
    }
}

int draw_2d_map(data_t data)
{
    sfRenderStates states[2] = {create_state(data.textures.sand.texture),
                                create_state(data.textures.hover.texture)
    };
    int hovered = 0;
    for (int i = 0; i < MAP_Y - 1; ++i)
        draw_vertex_array(data, states, i, &hovered);
    return 0;
}
