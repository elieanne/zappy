/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** rotate_commands
*/

#include "zappy_server.h"

int rotate_right(server_t *server, player_t *player, char** cmds)
{
    (void) server;
    (void) cmds;
    if (!player)
        return ERROR;

    if (player->orientation == LEFT)
        player->orientation = TOP;
    else
        player->orientation += 1;
    send_ok(player->fd);
    gui_player_pos_event(server->game.players, player);
    return SUCCESS;
}

int rotate_left(server_t *server, player_t *player, char** cmds)
{
    (void) server;
    (void) cmds;
    if (!player)
        return ERROR;

    if (player->orientation == TOP)
        player->orientation = LEFT;
    else
        player->orientation -= 1;
    send_ok(player->fd);
    gui_player_pos_event(server->game.players, player);
    return SUCCESS;
}

void move_player(server_t *server, player_t *player, int x_of, int y_of)
{
    int new_y = 0;
    int new_x = 0;
    tile_t *old_tile = NULL;
    user_id_t *tmp = NULL;
    if (!player || !player->tile || !server || !server->game.map.map)
        return;
    old_tile = player->tile;
    tmp = find_id_by_uuid(old_tile->id_list, player->id);
    if (!tmp)
        return;
    old_tile->id_list = remove_id_by_uuid(old_tile->id_list, player->id);
    tmp->next = NULL;
    new_x = player->tile->x + x_of;
    new_y = player->tile->y + y_of;
    new_x = mod(new_x, server->game.map.width);
    new_y = mod(new_y, server->game.map.height);
    if (!server->game.map.map[new_y])
        return;
    player->tile = &server->game.map.map[new_y][new_x];
    player->tile->id_list = add_id_back(player->tile->id_list, tmp);
}

int forward(server_t *server, player_t *player, char** cmds)
{
    (void) cmds;
    if (!player || !player->tile || !server || !server->game.map.map)
        return ERROR;
    switch (player->orientation) {
        case TOP:
            move_player(server, player, 0, -1);
            break;
        case RIGHT:
            move_player(server, player, 1, 0);
            break;
        case BOTTOM:
            move_player(server, player,0, 1);
            break;
        case LEFT:
            move_player(server, player, -1, 0);
            break;
    }
    gui_player_pos_event(server->game.players, player);
    send_ok(player->fd);
    return SUCCESS;
}
