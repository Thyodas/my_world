/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myworld-guillaume.hein
** File description:
** load.c
*/

#include "myworld.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

float ratof(char *arr);

void implement_texture(data_t *data, int id, int i, int j)
{
    if (id == SAND)
        data->map.tiles[i][j].texture = data->textures.sand;
    if (id == GRASS)
        data->map.tiles[i][j].texture = data->textures.grass;
}

int fill_tile(char *line, int i, int j, data_t *data)
{
    float coords[4];
    int k = 0;
    char *token = my_strtok(line, " ");
    coords[k++] = ratof(token);
    for (; (token = my_strtok(NULL, " \n")) != NULL && k < 4; ++k)
        coords[k] = ratof(token);
    if (k != 4)
        return 0;
    data->map.tiles[i][j].coord_3d.x = coords[0];
    data->map.tiles[i][j].coord_3d.y = coords[1];
    data->map.tiles[i][j].coord_3d.z = coords[2];
    implement_texture(data, (int)coords[3], i, j);
    data->map.tiles[i][j].index_x = i;
    data->map.tiles[i][j].index_y = j;
    data->map.tiles[i][j].color = sfWhite;
    return 1;
}

int allocate_tiles(data_t *data)
{
    data->map.tiles = malloc(sizeof(tile_t *) * data->map.size);
    if (data->map.tiles == NULL)
        return 0;
    for (int i = 0; i < data->map.size; ++i) {
        data->map.tiles[i] = malloc(sizeof(tile_t) * data->map.size);
        if (data->map.tiles[i] == NULL)
            return 0;
    }
    int double_size = data->map.size * data->map.size;
    data->map.draw_order = malloc(sizeof(tile_t *) * double_size);
    if (data->map.draw_order == NULL)
        return 0;
    return 1;
}

int fill_map(data_t *data, FILE *fp)
{
    if (!allocate_tiles(data))
        return 0;
    char *line = NULL;
    size_t len = 0;
    int i = 0;
    int j = 0;
    int pos = 0;
    while (getline(&line, &len, fp) != -1) {
        if (!fill_tile(line, i, j, data))
            return 0;
        data->map.draw_order[pos++] = &data->map.tiles[i][j++];
        if (j == data->map.size) {
            j = 0;
            i++;
        }
        if (i == data->map.size)
            break;
    }
    return 1;
}

int load_map(data_t *data, char *path)
{
    FILE *fp = fopen(path, "r");
    if (!fp) {
        my_printf("There was an error opening the file\n");
        return 0;
    }
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, fp) == -1)
        return 0;
    int size = my_getnbr(line);
    if (size <= 1)
        return 0;
    data->map.size = size;
    if (!fill_map(data, fp))
        return 0;
    return 1;
}
