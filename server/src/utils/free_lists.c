/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** free_lists
*/

#include "zappy_server.h"

void free_game(game_t *game)
{
    free_player_list(game->players);
    free_map(game);
    free_command(game->team_names);
    if (game->team_slot)
        free(game->team_slot);
}

void free_player_list(player_t *players)
{
    player_t* tmp = NULL;

    if (!players)
        return;
    while (players) {
        tmp = players;
        free_command(tmp->command_buffer);
        if (tmp->current_cmd)
            free(tmp->current_cmd);
        players = players->next;
        free(tmp);
    }
}

void free_id_list(user_id_t *id)
{
    user_id_t* tmp = NULL;

    if (!id)
        return;
    while (id) {
        tmp = id;
        id = id->next;
        free(tmp);
    }
}

void free_map(game_t *game)
{
    if (!game)
        return;
    for (int i = 0; i < game->map.height; i++) {
        for (int j = 0; j < game->map.width; j++) {
            free_id_list(game->map.map[i][j].id_list);
        }
        if (game->map.map[i])
            free(game->map.map[i]);
    }
    if (game->map.map)
        free(game->map.map);
}
