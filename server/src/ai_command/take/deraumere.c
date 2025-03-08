/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** deraumere
*/

#include "zappy_server.h"

int take_deraumere(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->tile->inventory.deraumere <= 0)
        return 84;
    player->tile->inventory.deraumere -= 1;
    player->inventory.deraumere += 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 2, 1));
    return SUCCESS;
}

int drop_deraumere(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->inventory.deraumere <= 0)
        return 84;
    player->tile->inventory.deraumere += 1;
    player->inventory.deraumere -= 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 2, 0));
    return SUCCESS;
}

int get_nb_deraumere(map_t *map)
{
    int nb_deraumere = 0;

    if (!map)
        return -1;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            nb_deraumere += map->map[i][j].inventory.deraumere;
    }
    return nb_deraumere;
}
