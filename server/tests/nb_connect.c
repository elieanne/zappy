/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** connect_nbr
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(connect_nbr, connect_nbr_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.teams_nb = 1;
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->game.players->orientation = RIGHT;
    connect_nbr(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("1\n");
}

Test(connect_nbr, connect_nbr_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(connect_nbr(server, NULL, NULL), ERROR);
}

Test(connect_nbr, connect_nbr_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->team = 2;
    server->game.teams_nb = 1;
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->game.players->orientation = RIGHT;
    cr_assert_eq(connect_nbr(server, server->game.players, cmds), ERROR);
}
