/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** command_handling_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"
#include <fcntl.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(handle_team_connection, handle_team_connection_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.team_names = malloc(sizeof(char *) * 1);
    server->game.team_names[0] = strdup("team1");
    server->game.teams_nb = 1;
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->all_co[0].is_player = false;
    server->all_co[0].fd = 1;
    server->all_co[0].id = 0;
    server->all_co[0].buffer = init_cmd_buffer();
    server->all_co [0].buffer[0] = strdup("Look");
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = EGG;
    server->game.players->team = 0;
    handle_team_connection("team1", server, 0);
    cr_assert_eq(server->all_co[0].is_player, true);
    cr_assert_eq(server->game.players->type, PLAYER);
    cr_assert_eq(server->all_co[0].id, 0);
    cr_assert_eq(server->game.players->fd, 1);
    cr_assert_eq(server->game.players->client_index, 0);
    cr_assert_eq(server->game.players->team, 0);
    cr_assert_eq(server->game.players->level, 1);
    cr_assert_eq(server->game.players->inventory.food, 10);
    cr_assert_str_eq(server->game.players->command_buffer[0], "Look");
}

Test(handle_team_connection, handle_team_connection_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(handle_team_connection("oui", server, 0), -1);
}

Test(handle_team_connection, handle_team_connection_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(handle_team_connection(NULL, server, 0), -1);
}

Test(handle_team_connection, handle_team_connection_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->all_co[0].is_player = true;
    cr_assert_eq(handle_team_connection("team1", server, 0), -1);
}

Test(get_command_string, get_command_string_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    int fd = open("tests/samples_commands/command1.txt", O_RDONLY);
    if (server == NULL || fd == -1) {
        cr_assert_eq(true, false);
    }
    server->game.players->fd = fd;
    server->game.players->command_buffer = init_cmd_buffer();
    server->all_co[0].fd = fd;
    server->all_co[0].id = 0;
    get_command_string(server, 0);
    cr_assert_str_eq(server->game.players->command_buffer[0], "Look");
}

Test(get_command_string, get_command_string_valid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    int fd = open("tests/samples_commands/command1.txt", O_RDONLY);
    if (server == NULL || fd == -1) {
        cr_assert_eq(true, false);
    }
    server->game.players->fd = fd;
    server->all_co[0].buffer = init_cmd_buffer();
    server->all_co[0].fd = fd;
    server->all_co[0].id = 1;
    get_command_string(server, 0);
    cr_assert_str_eq(server->all_co[0].buffer[0], "Look");
}

Test(get_command_string, get_command_string_valid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    int fd = open("tests/samples_commands/no_command.txt", O_RDONLY);
    if (server == NULL || fd == -1) {
        cr_assert_eq(true, false);
    }
    server->game.players->fd = fd;
    server->all_co[0].buffer = init_cmd_buffer();
    server->all_co[0].fd = fd;
    server->all_co[0].id = 1;
    get_command_string(server, 0);
    cr_assert_eq(server->all_co[0].buffer, NULL);
    cr_assert_eq(server->all_co[0].is_player, false);
    cr_assert_eq(server->all_co[0].fd, -1);
    cr_assert_eq(server->all_co[0].id, -1);
}

Test(check_command, check_command_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    int fd = open("tests/samples_commands/command1.txt", O_RDONLY);
    if (server == NULL || fd == -1) {
        cr_assert_eq(true, false);
    }
    server->game.players->fd = fd;
    server->game.players->command_buffer = init_cmd_buffer();
    FD_SET(fd, &server->rfds);
    server->all_co[1].fd = fd;
    server->all_co[1].id = 0;
    check_command(server);
    cr_assert_str_eq(server->game.players->command_buffer[0], "Look");
}

Test(gui_map_size, gui_map_size_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(gui_map_size(NULL, NULL, NULL), -1);
}

Test(gui_map_content, gui_map_content_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(gui_map_content(NULL, NULL, NULL), -1);
}

Test(gui_map_content, gui_map_content_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    char **str = malloc(sizeof(char) * 2);
    str[0] = strdup("mct");
    str[1] = NULL;
    server->game.players->type = GUI;
    gui_map_content(server, server->game.players, str);
    cr_assert_stdout_eq_str("bct 0 0 1 1 0 0 0 0 0\n"
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
                            "");
}

Test(gui_tile_content, gui_tile_content_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(gui_tile_content(NULL, NULL, NULL), -1);
}

Test(gui_tile_content, gui_tile_content_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    char **str = malloc(sizeof(char) * 4);
    str[0] = strdup("bct");
    str[1] = strdup("0");
    str[2] = strdup("0");
    str[3] = NULL;
    server->game.players->type = GUI;
    gui_tile_content(server, server->game.players, str);
    cr_assert_stdout_eq_str("bct 0 0 1 1 0 0 0 0 0\n");
}

Test(gui_player_lvl, gui_player_lvl_invalid_5, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    char **str = malloc(sizeof(char) * 3);
    str[0] = strdup("plv");
    str[1] = strdup("10");
    str[2] = NULL;
    cr_assert_eq(gui_player_lvl(server, server->game.players, str), -1);
}

Test(is_valid_lvl, is_valid_lvl_invalid_5, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    char **str = malloc(sizeof(char) * 3);
    str[0] = strdup("plv");
    str[1] = strdup("10");
    str[2] = NULL;
    cr_assert_eq(is_valid_lvl(server, server->game.players, str), false);
}

Test(gui_player_lvl, gui_player_lvl_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    char **str = malloc(sizeof(char) * 3);
    str[0] = strdup("plv");
    str[1] = strdup("0");
    str[2] = NULL;
    cr_assert_eq(gui_player_lvl(server, server->game.players, str), 0);
    cr_assert_stdout_eq_str("plv 0 1\n");
}

Test(gui_player_lvl, gui_player_lvl_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(gui_player_lvl(NULL, NULL, NULL), -1);
}

Test(get_start_inc_info, get_start_inc_info_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(get_start_inc_infos(NULL), NULL);
}

Test(get_end_inc_info, get_end_inc_info_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(get_end_inc_infos(NULL), NULL);
}

Test(is_valid_pin, is_valid_pin_invalid_5, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    char **str = malloc(sizeof(char) * 3);
    str[0] = strdup("pin");
    str[1] = strdup("10");
    str[2] = NULL;
    cr_assert_eq(is_valid_pin(server, server->game.players, str), false);
}

Test(gui_inv_event, gui_inv_event_invalid_2, .init=redirect_all_stdout)
{
    gui_inv_event(NULL, NULL);
    cr_assert_eq(true, true);
}

Test(gui_inv_event, gui_inv_event, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    gui->fd = 2;
    gui->type = GUI;
    server->game.players->type = PLAYER;
    server->game.players->id = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    gui_inv_event(server->game.players, server->game.players);
    cr_assert_stderr_eq_str("pin 1 0 0 10 0 0 0 0 0 0\n");
}

Test(gui_player_pin, gui_player_pin, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("pin");
    cmds[1] = strdup("1");
    cmds[2] = NULL;
    gui->fd = 2;
    gui->type = GUI;
    server->game.players->type = PLAYER;
    server->game.players->id = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    gui_player_pin(server, gui, cmds);
    cr_assert_stderr_eq_str("pin 1 0 0 10 0 0 0 0 0 0\n");
}

Test(gui_player_pin, gui_player_pin_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("pin");
    cmds[1] = strdup("10");
    cmds[2] = NULL;
    gui->fd = 2;
    gui->type = GUI;
    server->game.players->type = PLAYER;
    server->game.players->id = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    cr_assert_eq(gui_player_pin(server, gui, cmds), -1);
}

Test(gui_player_pin, gui_player_pin_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(gui_player_pin(NULL, NULL, NULL), -1);
}

Test(is_valid_ppo, is_valid_ppo_invalid_5, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    char **str = malloc(sizeof(char) * 3);
    str[0] = strdup("ppo");
    str[1] = strdup("10");
    str[2] = NULL;
    cr_assert_eq(is_valid_ppo(server, server->game.players, str), false);
}

Test(gui_player_pos, gui_player_pos_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("pin");
    cmds[1] = strdup("10");
    cmds[2] = NULL;
    gui->fd = 2;
    gui->type = GUI;
    server->game.players->type = PLAYER;
    server->game.players->id = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    cr_assert_eq(gui_player_pos(server, gui, cmds), -1);
}

Test(gui_player_pos, gui_player_pos_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("ppo");
    cmds[1] = strdup("1");
    cmds[2] = NULL;
    gui->fd = 2;
    gui->type = GUI;
    server->game.players->orientation = TOP;
    server->game.players->type = PLAYER;
    server->game.players->id = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    gui_player_pos(server, gui, cmds);
    cr_assert_stderr_eq_str("ppo 1 0 0 1\n");
}

Test(gui_player_pos, gui_player_pos_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(gui_player_pos(NULL, NULL, NULL), -1);
}

Test(gui_player_pos_event, gui_player_pos_event_invalid_2, .init=redirect_all_stdout)
{
    gui_player_pos_event(NULL, NULL);
    cr_assert_eq(true, true);
}

Test(gui_player_pos_event, gui_player_pos_event, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    gui->fd = 2;
    gui->type = GUI;
    server->game.players->orientation = LEFT;
    server->game.players->type = PLAYER;
    server->game.players->id = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    gui_player_pos_event(server->game.players, server->game.players);
    cr_assert_stderr_eq_str("ppo 1 0 0 4\n");
}

Test(send_gui_event, send_gui_event_invalid, .init=redirect_all_stdout)
{
    send_gui_event(NULL, NULL);
    cr_assert_eq(true, true);
}

Test(send_gui_event, send_gui_event_invalid_2, .init=redirect_all_stdout)
{
    char *cmd = strdup("pin 1");
    send_gui_event(NULL, cmd);
    cr_assert_eq(true, true);
}

//Test(send_msg_to_gui, send_msg_to_gui, .init=redirect_all_stdout)
//{
//    server_t *server = init_server_test();
//    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
//    if (server == NULL) {
//        cr_assert_eq(true, false);
//    }
//    char *msg = strdup("test");
//    gui->fd = 1;
//    gui->type = GUI;
//    server->game.players->orientation = LEFT;
//    server->game.players->type = PLAYER;
//    server->game.players->id = 1;
//    server->game.players = add_player_back(server->game.players, gui);
//    send_msg_to_gui(server->game.players, msg);
//    cr_assert_stdout_eq_str("test\n");
//}
//
Test(send_msg_to_gui, send_msg_to_gui_invalid, .init=redirect_all_stdout)
{
    send_msg_to_gui(NULL, NULL);
    cr_assert_eq(true, true);
}

Test(format_team_name, format_team_name_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(format_team_name(NULL), NULL);
}

Test(get_team_names, get_team_names_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(get_team_names(NULL), NULL);
}

Test(gui_teams_name, gui_teams_name, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    if (server == NULL) {
        cr_assert_eq(true, false);
    }

    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("tna");
    cmds[1] = NULL;
    gui->fd = 1;
    gui->type = GUI;
    server->game.players->orientation = LEFT;
    server->game.players->type = PLAYER;
    server->game.players->id = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->game.teams_nb = 1;
    server->game.team_names = malloc(sizeof(char *) * 2);
    server->game.team_names[0] = strdup("test");
    server->game.team_names[1] = NULL;
    gui_teams_name(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("tna test\n");
}

Test(gui_teams_name, gui_teams_name_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(gui_teams_name(NULL, NULL, NULL), -1);
}

Test(gui_time_unit, gui_time_unit_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(gui_time_unit(NULL, NULL, NULL), -1);
}

Test(gui_time_unit, gui_time_unit_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("tna");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = GUI;
    gui_time_unit(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("sgt 100\n");
}

Test(gui_sst, gui_sst_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("tna");
    cmds[1] = strdup("2");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = GUI;
    gui_sst(server, server->game.players, cmds);
    cr_assert_eq(server->game.freq, 2);
}

Test(free_parsing, free_parsing_valid, .init=redirect_all_stdout)
{
    parsed_info_t *infos = malloc(sizeof(parsed_info_t));
    infos->names = malloc(sizeof(char *) * 2);
    infos->names[0] = strdup("test");
    infos->names[1] = NULL;
    infos->port = "4242";
    infos->width = "10";
    infos->height = "10";
    infos->clients_nb = "10";
    infos->freq = "10";
    free_parsing(infos);
    cr_assert_eq(true, true);
}

Test(free_parsing, free_parsing_invalid, .init=redirect_all_stdout)
{
    free_parsing(NULL);
    cr_assert_eq(true, true);
}

Test(parse_args, parse_args, .init=redirect_all_stdout)
{
    char **cmds = malloc(sizeof(char *) * 15);
    cmds[0] = strdup("./zappy_server");
    cmds[1] = strdup("-p");
    cmds[2] = strdup("4242");
    cmds[3] = strdup("-x");
    cmds[4] = strdup("10");
    cmds[5] = strdup("-y");
    cmds[6] = strdup("10");
    cmds[7] = strdup("-n");
    cmds[8] = strdup("test");
    cmds[9] = strdup("test2");
    cmds[10] = strdup("-c");
    cmds[11] = strdup("10");
    cmds[12] = strdup("-f");
    cmds[13] = strdup("10");
    cmds[14] = NULL;
    parsed_info_t *infos = parse_args(cmds);
    cr_assert_str_eq(infos->port, "4242");
    cr_assert_str_eq(infos->width, "10");
    cr_assert_str_eq(infos->height, "10");
    cr_assert_str_eq(infos->clients_nb, "10");
    cr_assert_str_eq(infos->freq, "10");
    cr_assert_str_eq(infos->names[0], "test");
    cr_assert_str_eq(infos->names[1], "test2");
}

Test(parse_args, parse_args_2, .init=redirect_all_stdout)
{
    char **cmds = malloc(sizeof(char *) * 13);
    cmds[0] = strdup("./zappy_server");
    cmds[1] = strdup("-p");
    cmds[2] = strdup("4242");
    cmds[3] = strdup("-x");
    cmds[4] = strdup("10");
    cmds[5] = strdup("-y");
    cmds[6] = strdup("10");
    cmds[7] = strdup("-n");
    cmds[8] = strdup("test");
    cmds[9] = strdup("test2");
    cmds[10] = strdup("-c");
    cmds[11] = strdup("10");
    cmds[12] = NULL;
    parsed_info_t *infos = parse_args(cmds);
    cr_assert_str_eq(infos->port, "4242");
    cr_assert_str_eq(infos->width, "10");
    cr_assert_str_eq(infos->height, "10");
    cr_assert_str_eq(infos->clients_nb, "10");
    cr_assert_eq(infos->freq, NULL);
    cr_assert_str_eq(infos->names[0], "test");
    cr_assert_str_eq(infos->names[1], "test2");
}

Test(parse_args, parse_args_invalid, .init=redirect_all_stdout)
{
    char **cmds = malloc(sizeof(char *) * 13);
    cmds[0] = strdup("./zappy_server");
    cmds[1] = strdup("-p");
    cmds[2] = strdup("4242");
    cmds[3] = strdup("-x");
    cmds[4] = strdup("10");
    cmds[5] = strdup("-y");
    cmds[7] = strdup("-n");
    cmds[8] = strdup("test");
    cmds[9] = strdup("test2");
    cmds[10] = strdup("-c");
    cmds[11] = strdup("10");
    cmds[12] = NULL;
    parsed_info_t *infos = parse_args(cmds);
    cr_assert_eq(infos, NULL);
}

Test(parse_args, parse_args_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(parse_args(NULL), NULL);
}

Test(parse_args, parse_args_invalid_3, .init=redirect_all_stdout)
{
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("./zappy_server");
    cmds[1] = strdup("-h");
    cmds[2] = NULL;
    parsed_info_t *infos = parse_args(cmds);
    cr_assert_eq(infos, NULL);
}

Test(get_arg, get_arg_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(get_arg(NULL, NULL), NULL);
}

Test(get_nb_teams, get_nb_teams_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(get_nb_teams(NULL), -1);
}

Test(get_teams, get_teams_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(get_teams(NULL), NULL);
}

Test(need_help, need_help_invalid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(need_help(NULL), true);
}
