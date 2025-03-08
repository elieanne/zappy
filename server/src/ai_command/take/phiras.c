/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** phiras
*/

#include "zappy_server.h"

int take_phiras(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->tile->inventory.phiras <= 0)
        return 84;
    player->tile->inventory.phiras -= 1;
    player->inventory.phiras += 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 5, 1));
    return SUCCESS;
}

int drop_phiras(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->inventory.phiras <= 0)
        return 84;
    player->tile->inventory.phiras += 1;
    player->inventory.phiras -= 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 5, 0));
    return SUCCESS;
}

int get_nb_phiras(map_t *map)
{
    int nb_phiras = 0;

    if (!map)
        return -1;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            nb_phiras += map->map[i][j].inventory.phiras;
    }
    return nb_phiras;
}
