/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** look
*/

#include "zappy_server.h"
#include "ai_command.h"

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

tile_t *find_tile(game_t *game, int x, int y)
{
    if (!game || !game->map.map)
        return NULL;

    x = mod(x, game->map.width);
    y = mod(y, game->map.height);
    if (!game->map.map[y])
        return NULL;
    return &game->map.map[y][x];
}

int look(server_t *server, player_t *player,
__attribute__((unused)) char** cmds)
{
    char *str = NULL;
    if (!player || !server->game.players)
        return ERROR;
    str = my_strcat(str, "[ ");
    if (player->orientation == TOP)
        str = look_top(server, player, str);
    if (player->orientation == BOTTOM)
        str = look_bot(server, player, str);
    if (player->orientation == RIGHT)
        str = look_right(server, player, str);
    if (player->orientation == LEFT)
        str = look_left(server, player, str);
    str = my_strcat(str, " ]\n");
    dprintf(player->fd, "%s", str);
    free(str);
    return SUCCESS;
}
