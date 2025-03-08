/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** connect_nbr
*/

#include "zappy_server.h"

int connect_nbr(server_t *server, player_t *player, char** cmds)
{
    if (!player)
        return ERROR;
    if (!server || !server->game.team_slot ||
    player->team >= server->game.teams_nb || cmds[1])
        return ERROR;
    dprintf(player->fd, "%d\n", server->game.team_slot[player->team]);
    return SUCCESS;
}
