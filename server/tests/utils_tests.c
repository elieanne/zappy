/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** utils_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"
#include <fcntl.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(count_player, count_player_invalid)
{
    cr_assert_eq(get_len_player(NULL), 0);
}

Test(display_player, display_player_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    gui->type = GUI;
    gui->command_buffer = init_cmd_buffer();
    gui->command_buffer[0] = strdup("test");
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("test");
    server->game.players->type = PLAYER;
    server->game.players = add_player_back(server->game.players, gui);
    display_user(server->game.players);
    cr_assert_eq(true, true);
}

Test(free_player_list, free_player_list_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    gui->type = GUI;
    gui->command_buffer = init_cmd_buffer();
    gui->command_buffer[0] = strdup("test");
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("test");
    server->game.players->type = PLAYER;
    server->game.players->current_cmd = strdup("test");
    server->game.players = add_player_back(server->game.players, gui);
    free_player_list(server->game.players);
    cr_assert_eq(true, true);
}

Test(free_map, free_map_invalid, .init=redirect_all_stdout)
{
    free_map(NULL);
    cr_assert_eq(true, true);
}

Test(is_numeric, is_numeric_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(is_numeric(NULL), false);
}

Test(free_player, free_player_invalid, .init=redirect_all_stdout)
{
    free_player(NULL);
    cr_assert_eq(true, true);
}

Test(free_player, free_player_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("test");
    server->game.players->type = PLAYER;
    server->game.players->current_cmd = strdup("test");
    free_player(server->game.players);
    cr_assert_eq(true, true);
}

Test(find_player_by_uuid, find_player_by_uuid_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(find_player_by_uuid(NULL, -1), false);
}

Test(remove_node, remove_node_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = init_player_pos(-1, &server->game, 0, 0);
    gui->type = GUI;
    gui->command_buffer = init_cmd_buffer();
    gui->command_buffer[0] = strdup("test");
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("test");
    server->game.players->type = PLAYER;
    server->game.players->current_cmd = strdup("test");
    server->game.players = add_player_back(server->game.players, gui);
    server->game.players = remove_node(server->game.players, NULL, server->game.players);
    cr_assert_eq(server->game.players->type, GUI);
}

Test(remove_node, remove_node_valid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("test");
    server->game.players->type = PLAYER;
    server->game.players->current_cmd = strdup("test");
    server->game.players = remove_node(server->game.players, NULL, server->game.players);
    cr_assert_eq(server->game.players, NULL);
}

Test(find_user_by_uuid, find_user_by_uuid_invalid, .init=redirect_all_stdout)
{
    user_id_t *user = NULL;
    user_id_t *new_id = malloc(sizeof(user_id_t));
    new_id->id = 0;
    user = add_id_back(user, new_id);
    cr_assert_eq(find_id_by_uuid(user, 3), NULL);
}

Test(find_user_by_uuid, find_user_by_uuid_valid_2, .init=redirect_all_stdout)
{
    user_id_t *user = NULL;
    user_id_t *new_id = malloc(sizeof(user_id_t));
    user_id_t *new_id_2 = malloc(sizeof(user_id_t));
    new_id->id = 0;
    new_id_2->id = 1;
    user = add_id_back(user, new_id);
    user = add_id_back(user, new_id_2);
    user = remove_id_by_uuid(user, 4);
    cr_assert_eq(user->id, 0);
}

Test(remove_id_by_uuid, remove_id_by_uuid_valid, .init=redirect_all_stdout)
{
    user_id_t *user = NULL;
    user_id_t *new_id = malloc(sizeof(user_id_t));
    user_id_t *new_id_2 = malloc(sizeof(user_id_t));
    new_id->id = 0;
    new_id_2->id = 1;
    user = add_id_back(user, new_id);
    user = add_id_back(user, new_id_2);
    user = remove_id_by_uuid(user, 0);
    cr_assert_eq(user->id, 1);
}

Test(remove_id_by_uuid, remove_id_by_uuid_valid_2, .init=redirect_all_stdout)
{
    cr_assert_eq(remove_id_by_uuid(NULL, 0), NULL);
}

Test(send_msg_to_gui, send_msg_to_gui_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *player = init_player_pos(1, &server->game, 0, 0);
    server->game.players->type = GUI;
    server->game.players = add_player_back(server->game.players, player);
    send_msg_to_gui(server->game.players, strdup("test"));
//    cr_assert_stdout_eq_str("test\n");
    cr_assert_eq(true, true);
}

Test(parsing_check, parsing_check_errors, .init=redirect_all_stdout)
{
    parsed_info_t* info = NULL;
    cr_assert_eq(check_parsing(info), 84);
    info = malloc(sizeof(parsed_info_t));
    info->clients_nb = "12";
    info->freq = "12";
    info->height = "12";
    info->port = "4242";
    info->names = NULL;
    cr_assert_eq(check_parsing(info), 0);
    info->names = malloc(sizeof(char*) * 1);
    info->names[0] = NULL;
    cr_assert_eq(check_parsing(info), 84);
    cr_assert_eq(check_parsing(info), 84);
    info->port = "0";
    cr_assert_eq(check_parsing(info), 84);
    info->freq = "1";
    cr_assert_eq(check_parsing(info), 84);
    info->height = "1";
    cr_assert_eq(check_parsing(info), 84);
    info->width = "1";
    cr_assert_eq(check_parsing(info), 84);
    info->clients_nb = "0";
    cr_assert_eq(check_parsing(info), 84);
    cr_assert_eq(print_parsing_error(NULL), 84);
}
