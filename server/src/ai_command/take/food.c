/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** food
*/

#include "zappy_server.h"

int take_food(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->tile->inventory.food <= 0)
        return 84;
    player->tile->inventory.food -= 1;
    player->inventory.food += 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 0, 1));
    return SUCCESS;
}

int drop_food(player_t *player, server_t *server)
{
    if (!player || !player->tile || !server)
        return ERROR;
    if (player->inventory.food <= 0)
        return 84;
    player->tile->inventory.food += 1;
    player->inventory.food -= 1;
    send_ok(player->fd);
    send_gui_event(server->game.players, get_take_drop_info(player, 0, 0));
    return SUCCESS;
}

int get_nb_food(map_t *map)
{
    int nb_food = 0;

    if (!map)
        return -1;
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++)
            nb_food += map->map[i][j].inventory.food;
    }
    return nb_food;
}
