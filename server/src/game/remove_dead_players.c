/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** remove_dead_players.c
*/

#include "zappy_server.h"

void send_death_message(player_t *player, server_t *server)
{
    if (!player || player->fd == -1)
        return;
    dprintf(player->fd, "dead\n");
    remove_client(server, player->client_index);
}

char *get_death_infos(player_t *player)
{
    char *result = NULL;
    if (!player || player->team == -1)
        return NULL;
    result = malloc(sizeof(char) * 16);
    if (!player->was_egg)
        sprintf(result, "pdi %d\n", player->id);
    else
        sprintf(result, "edi %d\n", player->id);
    return result;
}

void remove_dead_players(server_t *server)
{
    player_t *tmp = server->game.players;
    player_t *prev = NULL;
    player_t *save = NULL;

    while (tmp != NULL) {
        if (tmp->type != DEAD) {
            prev = tmp;
            tmp = prev->next;
            continue;
        }
        send_death_message(tmp, server);
        send_gui_event(server->game.players, get_death_infos(tmp));
        save = tmp;
        tmp = save->next;
        server->game.players = remove_node(server->game.players, prev, save);
    }
}
