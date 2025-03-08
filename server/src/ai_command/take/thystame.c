/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** thystame
*/

#include "zappy_server.h"

int take_thystame(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->tile->inventory.thystame <= 0)
        return 84;
    player->tile->inventory.thystame -= 1;
    player->inventory.thystame += 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 6, 1));
    return SUCCESS;
}

int drop_thystame(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->inventory.thystame <= 0)
        return 84;
    player->tile->inventory.thystame += 1;
    player->inventory.thystame -= 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 6, 0));
    return SUCCESS;
}

int get_nb_thystame(map_t *map)
{
    int nb_thystame = 0;

    if (!map)
        return -1;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            nb_thystame += map->map[i][j].inventory.thystame;
    }
    return nb_thystame;
}
