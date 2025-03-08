/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** exit_program_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(exit_program, exit_program_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
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
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("Forward");
    server->game.players->current_cmd = NULL;
    cr_assert_eq(exit_program(server, parsed), 0);
}

Test(free_server_base, free_server_base_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    parsed->names = malloc(sizeof(char *) * 2);
    parsed->names[0] = strdup("team1");
    parsed->names[1] = NULL;
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
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("Forward");
    server->game.players->current_cmd = NULL;
    free_server_base(server, parsed);
    cr_assert_eq(true, true);
}

Test(free_game_struct, free_game_struct_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    parsed->names = malloc(sizeof(char *) * 2);
    parsed->names[0] = strdup("team1");
    parsed->names[1] = NULL;
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
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->command_buffer[0] = strdup("Forward");
    server->game.players->current_cmd = NULL;
    cr_assert_eq(free_game_struct(server, parsed), 0);
}

Test(free_game_struct, free_game_struct_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(free_game_struct(NULL, parsed), 84);
}

Test(exit_program, exit_program_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    parsed_info_t *parsed = malloc(sizeof(parsed_info_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(exit_program(NULL, parsed), 84);
}
