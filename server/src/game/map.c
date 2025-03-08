/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** map
*/

#include "zappy_server.h"

int spawn_linemate(map_t *map, int size)
{
    int rand_height = 0;
    int rand_width = 0;
    int nb_food = (int) (size * 0.3) - get_nb_linemate(map);

    if (!map || !map->map)
        return 84;
    for (int i = 0; i < nb_food; i++) {
        rand_height = rand() % map->height;
        rand_width = rand() % map->width;
        if (!map->map[rand_height])
            return 84;
        map->map[rand_height][rand_width].inventory.linemate += 1;
    }
    return 0;
}

int spawn_food(map_t *map, int size)
{
    int rand_height = 0;
    int rand_width = 0;
    int nb_food = size * 0.5 - get_nb_food(map);

    if (!map || !map->map)
        return 84;
    for (int i = 0; i < nb_food; i++) {
        rand_height = rand() % map->height;
        rand_width = rand() % map->width;
        if (!map->map[rand_height])
            return 84;
        map->map[rand_height][rand_width].inventory.food += 1;
    }
    return 0;
}

int spawn_ressources(game_t *game)
{
    int full_size = 0;
    int return_val = 0;
    if (!game)
        return 84;

    full_size = game->map.height * game->map.width;
    return_val += spawn_food(&game->map, full_size);
    return_val += spawn_linemate(&game->map, full_size);
    return_val += spawn_deraumere(&game->map, full_size);
    return_val += spawn_sibur(&game->map, full_size);
    return_val += spawn_mendiane(&game->map, full_size);
    return_val += spawn_phiras(&game->map, full_size);
    return_val += spawn_thystame(&game->map, full_size);
    if (return_val)
        return 84;
    return 0;
}

player_t *init_player_pos(int team_id, game_t *game, int x, int y)
{
    player_t *player = NULL;
    user_id_t *new_id = gen_new_id();
    player = malloc(sizeof(player_t));
    if (!player || !new_id || !game)
        return NULL;
    player->fd = -1;
    player->cooldown = 0;
    player->elevating = false;
    player->id = new_id->id;
    player->level = 1;
    player = init_player_command(player);
    player->team = team_id;
    player->was_egg = false;
    player->orientation = (rand() % 4) + 1;
    player->tile = &game->map.map[y][x];
    player->tile->id_list = add_id_back(player->tile->id_list, new_id);
    return player;
}
