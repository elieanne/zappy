/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** fork
*/

#include "zappy_server.h"

char *get_egg_infos(player_t *egg, player_t *player)
{
    char *result = NULL;
    if (!player || !egg || !egg->tile)
        return NULL;
    result = malloc(sizeof(char) * 50);
    sprintf(result, "enw %d %d %d %d\n", egg->id, player->id, egg->tile->x,
        egg->tile->y);
    return result;
}

char *get_player_infos(player_t *player)
{
    char *result = NULL;
    if (!player)
        return NULL;
    result = malloc(sizeof(char) * 16);
    sprintf(result, "pfk %d\n", player->id);
    return result;
}

bool is_valid_fork(server_t *server, player_t *player, char **cmds)
{
    if (!server || !player || !cmds)
        return false;
    if (get_command_size(cmds) != 1)
        return false;
    send_gui_event(server->game.players, get_player_infos(player));
    return true;
}

int fork_cmd(server_t *server, player_t *player, char** cmds)
{
    player_t *egg = NULL;
    if (!player)
        return ERROR;
    if (!server || !server->game.players || cmds[1])
        return ERROR;
    egg = init_player_pos(
    player->team, &server->game, player->tile->x, player->tile->y);
    if (!egg)
        return ERROR;
    egg->was_egg = true;
    egg->orientation = player->orientation;
    server->game.players = add_player_back(server->game.players, egg);
    server->game.team_slot[player->team]++;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_egg_infos(egg, player));
    return 0;
}
