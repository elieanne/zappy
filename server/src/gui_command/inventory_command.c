/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** inventory_command.c
*/

#include "zappy_server.h"

bool is_valid_pin(server_t *server, player_t *player, char **cmds)
{
    (void) *player;
    int id = -1;
    player_t *tmp = NULL;
    if (get_command_size(cmds) != 2)
        return false;
    if (!is_numeric(cmds[1]))
        return false;
    id = (int) strtol(cmds[1], NULL, 10);
    tmp = find_player_by_uuid(server->game.players, id);
    if (!tmp || tmp->type != PLAYER)
        return false;
    return true;
}

void gui_inv_event(player_t *player_list, player_t *player)
{
    inventory_t inv;
    player_t *tmp = NULL;
    if (!player || !player_list)
        return;
    inv = player->inventory;
    tmp = player_list;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type != GUI)
            continue;
        dprintf(tmp->fd, "pin %d %d %d %d %d %d %d %d %d %d\n", player->id,
        player->tile->x, player->tile->y, inv.food, inv.linemate,
        inv.deraumere, inv.sibur, inv.mendiane, inv.phiras, inv.thystame);
    }
}

int gui_player_pin(server_t *server, player_t *player, char **cmds)
{
    player_t *tmp = NULL;
    inventory_t inv;
    int id = -1;
    if (!server || !player || !cmds)
        return -1;
    id = (int) strtol(cmds[1], NULL, 10);
    tmp = find_player_by_uuid(server->game.players, id);
    if (!tmp || tmp->type != PLAYER)
        return -1;
    inv = tmp->inventory;
    dprintf(player->fd, "pin %d %d %d %d %d %d %d %d %d %d\n", tmp->id,
        tmp->tile->x, tmp->tile->y, inv.food, inv.linemate,
        inv.deraumere, inv.sibur, inv.mendiane, inv.phiras, inv.thystame);
    return 0;
}
