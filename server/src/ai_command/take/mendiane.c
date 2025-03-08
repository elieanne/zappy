/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** mendiane
*/

#include "zappy_server.h"

int take_mendiane(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->tile->inventory.mendiane <= 0)
        return 84;
    player->tile->inventory.mendiane -= 1;
    player->inventory.mendiane += 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 4, 1));
    return SUCCESS;
}

int drop_mendiane(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->inventory.mendiane <= 0)
        return 84;
    player->tile->inventory.mendiane += 1;
    player->inventory.mendiane -= 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 4, 0));
    return SUCCESS;
}

int get_nb_mendiane(map_t *map)
{
    int nb_mendiane = 0;

    if (!map)
        return -1;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            nb_mendiane += map->map[i][j].inventory.mendiane;
    }
    return nb_mendiane;
}
