/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** time_unit.c
*/

#include "zappy_server.h"

int gui_time_unit(server_t *server, player_t *player, char **cmds)
{
    if (!server || !player || !cmds)
        return -1;
    dprintf(player->fd, "sgt %d\n", server->game.freq);
    return 0;
}
