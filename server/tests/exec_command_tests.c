/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** exec_command_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(exec_command, exec_command_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("Forward");
    server->game.players->current_cmd = NULL;
    cr_assert_eq(exec_command(server, server->game.players), SUCCESS);
    cr_assert_str_eq(server->game.players->current_cmd, "Forward");
    cr_assert_eq(server->game.players->cooldown, 7);
}

Test(exec_command, exec_command_valid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->current_cmd = strdup("Forward");
    cr_assert_eq(exec_command(server, server->game.players), SUCCESS);
    cr_assert_stdout_eq_str("ok\n");
}

Test(exec_command, exec_command_valid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = GUI;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->current_cmd = strdup("msz");
    cr_assert_eq(exec_command(server, server->game.players), SUCCESS);
    cr_assert_stdout_eq_str("msz 5 5\n");
}

Test(exec_command, exec_command_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->current_cmd = strdup("msz");
    cr_assert_eq(exec_command(server, server->game.players), SUCCESS);
    cr_assert_stdout_eq_str("ko\n");
}

Test(exec_command, exec_command_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->current_cmd = strdup("Forward");
    server->game.players->cooldown = 1;
    cr_assert_eq(exec_command(server, server->game.players), ERROR);
}

Test(exec_command, exec_command_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->current_cmd = strdup("Forward");
    server->game.players->elevating = true;
    cr_assert_eq(exec_command(server, server->game.players), ERROR);
}

Test(exec_command, exec_command_invalid_4, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = GUI;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("azeaze");
    cr_assert_eq(exec_command(server, server->game.players), ERROR);
    cr_assert_stdout_eq_str("suc\n");
}

Test(exec_command, exec_command_invalid_5, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = GUI;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("msz 1");
    cr_assert_eq(exec_command(server, server->game.players), ERROR);
    cr_assert_stdout_eq_str("sbp\n");
}

Test(exec_command, exec_command_invalid_6, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("azeaze");
    cr_assert_eq(exec_command(server, server->game.players), ERROR);
    cr_assert_stdout_eq_str("ko\n");
}

Test(exec_command, exec_command_invalid_7, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("Forward 1");
    cr_assert_eq(exec_command(server, server->game.players), ERROR);
    cr_assert_stdout_eq_str("ko\n");
}

Test(exec_command, exec_command_invalid_8, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->current_cmd = strdup(" \n");
    cr_assert_eq(exec_command(server, server->game.players), ERROR);
}

Test(exec_command, exec_command_invalid_9, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->current_cmd = strdup("Take deraumere");
    cr_assert_eq(exec_command(server, server->game.players), SUCCESS);
    cr_assert_stdout_eq_str("ko\n");
}

Test(exec_command, exec_command_invalid_10, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = GUI;
    server->game.players->current_cmd = strdup("azeaze");
    cr_assert_eq(exec_command(server, server->game.players), SUCCESS);
    cr_assert_stdout_eq_str("suc\n");
}

Test(is_cmd_valid, is_cmd_valid_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = NULL;
    cr_assert_eq(is_cmd_valid(server, server->game.players), ERROR);
}
