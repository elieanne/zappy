/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** inventory.c
*/

#include "zappy_server.h"

bool is_valid_inv(server_t *server, player_t *player, char **cmds)
{
    if (!server || !player || !cmds)
        return false;
    if (get_command_size(cmds) != 1)
        return false;
    return true;
}

int ai_inventory(server_t *server, player_t *player, char** cmds)
{
    inventory_t inv;
    if (!server || !player || !cmds)
        return -1;
    inv = player->inventory;
    dprintf(player->fd, "[ food %d, linemate %d, deraumere %d, sibur %d,"
                        " mendiane %d, phiras %d, thystame %d ]\n", inv.food,
        inv.linemate, inv.deraumere, inv.sibur, inv.mendiane, inv.phiras,
        inv.thystame
        );
    return 0;
}
