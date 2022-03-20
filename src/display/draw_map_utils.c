/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** draw_map_utils
*/

#include "myworld.h"

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
sfColor texture_color)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {points[0], texture_color, (sfVector2f){0, 0}};
    sfVertex vertex2 = {points[1], texture_color,
        (sfVector2f){0, texture.size.y}};
    sfVertex vertex3 = {points[2], texture_color,
        (sfVector2f){texture.size.x, texture.size.y}};
    sfVertex vertex4 = {points[3], texture_color,
        (sfVector2f){texture.size.x, 0}};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return vertex_array;
}
