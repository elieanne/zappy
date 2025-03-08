/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_player.c
*/

#include "zappy_server.h"

void release_current_command(player_t *player)
{
    if (!player || !player->current_cmd)
        return;
    free(player->current_cmd);
    player->current_cmd = NULL;
}

user_id_t *gen_new_id(void)
{
    user_id_t *new_id = malloc(sizeof(user_id_t));
    if (!new_id)
        return NULL;
    new_id->id = generate_uuid();
    new_id->next = NULL;
    return new_id;
}

player_t *init_player_inventory(player_t *player)
{
    if (!player)
        return NULL;
    player->inventory.food = 0;
    player->inventory.deraumere = 0;
    player->inventory.linemate = 0;
    player->inventory.mendiane = 0;
    player->inventory.sibur = 0;
    player->inventory.phiras = 0;
    player->inventory.thystame = 0;
    return player;
}

player_t *init_player_command(player_t *player)
{
    player = init_player_inventory(player);
    player->next = NULL;
    player->type = EGG;
    player->command_buffer = NULL;
    player->current_cmd = NULL;
    player->food_clock = 0;
    player->client_index = -1;
    return player;
}

player_t *init_player(int team_id, game_t *game)
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
    player->tile = &game->map.map[rand() % game->map.height]
    [rand() % game->map.width];
    player->tile->id_list = add_id_back(player->tile->id_list, new_id);
    return player;
}
