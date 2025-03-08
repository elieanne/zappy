/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** inventory_test.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(inventory, base_inventory, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    char expected[] = "[ food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0 ]\n";
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    ai_inventory(server, server->game.players, cmds);
    cr_assert_stdout_eq_str(expected);
}

Test(inventory, base_inventory_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = ai_inventory(server, server->game.players, NULL);
    cr_assert_eq(result, -1);
}
