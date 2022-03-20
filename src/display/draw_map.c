/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** draw_map.c
*/

#include "myworld.h"
#include "my.h"
#include <math.h>
#include <stdlib.h>

int pnpoly(sfVector2f points[4], sfVector2i pos);
float calc_dist(sfVector2f point1, sfVector2f point2);
sfRenderStates create_state(sfTexture *text);
sfVertexArray *create_tile(sfVector2f points[4], texture_data_t texture,
sfColor texture_color);
sfVector2f project_iso_point(float x, float y, float z, sfVector2f factors);

void draw_hover_tile(data_t *data, sfVector2f points[4], sfRenderStates state,
sfVector2i pos)
{
    sfVertexArray *vertex_array = create_tile(points,
        data->map.tiles[pos.x][pos.y].texture, (sfColor){120, 120, 120, 255});
    sfRenderWindow_drawVertexArray(data->window, vertex_array, &state);
    sfVertexArray_destroy(vertex_array);
}

void set_hovered(data_t *data, int i, int j)
{
    sfVector2f points[4] = {data->map.tiles[i][j].coord_2d,
        data->map.tiles[i][j + 1].coord_2d,
        data->map.tiles[i + 1][j + 1].coord_2d,
        data->map.tiles[i + 1][j].coord_2d};
    if (data->map.use_hover_circle && calc_dist(data->map.tiles[i][j]
        .coord_2d, (sfVector2f){data->pos_mouse.x, data->pos_mouse.y})
        < data->map.hover_circle_radius) {
        data->map.show_hover_circle = true;
        data->map.is_tile_hovered = false;
        data->map.hovered_tile = &data->map.tiles[i][j];
    } else if (pnpoly(points, data->pos_mouse)) {
        data->map.hovered_tile = &data->map.tiles[i][j];
        data->map.show_hover_circle = false;
        data->map.is_tile_hovered = true;
    }
}

void draw_vertex_array(data_t *data, int i, int j)
{
    sfVertexArray *vertex_array;
    sfVector2f points[4] = {data->map.tiles[i][j].coord_2d, data->map.tiles[i]
        [j + 1].coord_2d, data->map.tiles[i + 1][j + 1].coord_2d,
        data->map.tiles[i + 1][j].coord_2d};
    sfRenderStates state = create_state(data->map.tiles[i][j].texture.texture);
    if (data->map.is_tile_hovered && i == data->map.hovered_tile->
        index_x && j == data->map.hovered_tile->index_y) {
        draw_hover_tile(data, points, state, (sfVector2i){i, j});
        return;
    }
    vertex_array = create_tile(points, data->map.tiles[i][j].texture,
        data->map.tiles[i][j].color);
    sfRenderWindow_drawVertexArray(data->window, vertex_array, &state);
    sfVertexArray_destroy(vertex_array);
}

void draw_hover_circle(data_t *data)
{
    if (data->map.use_hover_circle && data->map.show_hover_circle) {
        sfCircleShape_setRadius(data->map.hover_circle,
            data->map.hover_circle_radius);
        sfCircleShape_setOrigin(data->map.hover_circle, (sfVector2f)
            {data->map.hover_circle_radius, data->map.hover_circle_radius});
        sfCircleShape_setPosition(data->map.hover_circle,
            data->map.hovered_tile->coord_2d);
        sfRenderWindow_drawCircleShape(data->window,
            data->map.hover_circle, NULL);
    }
}

int draw_2d_map(data_t *data)
{
    data->map.show_hover_circle = false;
    data->map.is_tile_hovered = false;
    data->map.hover_circle_radius = data->map.factors.x / 6;
    for (int i = 0; i < data->map.size * data->map.size; i++)
        if (data->map.draw_order[i]->index_x < data->map.size - 1 &&
            data->map.draw_order[i]->index_y < data->map.size - 1)
            set_hovered(data, data->map.draw_order[i]->index_x,
                data->map.draw_order[i]->index_y);
    for (int i = 0; i < data->map.size * data->map.size; i++)
        if (data->map.draw_order[i]->index_x < data->map.size - 1 &&
            data->map.draw_order[i]->index_y < data->map.size - 1)
            draw_vertex_array(data, data->map.draw_order[i]->index_x,
                data->map.draw_order[i]->index_y);
    draw_hover_circle(data);
    return 0;
}
