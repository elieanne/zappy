/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ai_command
*/

#include "../include/test.h"
#include "../include/ai_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int start_incantation(server_t *server, player_t *player);
int reset_elevation(server_t *server, player_t *player);
int level_up_players(server_t *server, player_t *player);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int init_map_test(map_t *map)
{
    if (!map)
        return -1;
    map->map = malloc(sizeof(tile_t *) * 5);
    for (int i = 0; i < 5; i++) {
        map->map[i] = malloc(sizeof(tile_t) * 5);
    }
    map->map[0][0] = (tile_t) {.inventory = { 1, 1, 0, 0, 0, 0, 0 }, .x = 0, .y = 0, .id_list = NULL };
    map->map[0][1] = (tile_t) {.inventory = { 1, 0, 0, 0, 0, 1, 0 }, .x = 1, .y = 0, .id_list = NULL };
    map->map[0][2] = (tile_t) {.inventory = { 1, 1, 1, 0, 0, 0, 0 }, .x = 2, .y = 0, .id_list = NULL };
    map->map[0][3] = (tile_t) {.inventory = { 1, 0, 0, 0, 0, 0, 0 }, .x = 3, .y = 0, .id_list = NULL };
    map->map[0][4] = (tile_t) {.inventory = { 1, 0, 0, 1, 0, 0, 0 }, .x = 4, .y = 0, .id_list = NULL };
    map->map[1][0] = (tile_t) {.inventory = { 0, 0, 0, 0, 0, 0, 0 }, .x = 0, .y = 1, .id_list = NULL };
    map->map[1][1] = (tile_t) {.inventory = { 0, 0, 0, 0, 0, 0, 0 }, .x = 1, .y = 1, .id_list = NULL };
    map->map[1][2] = (tile_t) {.inventory = { 0, 1, 0, 0, 0, 1, 0 }, .x = 2, .y = 1, .id_list = NULL };
    map->map[1][3] = (tile_t) {.inventory = { 0, 1, 1, 0, 0, 0, 0 }, .x = 3, .y = 1, .id_list = NULL };
    map->map[1][4] = (tile_t) {.inventory = { 1, 0, 0, 0, 0, 0, 0 }, .x = 4, .y = 1, .id_list = NULL };
    map->map[2][0] = (tile_t) {.inventory = { 1, 0, 0, 0, 0, 0, 0 }, .x = 0, .y = 2, .id_list = NULL };
    map->map[2][1] = (tile_t) {.inventory = { 1, 1, 0, 0, 0, 0, 0 }, .x = 1, .y = 2, .id_list = NULL };
    map->map[2][2] = (tile_t) {.inventory = { 1, 0, 0, 0, 0, 0, 0 }, .x = 2, .y = 2, .id_list = NULL };
    map->map[2][3] = (tile_t) {.inventory = { 1, 0, 0, 0, 0, 0, 0 }, .x = 3, .y = 2, .id_list = NULL };
    map->map[2][4] = (tile_t) {.inventory = { 0, 0, 0, 1, 0, 0, 0 }, .x = 4, .y = 2, .id_list = NULL };
    map->map[3][0] = (tile_t) {.inventory = { 0, 0, 0, 0, 0, 0, 1 }, .x = 0, .y = 3, .id_list = NULL };
    map->map[3][1] = (tile_t) {.inventory = { 0, 1, 1, 0, 0, 0, 0 }, .x = 1, .y = 3, .id_list = NULL };
    map->map[3][2] = (tile_t) {.inventory = { 0, 1, 0, 0, 0, 0, 0 }, .x = 2, .y = 3, .id_list = NULL };
    map->map[3][3] = (tile_t) {.inventory = { 1, 0, 0, 0, 0, 0, 0 }, .x = 3, .y = 3, .id_list = NULL };
    map->map[3][4] = (tile_t) {.inventory = { 1, 0, 0, 0, 0, 0, 0 }, .x = 4, .y = 3, .id_list = NULL };
    map->map[4][0] = (tile_t) {.inventory = { 1, 0, 0, 0, 1, 0, 0 }, .x = 0, .y = 4, .id_list = NULL };
    map->map[4][1] = (tile_t) {.inventory = { 0, 1, 0, 0, 0, 0, 0 }, .x = 1, .y = 4, .id_list = NULL };
    map->map[4][2] = (tile_t) {.inventory = { 1, 0, 0, 1, 0, 1, 0 }, .x = 2, .y = 4, .id_list = NULL };
    map->map[4][3] = (tile_t) {.inventory = { 1, 0, 0, 0, 0, 0, 0 }, .x = 3, .y = 4, .id_list = NULL };
    map->map[4][4] = (tile_t) {.inventory = { 1, 1, 0, 0, 0, 0, 0 }, .x = 4, .y = 4, .id_list = NULL };
    return 0;
}

server_t *init_server_test()
{
    player_t *player;
    server_t *server = malloc(sizeof(server_t));
    if (!server)
        return NULL;
    server->game.freq = 100;
    server->game.is_win = false;
    server->game.team_slot = NULL;
    server->game.team_names = NULL;
    server->game.teams_nb = 0;
    server->game.food_respawn = 0;
    server->game.players = NULL;
    server->game.map.width = 5;
    server->game.map.height = 5;
    server->game.map.map = NULL;
    if (init_map_test(&server->game.map) == -1)
        return NULL;
    player = init_player_pos(0, &server->game, 0, 0);
    player->type = PLAYER;
    player->inventory.food = 10;
    player->fd = 1;
    server->game.players = add_player_back(server->game.players, player);
    return server;
}

Test(incantation, incantation_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = finish_incantation(server, server->game.players, cmds);
    cr_assert_eq(result, 0);
}

Test(incantation, incantation_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    forward(server, server->game.players, cmds);
    int result = finish_incantation(server, server->game.players, cmds);
    cr_assert_eq(result, 84);
}

Test(incantation, incantation_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    int result = finish_incantation(server, server->game.players, NULL);
    cr_assert_eq(result, 84);
}

Test(incantation, incantation_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    int result = finish_incantation(server, server->game.players, cmds);
    cr_assert_eq(result, 84);
}

Test(start_incantation, start_incantation_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    forward(server, server->game.players, cmds);
    int result = start_incantation(server, NULL);
    cr_assert_eq(result, 84);
}

Test(reset_elevation, reset_elevation, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *player = init_player_pos(0, &server->game, 0, 0);
    player->fd = STDERR_FILENO;
    server->game.players = add_player_back(server->game.players, player);
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->elevating = true;
    reset_elevation(server, server->game.players);
    cr_assert_stderr_eq_str("ko\n");
    cr_assert_eq(server->game.players->elevating, false);
}

Test(reset_elevation, reset_elevation_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->elevating = true;
    reset_elevation(server, NULL);
    cr_assert_eq(server->game.players->elevating, true);
}

Test(level_up_player, level_up_player, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->elevating = true;
    level_up_players(server, server->game.players);
    cr_assert_stdout_eq_str("Current level: 2\n");
    cr_assert_eq(server->game.players->elevating, false);
    cr_assert_eq(server->game.players->level, 2);
}

Test(level_up_player, level_up_player_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->elevating = true;
    level_up_players(NULL, server->game.players);
    cr_assert_eq(server->game.players->elevating, true);
    cr_assert_eq(server->game.players->level, 1);
}

Test(get_player_on_tile, get_player_on_tile_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(get_player_on_tile(NULL, NULL, 1), 0);
}

Test(remove_resources, remove_resources_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(remove_resources(NULL, 1), ERROR);
}

Test(check_incantation, check_incantation_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *player = init_player_pos(0, &server->game, 0, 0);
    player->type = PLAYER;
    server->game.players = add_player_back(server->game.players, player);
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(check_incantation(server, server->game.players), false);
}

Test(check_incantation, check_incantation_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(check_incantation(NULL, server->game.players), false);
}

Test(check_incantation, check_incantation_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.deraumere = 1;
    cr_assert_eq(check_incantation(server, server->game.players), false);
}

Test(check_incantation, check_incantation_invalid_4, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.sibur = 1;
    cr_assert_eq(check_incantation(server, server->game.players), false);
}

Test(check_incantation, check_incantation_invalid_5, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.mendiane = 1;
    cr_assert_eq(check_incantation(server, server->game.players), false);
}

Test(check_incantation, check_incantation_invalid_6, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.phiras = 1;
    cr_assert_eq(check_incantation(server, server->game.players), false);
}

Test(check_incantation, check_incantation_invalid_7, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.thystame = 1;
    cr_assert_eq(check_incantation(server, server->game.players), false);
}
