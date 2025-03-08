/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** linemate
*/

#include "zappy_server.h"

int take_linemate(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->tile->inventory.linemate <= 0)
        return 84;
    player->tile->inventory.linemate -= 1;
    player->inventory.linemate += 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 1, 1));
    return SUCCESS;
}

int drop_linemate(player_t *player, server_t *server)
{
    printf("try to drop");
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->inventory.linemate <= 0)
        return 84;
    player->tile->inventory.linemate += 1;
    player->inventory.linemate -= 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 1, 0));
    return SUCCESS;
}

int get_nb_linemate(map_t *map)
{
    int nb_linemate = 0;

    if (!map)
        return -1;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            nb_linemate += map->map[i][j].inventory.linemate;
    }
    return nb_linemate;
}
