/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game_init
*/

#include "zappy_server.h"
#include <string.h>

void init_tile(tile_t *tile, int x, int y)
{
    tile->x = x;
    tile->y = y;
    tile->inventory.food = 0;
    tile->inventory.deraumere = 0;
    tile->inventory.linemate = 0;
    tile->inventory.mendiane = 0;
    tile->inventory.sibur = 0;
    tile->inventory.phiras = 0;
    tile->inventory.thystame = 0;
    tile->id_list = NULL;
}

int init_game_map(parsed_info_t *parse_info, game_t *game)
{
    if (!game || !parse_info || !parse_info->width || !parse_info->height)
        return 84;
    game->map.height = atoi(parse_info->height);
    game->map.width = atoi(parse_info->width);
    if (game->map.width < 1 || game->map.height < 1)
        return 84;
    game->map.map = malloc(sizeof(tile_t *) * game->map.height);
    if (!game->map.map)
        return 84;
    for (int i = 0; i < game->map.height; i++) {
        game->map.map[i] = malloc(sizeof(tile_t) * game->map.width);
        if (!game->map.map[i])
            return 84;
        for (int j = 0; j < game->map.width; j++)
            init_tile(&game->map.map[i][j], j, i);
    }
    return 0;
}

void init_player_list(game_t *game)
{
    for (int i = 0; i < game->teams_nb; i++) {
        for (int j = 0; j < game->max_client; j++) {
            game->players = add_player_back(game->players,
            init_player(i, game));
        }
    }
}

int init_game_struct(game_t *game, parsed_info_t *parsed)
{
    int max_player = 0;
    int team_nb = 0;
    if (!game || !parsed || !parsed->clients_nb || !parsed->names)
        return 84;
    max_player = atoi(parsed->clients_nb);
    while (parsed->names[team_nb])
        team_nb++;
    if (max_player < 1 || team_nb < 1)
        return 84;
    game->is_win = false;
    game->teams_nb = team_nb;
    game->max_client = max_player;
    game->team_slot = malloc(sizeof(int) * team_nb);
    for (int i = 0; i < team_nb; i++)
        game->team_slot[i] = max_player;
    game->team_names = parsed->names;
    if (!parsed->freq || (game->freq = atoi(parsed->freq)) < 1)
        game->freq = 100;
    game->food_respawn = 0;
    return 0;
}

int init_game(server_t *server, parsed_info_t *parsed_info)
{
    if (!server || !parsed_info)
        return ERROR;
    server->game.players = NULL;
    server->game.team_slot = NULL;
    server->game.team_names = NULL;
    server->game.map.map = NULL;
    server->game.map.height = 0;
    server->game.map.width = 0;
    server->game.max_client = 0;
    if (init_game_struct(&server->game, parsed_info) == 84) {
        free_game_struct(server, parsed_info);
        return ERROR;
    }
    if (init_game_map(parsed_info, &server->game) == 84) {
        exit_program(server, parsed_info);
        return ERROR;
    }
    return SUCCESS;
}
