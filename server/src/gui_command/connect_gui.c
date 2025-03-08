/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** connect_gui.c
*/

#include "zappy_server.h"
#include "gui_connection.h"

char *format_server_freq(game_t *game)
{
    char *result = NULL;
    if (!game)
        return NULL;
    result = malloc(sizeof(char) * 16);
    sprintf(result, "sgt %d\n", game->freq);
    return result;
}

char *format_tile_info(game_t *game)
{
    char *result = NULL;
    char *tmp = NULL;
    if (!game)
        return NULL;
    for (int y = 0; y < game->map.height; y++) {
        for (int x = 0; x < game->map.width; x++) {
            tmp = get_str_tile_content(game->map.map[y][x]);
            result = my_strcat(result, tmp);
            free(tmp);
        }
    }
    return result;
}

int send_gui_information(server_t *server, player_t *player)
{
    char *result = NULL;
    char *tmp = NULL;
    int i = 0;
    game_t game;
    if (!server || !player)
        return -1;
    result = malloc(sizeof(char) * 12);
    if (!result)
        return -1;
    game = server->game;
    sprintf(result, "msz %d %d\n", game.map.width, game.map.height);
    while (steps[i].exec != NULL) {
        tmp = steps[i++].exec(&game);
        result = my_strcat(result, tmp);
        free(tmp);
    }
    dprintf(player->fd, "%s", result);
    send_existing_players(server, player);
    free(result);
    return 0;
}

int handle_gui_connection(const char *cmd, server_t *server, int index)
{
    if (!cmd || !server)
        return -1;
    if (server->all_co[index].is_player)
        return -1;
    if (!strcmp(cmd, "GRAPHIC")) {
        connect_gui(server, index);
        return 0;
    }
    return -1;
}

int connect_gui(server_t *server, int index)
{
    player_t *new = NULL;
    if (!server)
        return -1;
    new = init_player(-1, &server->game);
    if (!new)
        return -1;
    new->fd = server->all_co[index].fd;
    new->command_buffer = server->all_co[index].buffer;
    new->type = GUI;
    new->client_index = index;
    server->all_co[index].id = new->id;
    server->all_co[index].is_player = true;
    server->game.players = add_player_back(server->game.players, new);
    printf("GUI added\n");
    send_gui_information(server, new);
    return 0;
}
