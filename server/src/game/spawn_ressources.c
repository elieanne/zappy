/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** spawn_ressources
*/

#include "game.h"
#include "map.h"

int spawn_thystame(map_t *map, int size)
{
    int rand_height = 0;
    int rand_width = 0;
    int nb_food = size * 0.05 - get_nb_thystame(map);

    if (!map || !map->map)
        return 84;
    for (int i = 0; i < nb_food; i++) {
        rand_height = rand() % map->height;
        rand_width = rand() % map->width;
        if (!map->map[rand_height])
            return 84;
        map->map[rand_height][rand_width].inventory.thystame += 1;
    }
    return 0;
}

int spawn_phiras(map_t *map, int size)
{
    int rand_height = 0;
    int rand_width = 0;
    int nb_food = size * 0.08 - get_nb_phiras(map);

    if (!map || !map->map)
        return 84;
    for (int i = 0; i < nb_food; i++) {
        rand_height = rand() % map->height;
        rand_width = rand() % map->width;
        if (!map->map[rand_height])
            return 84;
        map->map[rand_height][rand_width].inventory.phiras += 1;
    }
    return 0;
}

int spawn_mendiane(map_t *map, int size)
{
    int rand_height = 0;
    int rand_width = 0;
    int nb_food = size * 0.1 - get_nb_mendiane(map);

    if (!map || !map->map)
        return 84;
    for (int i = 0; i < nb_food; i++) {
        rand_height = rand() % map->height;
        rand_width = rand() % map->width;
        if (!map->map[rand_height])
            return 84;
        map->map[rand_height][rand_width].inventory.mendiane += 1;
    }
    return 0;
}

int spawn_sibur(map_t *map, int size)
{
    int rand_height = 0;
    int rand_width = 0;
    int nb_food = size * 0.1 - get_nb_sibur(map);

    if (!map || !map->map)
        return 84;
    for (int i = 0; i < nb_food; i++) {
        rand_height = rand() % map->height;
        rand_width = rand() % map->width;
        if (!map->map[rand_height])
            return 84;
        map->map[rand_height][rand_width].inventory.sibur += 1;
    }
    return 0;
}

int spawn_deraumere(map_t *map, int size)
{
    int rand_height = 0;
    int rand_width = 0;
    int nb_food = size * 0.15 - get_nb_deraumere(map);

    if (!map || !map->map)
        return 84;
    for (int i = 0; i < nb_food; i++) {
        rand_height = rand() % map->height;
        rand_width = rand() % map->width;
        if (!map->map[rand_height])
            return 84;
        map->map[rand_height][rand_width].inventory.deraumere += 1;
    }
    return 0;
}
