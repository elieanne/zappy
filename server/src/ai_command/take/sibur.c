/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** sibur
*/

#include "zappy_server.h"

int take_sibur(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->tile->inventory.sibur <= 0)
        return 84;
    player->tile->inventory.sibur -= 1;
    player->inventory.sibur += 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 3, 1));
    return SUCCESS;
}

int drop_sibur(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->inventory.sibur <= 0)
        return 84;
    player->tile->inventory.sibur += 1;
    player->inventory.sibur -= 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 3, 0));
    return SUCCESS;
}

int get_nb_sibur(map_t *map)
{
    int nb_sibur = 0;

    if (!map)
        return -1;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            nb_sibur += map->map[i][j].inventory.sibur;
    }
    return nb_sibur;
}
