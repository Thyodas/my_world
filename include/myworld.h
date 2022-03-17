/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** myworld -> main data structures
*/

#ifndef MYWORLD_H_
    #define MYWORLD_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdbool.h>

    #define MAP_X 200
    #define MAP_Y 200
    #define M_PI 3.14159265358979323846
    #define DEG_TO_RAD(x) ((x) * M_PI / 180)
    #define MIN(a, b) ((a) < (b) ? (a) : (b))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))

    typedef struct {
        sfTexture *texture;
        sfVector2u size;
        int loaded;
    } texture_data_t;

    #include "interface.h"

    typedef struct {
        texture_data_t sand;
        texture_data_t checker;
        texture_data_t hover;
    } textures_t;

    typedef struct {
        sfVector2f coord_2d;
        sfVector3f coord_3d;
        texture_data_t texture;
    } tile_t;

    typedef struct {
        tile_t **tiles;
        int size_x;
        int size_y;
        sfVector2f factors;
        sfVector2i hovered_tile;
        bool is_tile_hovered;
    } map_t;

    typedef struct {
        sfRenderWindow *window;
        textures_t textures;
        map_t map;
        interface_t ui;
        sfEvent event;
        sfVector2i pos_mouse;
        sfVector2i pos_center;
        sfVector2f pos_board_center;
        bool mouse_released;
        bool is_mouse_on_ui;
        bool recalc;
        texture_data_t selected_texture;
        int (*selected_tool_func)();
    } data_t;

#endif /* MYWORLD_H_ */
