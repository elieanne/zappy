/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game_init_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(init_game, init_game_valid, .init=redirect_all_stdout)
{
    server_t *server = malloc(sizeof(server_t));
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    parsed->height = "5";
    parsed->width = "5";
    parsed->clients_nb = "1";
    parsed->freq = "100";
    parsed->names = malloc(sizeof(char *) * 2);
    parsed->names[0] = "toto";
    parsed->names[1] = NULL;
    parsed->port = "4242";
    init_game(server, parsed);
    init_player_list(&server->game);
    cr_assert_eq(server->game.map.height, 5);
    cr_assert_eq(server->game.map.width, 5);
    cr_assert_str_eq(server->game.team_names[0], "toto");
    cr_assert_eq(server->game.freq, 100);
    cr_assert_eq(server->game.players[0].type, EGG);
}

Test(init_game, init_game_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(init_game_map(NULL, NULL), ERROR);
}

Test(init_game, init_game_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = malloc(sizeof(server_t));
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    parsed->height = "0";
    parsed->width = "0";
    parsed->clients_nb = "1";
    parsed->freq = "100";
    parsed->names = malloc(sizeof(char *) * 2);
    parsed->names[0] = "toto";
    parsed->names[1] = NULL;
    parsed->port = "4242";
    cr_assert_eq(init_game_map(parsed, &server->game), ERROR);
}

Test(init_game_struct, init_game_struct_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(init_game_struct(NULL, NULL), ERROR);
}

Test(init_game_struct, init_game_struct_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = malloc(sizeof(server_t));
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    parsed->height = "5";
    parsed->width = "5";
    parsed->clients_nb = "0";
    parsed->freq = "100";
    parsed->names = malloc(sizeof(char *) * 2);
    parsed->names[0] = "toto";
    parsed->names[1] = NULL;
    parsed->port = "4242";
    cr_assert_eq(init_game_struct(&server->game, parsed), ERROR);
}

Test(init_game_struct, init_game_struct_valid_2, .init=redirect_all_stdout)
{
    server_t *server = malloc(sizeof(server_t));
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    parsed->height = "5";
    parsed->width = "5";
    parsed->clients_nb = "1";
    parsed->freq = "0";
    parsed->names = malloc(sizeof(char *) * 2);
    parsed->names[0] = "toto";
    parsed->names[1] = NULL;
    parsed->port = "4242";
    cr_assert_eq(init_game_struct(&server->game, parsed), 0);
}

Test(init_game, init_game_invalid_3, .init=redirect_all_stdout)
{
    cr_assert_eq(init_game(NULL, NULL), ERROR);
}

Test(init_game, init_game_invalid_4, .init=redirect_all_stdout)
{
    server_t *server = malloc(sizeof(server_t));
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    parsed->height = "5";
    parsed->width = "5";
    parsed->clients_nb = "0";
    parsed->freq = "100";
    parsed->names = malloc(sizeof(char *) * 2);
    parsed->names[0] = strdup("toto");
    parsed->names[1] = NULL;
    parsed->port = "4242";
    cr_assert_eq(init_game(server, parsed), ERROR);
}

Test(init_game, init_game_invalid_5)
{
    server_t *server = malloc(sizeof(server_t));
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    parsed->height = "0";
    parsed->width = "0";
    parsed->clients_nb = "1";
    parsed->freq = "100";
    parsed->names = malloc(sizeof(char *) * 2);
    parsed->names[0] = strdup("toto");
    parsed->names[1] = NULL;
    parsed->port = "4242";
    cr_assert_eq(init_game(server, parsed), ERROR);
}

Test(init_player_inventory, init_player_inventory_invalid)
{
    cr_assert_eq(init_player_inventory(NULL), NULL);
}

Test(init_player, init_player_invalid)
{
    cr_assert_eq(init_player(0, NULL), NULL);
}

Test(spawn_ressources, spawn_ressources_invalid)
{
    cr_assert_eq(spawn_ressources(NULL), ERROR);
}

Test(spawn_ressources, spawn_ressources_valid)
{
    server_t *server = malloc(sizeof(server_t));
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    parsed->height = "5";
    parsed->width = "5";
    parsed->clients_nb = "1";
    parsed->freq = "100";
    parsed->names = malloc(sizeof(char *) * 2);
    parsed->names[0] = strdup("toto");
    parsed->names[1] = NULL;
    parsed->port = "4242";
    init_game(server, parsed);
    cr_assert_eq(spawn_ressources(&server->game), 0);
}

Test(spawn_linemate, spawn_linemate_invalid)
{
    cr_assert_eq(spawn_linemate(NULL, 0), ERROR);
}

Test(spawn_deraumere, spawn_deraumere_invalid)
{
    cr_assert_eq(spawn_deraumere(NULL, 0), ERROR);
}

Test(spawn_sibur, spawn_sibur_invalid)
{
    cr_assert_eq(spawn_sibur(NULL, 0), ERROR);
}

Test(spawn_mendiane, spawn_mendiane_invalid)
{
    cr_assert_eq(spawn_mendiane(NULL, 0), ERROR);
}

Test(spawn_phiras, spawn_phiras_invalid)
{
    cr_assert_eq(spawn_phiras(NULL, 0), ERROR);
}

Test(spawn_thystame, spawn_thystame_invalid)
{
    cr_assert_eq(spawn_thystame(NULL, 0), ERROR);
}

Test(spawn_food, spawn_food_invalid)
{
    cr_assert_eq(spawn_food(NULL, 0), ERROR);
}
