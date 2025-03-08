/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** gui_player_level.c
*/

#include "zappy_server.h"

bool is_valid_lvl(server_t *server, player_t *player, char **cmds)
{
    (void) player;
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

int gui_player_lvl(server_t *server, player_t *player, char **cmds)
{
    player_t *tmp = NULL;
    int id = -1;
    if (!server || !player || !cmds)
        return -1;
    id = (int) strtol(cmds[1], NULL, 10);
    tmp = find_player_by_uuid(server->game.players, id);
    if (!tmp || tmp->type != PLAYER)
        return -1;
    dprintf(player->fd, "plv %d %d\n", tmp->id, tmp->level);
    return 0;
}

void gui_player_lvl_event(player_t *player_list, player_t *player)
{
    player_t *tmp = NULL;
    if (!player || !player_list)
        return;
    tmp = player_list;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type != GUI)
            continue;
        dprintf(tmp->fd, "plv %d %d\n", player->id, player->level);
    }
}
