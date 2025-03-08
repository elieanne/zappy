/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** check_connection_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_connection_sequence, check_connection_sequence_ai, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_names = malloc(sizeof(char *) * 1);
    server->game.team_names[0] = strdup("team1");
    server->game.teams_nb = 1;
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->all_co[1].is_player = false;
    server->all_co[1].fd = 2;
    server->all_co[1].id = 0;
    server->all_co[1].buffer = init_cmd_buffer();
    server->all_co [1].buffer[0] = strdup("team1");
    check_connection_sequence(server);
    cr_assert_eq(server->all_co[1].fd, 2);
    cr_assert_eq(server->all_co[1].id, 0);
    cr_assert_stderr_eq_str("0\n5 5\n");
}

Test(check_connection_sequence, check_connection_sequence_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_names = malloc(sizeof(char *) * 1);
    server->game.team_names[0] = strdup("team1");
    server->game.teams_nb = 1;
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->all_co[1].is_player = false;
    server->all_co[1].fd = 2;
    server->all_co[1].id = 0;
    server->all_co[1].buffer = init_cmd_buffer();
    server->all_co [1].buffer[0] = strdup("team1azez");
    check_connection_sequence(server);
    cr_assert_eq(server->all_co[1].fd, 2);
    cr_assert_eq(server->all_co[1].id, 0);
    cr_assert_stderr_eq_str("ko\n");
}

Test(check_connection_sequence, check_connection_sequence_gui, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = 1;
    server->game.team_names = malloc(sizeof(char*) * 1);
    server->game.team_names[0] = strdup("team1");
    server->game.teams_nb = 1;
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->all_co[1].is_player = false;
    server->all_co[1].fd = 2;
    server->all_co[1].id = 0;
    server->all_co[1].buffer = init_cmd_buffer();
    server->all_co [1].buffer[0] = strdup("GRAPHIC");
    check_connection_sequence(server);
    cr_assert_stderr_eq_str("msz 5 5\nsgt 100\n"
                            "bct 0 0 1 1 0 0 0 0 0\n"
                            "bct 1 0 1 0 0 0 0 1 0\n"
                            "bct 2 0 1 1 1 0 0 0 0\n"
                            "bct 3 0 1 0 0 0 0 0 0\n"
                            "bct 4 0 1 0 0 1 0 0 0\n"
                            "bct 0 1 0 0 0 0 0 0 0\n"
                            "bct 1 1 0 0 0 0 0 0 0\n"
                            "bct 2 1 0 1 0 0 0 1 0\n"
                            "bct 3 1 0 1 1 0 0 0 0\n"
                            "bct 4 1 1 0 0 0 0 0 0\n"
                            "bct 0 2 1 0 0 0 0 0 0\n"
                            "bct 1 2 1 1 0 0 0 0 0\n"
                            "bct 2 2 1 0 0 0 0 0 0\n"
                            "bct 3 2 1 0 0 0 0 0 0\n"
                            "bct 4 2 0 0 0 1 0 0 0\n"
                            "bct 0 3 0 0 0 0 0 0 1\n"
                            "bct 1 3 0 1 1 0 0 0 0\n"
                            "bct 2 3 0 1 0 0 0 0 0\n"
                            "bct 3 3 1 0 0 0 0 0 0\n"
                            "bct 4 3 1 0 0 0 0 0 0\n"
                            "bct 0 4 1 0 0 0 1 0 0\n"
                            "bct 1 4 0 1 0 0 0 0 0\n"
                            "bct 2 4 1 0 0 1 0 1 0\n"
                            "bct 3 4 1 0 0 0 0 0 0\n"
                            "bct 4 4 1 1 0 0 0 0 0\n"
                            "tna team1\n"
                            "pnw 0 0 0 1 1 team1\n"
                            "");
}

Test(check_connection_sequence, check_connection_sequence_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->all_co[1].buffer = init_cmd_buffer();
    server->all_co [1].buffer[0] = strdup("GRAPHIC");
    check_connection_sequence(NULL);
    cr_assert_str_eq(server->all_co [1].buffer[0], "GRAPHIC");
}

Test(check_connection_sequence, check_connection_sequence_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_names = malloc(sizeof(char *) * 1);
    server->game.team_names[0] = strdup("team1");
    server->game.teams_nb = 1;
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->all_co[1].is_player = true;
    server->all_co[1].fd = 2;
    server->all_co[1].id = 0;
    server->all_co[1].buffer = init_cmd_buffer();
    server->all_co [1].buffer[0] = strdup("team1");
    check_connection_sequence(server);
    cr_assert_str_eq(server->all_co [1].buffer[0], "team1");
}

Test(check_ai_co, check_ai_co_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("team1");
    cmds[1] = strdup("team1");
    cmds[2] = NULL;
    cr_assert_eq(check_ai_co(server, cmds, 1), -1);
}

Test(check_gui_co, check_gui_co_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("GRAPHIC");
    cmds[1] = strdup("GRAPHIC");
    cmds[2] = NULL;
    cr_assert_eq(check_gui_co(server, cmds, 1), -1);
}

Test(connect_gui, connect_gui_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(connect_gui(NULL, 1), -1);
}

Test(format_server_freq, format_server_freq_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(format_server_freq(NULL), NULL);
}

Test(format_tile_info, format_tile_info_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(format_tile_info(NULL), NULL);
}

Test(send_gui_info, send_gui_info_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(send_gui_information(NULL, NULL), -1);
}

Test(handle_gui_connection, handle_gui_connection_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(handle_gui_connection(NULL, NULL, 0), -1);
}

Test(handle_gui_connection, handle_gui_connection_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    char *cmds = strdup("GRAPHIC");
    server->all_co[0].is_player = true;
    cr_assert_eq(handle_gui_connection(cmds, server, 0), -1);
}
