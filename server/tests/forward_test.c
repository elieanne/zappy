/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** forward_test.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void move_player(server_t *server, player_t *player, int x_of, int y_of);

Test(Forward, forwad_out_of_map_top, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = TOP;
    forward(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->tile->x, 0);
    cr_assert_eq(server->game.players->tile->y, 4);
}

Test(Forward, forwad_right, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = TOP;
    rotate_right(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->orientation, RIGHT);
    forward(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->tile->x, 1);
    cr_assert_eq(server->game.players->tile->y, 0);
}

Test(Forward, forwad_left, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = TOP;
    rotate_left(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->orientation, LEFT);
    forward(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->tile->x, 4);
    cr_assert_eq(server->game.players->tile->y, 0);
}

Test(Forward, forwad_bottom, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = TOP;
    rotate_right(server, server->game.players, cmds);
    rotate_right(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->orientation, BOTTOM);
    forward(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->tile->x, 0);
    cr_assert_eq(server->game.players->tile->y, 1);
}

Test(Forward, forwad_out_of_map_bottom, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = TOP;
    rotate_right(server, server->game.players, cmds);
    rotate_right(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->orientation, BOTTOM);
    forward(server, server->game.players, cmds);
    forward(server, server->game.players, cmds);
    forward(server, server->game.players, cmds);
    forward(server, server->game.players, cmds);
    forward(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->tile->x, 0);
    cr_assert_eq(server->game.players->tile->y, 0);
}

Test(Forward, forwad_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = TOP;
    forward(server, NULL, cmds);
    cr_assert_eq(server->game.players->tile->x, 0);
    cr_assert_eq(server->game.players->tile->y, 0);
}

Test(rotate_right, rotate_right, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = LEFT;
    rotate_right(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->orientation, TOP);
}

Test(rotate_right, rotate_right_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = LEFT;
    rotate_right(server, NULL, cmds);
    cr_assert_eq(server->game.players->orientation, LEFT);
}

Test(rotate_left, rotate_left, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = LEFT;
    rotate_left(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->orientation, BOTTOM);
}

Test(rotate_left, rotate_left_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = TOP;
    rotate_left(server, NULL, cmds);
    cr_assert_eq(server->game.players->orientation, TOP);
}

Test(move_player, move_player_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = TOP;
    move_player(server, NULL, 1, 0);
    cr_assert_eq(server->game.players->tile->x, 0);
    cr_assert_eq(server->game.players->tile->y, 0);
}

Test(move_player, move_player_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->id_list = remove_id_by_uuid(server->game.players->tile->id_list, server->game.players->id);
    server->game.players->orientation = TOP;
    move_player(server, server->game.players, 1, 0);
    cr_assert_eq(server->game.players->tile->x, 0);
    cr_assert_eq(server->game.players->tile->y, 0);
}
