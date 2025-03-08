/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** validity_checker.c
*/

#include "zappy_server.h"

bool is_valid_bct(server_t *server, player_t *player, char **cmds)
{
    map_t map;
    int x = -1;
    int y = -1;
    if (!server || !player || !cmds || (get_command_size(cmds) != 3))
        return false;
    if (!is_numeric(cmds[1]) || !is_numeric(cmds[2]))
        return false;
    map = server->game.map;
    x = (int) strtol(cmds[1], NULL, 10);
    y = (int) strtol(cmds[2], NULL, 10);
    if (x < 0 || y < 0 || x >= map.width || y >= map.height)
        return false;
    return true;
}
