/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** check_valid.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(is_valid_inventory, is_valid_inventory_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_inv(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_inventory, is_valid_inventory_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_inv(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_inventory, is_valid_inventory_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_inv(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_one_arg, is_valid_one_arg_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_one_arg(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_one_arg, is_valid_one_arg_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_one_arg(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_one_arg, is_valid_one_arg_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_one_arg(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_take, is_valid_take_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_take(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_take, is_valid_take_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_take(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_take, is_valid_take_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_take(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_fork, is_valid_fork_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_fork(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_fork, is_valid_fork_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_fork(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_fork, is_valid_fork_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_fork(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_broadcast, is_valid_broadcast_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_broadcast(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_broadcast, is_valid_broadcast_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_broadcast(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_broadcast, is_valid_broadcast_valid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_broadcast(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_incantation, is_valid_incantation_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_incantation(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_incantation, is_valid_incantation_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_incantation(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_incantation, is_valid_incantation_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_incantation(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_incantation, is_valid_incantation_invalid_3, .init=redirect_all_stdout)
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
    int result = is_valid_incantation(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_pin, is_valid_pin_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("0");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_pin(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_pin, is_valid_pin_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("ert");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_pin(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_pin, is_valid_pin_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_pin(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_pin, is_valid_pin_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("0");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_pin(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_ppo, is_valid_ppo_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("0");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_ppo(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_ppo, is_valid_ppo_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("ert");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_ppo(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_ppo, is_valid_ppo_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_ppo(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_ppo, is_valid_ppo_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("0");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_ppo(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_lvl, is_valid_lvl_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("0");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_lvl(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_lvl, is_valid_lvl_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("ert");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_lvl(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_lvl, is_valid_lvl_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_lvl(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_lvl, is_valid_lvl_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("0");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_lvl(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_sst, is_valid_sst_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("2");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_sst(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_sst, is_valid_sst_valid_4, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("1");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_sst(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_sst, is_valid_sst_invalid_5, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("10001");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_sst(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_sst, is_valid_sst_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("ert");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_sst(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_sst, is_valid_sst_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_sst(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_sst, is_valid_sst_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("0");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_sst(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_sst, is_valid_sst_invalid_4, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("-1");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_sst(server, server->game.players, NULL);
    cr_assert_eq(result, false);
}

Test(is_valid_bct, is_valid_bct_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 4);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("1");
    cmds[2] = strdup("1");
    cmds[3] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_bct(server, server->game.players, cmds);
    cr_assert_eq(result, true);
}

Test(is_valid_bct, is_valid_bct_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 4);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("-1");
    cmds[2] = strdup("1");
    cmds[3] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_bct(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_bct, is_valid_bct_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 4);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("6");
    cmds[2] = strdup("1");
    cmds[3] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_bct(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}

Test(is_valid_bct, is_valid_bct_invalid_4, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 5);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("6");
    cmds[2] = strdup("1");
    cmds[3] = strdup("1");
    cmds[4] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = is_valid_bct(server, server->game.players, cmds);
    cr_assert_eq(result, false);
}
