/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** time_unit_modif.c
*/

#include "zappy_server.h"

bool is_valid_sst(server_t *server, player_t *player, char **cmds)
{
    (void) player;
    (void) server;
    int conversion = -1;
    if (get_command_size(cmds) != 2)
        return false;
    if (!is_numeric(cmds[1]))
        return false;
    conversion = atoi(cmds[1]);
    if ((conversion < 2 || conversion > 10000))
        return false;
    return true;
}

int gui_sst(server_t *server, player_t *player, char **cmds)
{
    int time = -1;
    if (!server || !player || !cmds)
        return -1;
    time = (int) strtol(cmds[1], NULL, 10);
    server->game.freq = time;
    dprintf(player->fd, "sst %d\n", server->game.freq);
    return 0;
}
