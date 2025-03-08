/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** gui_map.c
*/

#include "zappy_server.h"

bool is_valid_one_arg(server_t *server, player_t *player, char **cmds)
{
    if (!server || !player || !cmds)
        return false;
    if (get_command_size(cmds) != 1)
        return false;
    return true;
}

char *get_str_tile_content(tile_t tile)
{
    char *result = NULL;
    inventory_t inv;
    result = malloc(sizeof(char) * 113);
    if (!result)
        return NULL;
    inv = tile.inventory;
    sprintf(result, "bct %d %d %d %d %d %d %d %d %d\n", tile.x, tile.y,
        inv.food, inv.linemate, inv.deraumere, inv.sibur, inv.mendiane,
        inv.phiras, inv.thystame);
    return result;
}

int gui_map_size(server_t *server, player_t *player, char **cmds)
{
    map_t map;
    if (!server || !player || !cmds)
        return -1;
    map = server->game.map;
    dprintf(player->fd, "msz %d %d\n", map.width, map.height);
    return 0;
}

int gui_map_content(server_t *server, player_t *player, char **cmds)
{
    map_t map;
    char *result = NULL;
    char *tmp = NULL;
    if (!server || !player || !cmds)
        return -1;
    map = server->game.map;
    result = malloc(sizeof(char) * ((113 * map.width * map.height) + 1));
    result = memset(result, '\0', (113 * map.width * map.height) + 1);
    if (!result)
        return -1;
    for (int y = 0; y < map.height; y++) {
        for (int x = 0; x < map.width; x++) {
            tmp = get_str_tile_content(map.map[y][x]);
            result = strcat(result, tmp);
            free(tmp);
        }
    }
    dprintf(player->fd, "%s", result);
    free(result);
    return 0;
}

int gui_tile_content(server_t *server, player_t *player, char **cmds)
{
    char *tmp = NULL;
    int x = 0;
    int y = 0;
    if (!server || !player || !cmds)
        return -1;
    x = (int) strtoll(cmds[1], NULL, 10);
    y = (int) strtoll(cmds[2], NULL, 10);
    tmp = get_str_tile_content(server->game.map.map[y][x]);
    dprintf(player->fd, "%s", tmp);
    free(tmp);
    return 0;
}
