/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** player_position.c
*/

#include "gui_command.h"

bool is_valid_ppo(server_t *server, player_t *player, char **cmds)
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

int gui_player_pos_event(player_t* player_list, player_t *player)
{
    player_t *tmp = NULL;
    if (!player_list || !player)
        return -1;
    tmp = player_list;
    while (tmp != NULL) {
        if (tmp->type != GUI) {
            tmp = tmp->next;
            continue;
        }
        dprintf(tmp->fd, "ppo %d %d %d %d\n", player->id, player->tile->x,
            player->tile->y, player->orientation);
        tmp = tmp->next;
    }
    return 0;
}

int gui_player_pos(server_t *server, player_t *player, char **cmds)
{
    player_t *tmp = NULL;
    int id = -1;
    if (!server || !player || !cmds)
        return -1;
    id = (int) strtol(cmds[1], NULL, 10);
    tmp = find_player_by_uuid(server->game.players, id);
    if (!tmp || tmp->type != PLAYER)
        return -1;
    dprintf(player->fd, "ppo %d %d %d %d\n", tmp->id, tmp->tile->x,
    tmp->tile->y, tmp->orientation);
    return 0;
}
