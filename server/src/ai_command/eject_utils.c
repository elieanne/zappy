/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** eject_utils
*/

#include "zappy_server.h"

void handle_egg(server_t *server, player_t *tmp_player)
{
    if (!server || !tmp_player || tmp_player->was_egg == false)
        return;
    tmp_player->type = DEAD;
    tmp_player->was_egg = true;
    server->game.team_slot[tmp_player->team] -= 1;
    tmp_player->tile->id_list =
    remove_id_by_uuid(tmp_player->tile->id_list, tmp_player->id);
    remove_dead_players(server);
}

char *get_eject_info(player_t *player)
{
    char *result = NULL;
    if (!player)
        return NULL;
    result = malloc(sizeof(char) * 16);
    sprintf(result, "pex %d\n", player->id);
    return result;
}

int switch_direction(int dir)
{
    if (dir == TOP)
        return BOTTOM;
    if (dir == BOTTOM)
        return TOP;
    if (dir == LEFT)
        return RIGHT;
    if (dir == RIGHT)
        return LEFT;
    return ERROR;
}
