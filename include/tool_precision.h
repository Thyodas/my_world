/*
** EPITECH PROJECT, 2022
** myworld
** File description:
** tool_precision
*/

#ifndef TOOL_PRECISION_H_
    #define TOOL_PRECISION_H_

    #include "myworld.h"

    typedef struct {
        tile_t *tile;
        bool is_tile;
        bool is_corner;
        float dist_tile;
        float delta_z[3];
    } tool_precision_t;


#endif /* !TOOL_PRECISION_H_ */
