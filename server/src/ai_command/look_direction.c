/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** look_direction
*/

#include "zappy_server.h"

char *look_top(server_t *server, player_t *player, char *str)
{
    tile_t *tile = NULL;
    int player_level = 0;
    bool first_occ = true;
    if (!server || !player || !player->tile || !str)
        return NULL;

    player_level = player->level;
    for (int i = 0; i <= player_level; i++) {
        for (int j = -i; j <= i; j++) {
            tile = find_tile(&server->game, player->tile->x + j,
            player->tile->y - i);
            str = my_strcat(str, (first_occ ? "" : ","));
            str = get_tile_content(tile, player, server->game.players, str);
            first_occ = false;
        }
    }
    return str;
}

char *look_bot(server_t *server, player_t *player, char *str)
{
    tile_t *tile = NULL;
    int player_level = 0;
    bool first_occ = true;
    if (!server || !player || !player->tile || !str)
        return NULL;

    player_level = player->level;
    for (int i = 0; i <= player_level; i++) {
        for (int j = -i; j <= i; j++) {
            tile = find_tile(&server->game, player->tile->x - j,
            player->tile->y + i);
            str = my_strcat(str, (first_occ ? "" : ","));
            str = get_tile_content(tile, player, server->game.players, str);
            first_occ = false;
        }
    }
    return str;
}

char *look_right(server_t *server, player_t *player, char *str)
{
    tile_t *tile = NULL;
    int player_level = 0;
    bool first_occ = true;
    if (!server || !player || !player->tile || !str)
        return NULL;

    player_level = player->level;
    for (int i = 0; i <= player_level; i++) {
        for (int j = -i; j <= i; j++) {
            tile = find_tile(&server->game, player->tile->x + i,
            player->tile->y + j);
            str = my_strcat(str, (first_occ ? "" : ","));
            str = get_tile_content(tile, player, server->game.players, str);
            first_occ = false;
        }
    }
    return str;
}

char *look_left(server_t *server, player_t *player, char *str)
{
    tile_t *tile = NULL;
    int player_level = 0;
    bool first_occ = true;
    if (!server || !player || !player->tile || !str)
        return NULL;

    player_level = player->level;
    for (int i = 0; i <= player_level; i++) {
        for (int j = -i; j <= i; j++) {
            tile = find_tile(&server->game, player->tile->x - i,
            player->tile->y - j);
            str = my_strcat(str, (first_occ ? "" : ","));
            str = get_tile_content(tile, player, server->game.players, str);
            first_occ = false;
        }
    }
    return str;
}
