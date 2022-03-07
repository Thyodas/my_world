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

    typedef struct {
        sfTexture *sand;
        sfTexture *checker;
    } textures_t;

    typedef struct {
        sfVector2f **array_2d;
        sfVector3f **array_3d;
        int size_x;
        int size_y;
    } map_t;

    typedef struct {
        sfRenderWindow *window;
        textures_t textures;
        map_t map;
        sfEvent event;
    } data_t;

#endif /* MYWORLD_H_ */
