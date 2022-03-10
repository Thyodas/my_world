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

    #define MAP_X 10
    #define MAP_Y 10
    #define M_PI 3.14159265358979323846

    typedef struct {
        sfTexture *texture;
        sfVector2u size;
        int loaded;
    } texture_data_t;

    typedef struct {
        texture_data_t sand;
        texture_data_t checker;
    } textures_t;

    typedef struct {
        sfVector2f **array_2d;
        sfVector3f **array_3d;
        int size_x;
        int size_y;
        sfVector2f factors;
    } map_t;

    typedef struct {
        sfRenderWindow *window;
        textures_t textures;
        map_t map;
        sfEvent event;
    } data_t;

#endif /* MYWORLD_H_ */
