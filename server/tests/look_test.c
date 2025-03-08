/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** look.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(look, look_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    look(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("[ player food linemate, linemate, food phiras, ]\n");
}

Test(look, look_valid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = TOP;
    look(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("[ player food linemate, food linemate, food mendiane, linemate ]\n");
}

Test(look, look_valid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = BOTTOM;
    look(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("[ player food linemate,,, food ]\n");
}

Test(look, look_valid_4, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = LEFT;
    look(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("[ player food linemate, food, food sibur, food linemate ]\n");
}

Test(look, look_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(look(server, NULL, cmds), ERROR);
}

Test(find_tile, find_tile_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.map.map = NULL;
    cr_assert_eq(find_tile(&server->game, 0, 0), NULL);
}

Test(my_strcat, my_strcat_invalid, .init=redirect_all_stdout)
{
    char *base = strdup("coucou");
    cr_assert_str_eq(my_strcat(base, NULL), "coucou");
}

Test(my_strcat, my_strcat_valid, .init=redirect_all_stdout)
{
    char *base = strdup("coucou");
    cr_assert_str_eq(my_strcat(base, " coucou"), "coucou coucou");
}

Test(fill_tile_content, fill_tile_content_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(fill_tile_content(NULL, NULL), NULL);
}

Test(fill_content, fill_content_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(fill_content(NULL, NULL), NULL);
}

Test(get_tile_content, get_tile_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(get_tile_content(NULL, NULL, NULL, NULL), NULL);
}

Test(look_top, look_top_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(look_top(NULL, NULL, NULL), NULL);
}

Test(look_bot, look_bot_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(look_bot(NULL, NULL, NULL), NULL);
}

Test(look_right, look_right_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(look_right(NULL, NULL, NULL), NULL);
}

Test(look_left, look_left_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(look_left(NULL, NULL, NULL), NULL);
}
