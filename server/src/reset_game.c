/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** reset_game.c
*/

#include "zappy_server.h"

void reset_game(server_t *server)
{
    player_t *save = NULL;

    if (!server)
        return;
    save = server->game.players;
    for (; save != NULL; save = save->next) {
        if (save->type == GUI)
            continue;
        save->type = DEAD;
    }
    remove_dead_players(server);
    for (int i = 0; i < server->game.teams_nb; i++)
        server->game.team_slot[i] = server->game.max_client;
    init_player_list(&server->game);
    server->game.is_win = false;
    printf("======= Game reset... =======\n");
}
