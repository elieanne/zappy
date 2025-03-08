/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** players_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(send_death_message, send_death_message_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->client_index = 0;
    server->all_co[0].fd = 1;
    server->all_co[0].id = 0;
    server->all_co[0].is_player = true;
    server->all_co[0].buffer = init_cmd_buffer();
    send_death_message(server->game.players, server);
    cr_assert_eq(server->all_co[0].fd, -1);
    cr_assert_eq(server->all_co[0].id, -1);
    cr_assert_eq(server->all_co[0].is_player, false);
}

Test(get_death_info, get_death_info_valid, .init=redirect_all_stdout)
{
    cr_assert_eq(get_death_infos(NULL), NULL);
}

Test(get_death_info, get_death_info_valid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->was_egg = false;
    server->game.players->id = 0;
    cr_assert_str_eq(get_death_infos(server->game.players), "pdi 0\n");
}

Test(check_game_state, check_game_state, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = malloc(sizeof(player_t));
    player_t *p1 = malloc(sizeof(player_t));
    player_t *p2 = malloc(sizeof(player_t));
    player_t *p3 = malloc(sizeof(player_t));
    player_t *p4 = malloc(sizeof(player_t));
    player_t *p5 = malloc(sizeof(player_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    p1->type = PLAYER;
    p1->level = 8;
    p1->team = 0;
    p2->type = PLAYER;
    p2->level = 8;
    p2->team = 0;
    p3->type = PLAYER;
    p3->level = 8;
    p3->team = 0;
    p4->type = PLAYER;
    p4->level = 8;
    p4->team = 0;
    p5->type = PLAYER;
    p5->level = 8;
    p5->team = 0;
    server->game.players->type = PLAYER;
    server->game.players->level = 8;
    server->game.players->team = 0;
    server->game.players = add_player_back(server->game.players, p1);
    server->game.players = add_player_back(server->game.players, p2);
    server->game.players = add_player_back(server->game.players, p3);
    server->game.players = add_player_back(server->game.players, p4);
    server->game.players = add_player_back(server->game.players, p5);
    gui->type = GUI;
    gui->fd = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.is_win = false;
    server->game.teams_nb = 1;
    server->game.team_names = malloc(sizeof(char *) * 2);
    server->game.team_names[0] = strdup("Team1");
    server->game.team_names[1] = NULL;
    cr_assert_eq(check_game_state(&server->game), 0);
    cr_assert_stdout_eq_str("seg Team1\n");
}

Test(check_game_state, check_game_state_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = malloc(sizeof(player_t));
    player_t *p1 = malloc(sizeof(player_t));
    player_t *p2 = malloc(sizeof(player_t));
    player_t *p3 = malloc(sizeof(player_t));
    player_t *p4 = malloc(sizeof(player_t));
    player_t *p5 = malloc(sizeof(player_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    p1->type = PLAYER;
    p1->level = 8;
    p1->team = 0;
    p2->type = PLAYER;
    p2->level = 8;
    p2->team = 0;
    p3->type = PLAYER;
    p3->level = 8;
    p3->team = 0;
    p4->type = PLAYER;
    p4->level = 8;
    p4->team = 0;
    p5->type = PLAYER;
    p5->level = 8;
    p5->team = 0;
    server->game.players = add_player_back(server->game.players, p1);
    server->game.players = add_player_back(server->game.players, p2);
    server->game.players = add_player_back(server->game.players, p3);
    server->game.players = add_player_back(server->game.players, p4);
    server->game.players = add_player_back(server->game.players, p5);
    gui->type = GUI;
    gui->fd = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.is_win = false;
    server->game.teams_nb = 1;
    server->game.team_names = malloc(sizeof(char *) * 2);
    server->game.team_names[0] = strdup("Team1");
    server->game.team_names[1] = NULL;
    cr_assert_eq(check_game_state(&server->game), -1);
}

Test(check_game_state, check_game_state_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = malloc(sizeof(player_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->type = EGG;
    server->game.players->team = 0;
    gui->type = GUI;
    gui->fd = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.is_win = false;
    server->game.teams_nb = 1;
    server->game.team_names = malloc(sizeof(char *) * 2);
    server->game.team_names[0] = strdup("Team1");
    server->game.team_names[1] = NULL;
    cr_assert_eq(check_game_state(&server->game), -1);
}

Test(check_game_state, check_game_state_4, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *gui = malloc(sizeof(player_t));
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players = NULL;
    gui->type = GUI;
    gui->fd = 1;
    server->game.players = add_player_back(server->game.players, gui);
    server->game.is_win = false;
    server->game.teams_nb = 1;
    server->game.team_names = malloc(sizeof(char *) * 2);
    server->game.team_names[0] = strdup("Team1");
    server->game.team_names[1] = NULL;
    cr_assert_eq(check_game_state(&server->game), 0);
    cr_assert_stdout_eq_str("seg NULL\n");
}

Test(send_seg_event, send_seg_event, .init=redirect_all_stdout)
{
    cr_assert_eq(send_seg_event(0, NULL, NULL), -1);
}

Test(check_game_state, check_game_state_5, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.is_win = true;
    cr_assert_eq(check_game_state(&server->game), 0);
}
