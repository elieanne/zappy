/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** client_handler_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(add_client, add_client_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->all_co[0].fd = -1;
    server->all_co[0].id = -1;
    server->all_co[0].buffer = NULL;
    add_client(server, 1, 0);
    cr_assert_stdout_eq_str("WELCOME\n");
    cr_assert_eq(server->all_co[0].fd, 1);
    cr_assert_eq(server->all_co[0].id, -1);
    cr_assert_eq(server->all_co[0].buffer[0], NULL);
}

Test(add_client, add_client_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->all_co[0].fd = 1;
    server->all_co[0].id = -1;
    server->all_co[0].buffer = NULL;
    cr_assert_eq(add_client(server, 1, 0), ERROR);
}

Test(remove_client, remove_client_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->all_co[0].fd = 1;
    server->all_co[0].id = 0;
    server->all_co[0].buffer = NULL;
    remove_client(server, 0);
    cr_assert_eq(server->all_co[0].fd, -1);
    cr_assert_eq(server->all_co[0].id, -1);
    cr_assert_eq(server->game.players->type, DEAD);
    cr_assert_eq(server->game.players->fd, -1);
    cr_assert_eq(server->game.players->client_index, -1);
}

Test(remove_client, remove_client_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->all_co[0].fd = 1;
    server->all_co[0].id = 2;
    server->all_co[0].buffer = NULL;
    server->game.players->type = PLAYER;
    remove_client(server, 0);
    cr_assert_eq(server->all_co[0].fd, -1);
    cr_assert_eq(server->all_co[0].id, -1);
    cr_assert_eq(server->game.players->type, PLAYER);
    cr_assert_eq(server->game.players->fd, 1);
}

Test(get_connection_info, get_connection_info_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(get_connection_info(NULL, NULL), NULL);
}

Test(get_connection_info, get_connection_info_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = EGG;
    server->game.team_names = malloc(sizeof(char *) * 2);
    server->game.team_names[0] = NULL;
    server->game.team_names[1] = NULL;
    cr_assert_eq(get_connection_info(server->game.players, &server->game), NULL);
}

Test(get_connection_info, get_connection_info_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->was_egg = true;
    server->game.team_names = malloc(sizeof(char *) * 2);
    server->game.team_names[0] = strdup("team1");
    server->game.team_names[1] = NULL;
    cr_assert_str_eq(get_connection_info(server->game.players, &server->game), "ebo 0\n");
}

Test(init_connection_sequence, init_connection_sequence_invalid_4, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->all_co[0].fd = 1;
    server->game.players->was_egg = true;
    server->game.team_names = malloc(sizeof(char *) * 2);
    server->game.team_names[0] = strdup("team1");
    server->game.team_names[1] = NULL;
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 0;
    init_connection_sequence(server, 0, 0);
    cr_assert_stdout_eq_str("ko\n");
}
