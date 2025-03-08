/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** eject
*/

#include "test.h"
#include "ai_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(eject_test, not_valid_eject, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = RIGHT;
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = eject(server, server->game.players, cmds);
    cr_assert_eq(result, 84);
}

Test(eject_test, valid_eject_1_people_right, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = RIGHT;
    player_t *new_player = init_player_pos(0, &server->game, 0, 0);
    new_player->type = PLAYER;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = eject(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("eject: 4\nok\n");
    cr_assert_eq(server->game.map.map[0][1].id_list->id, new_player->id);
    cr_assert_eq(server->game.map.map[0][0].id_list->id, server->game.players->id);
    cr_assert_eq(result, 0);
}

Test(eject_test, valid_eject_1_people_left, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = LEFT;
    player_t *new_player = init_player_pos(0, &server->game, 0, 0);
    new_player->type = PLAYER;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = eject(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("eject: 2\nok\n");
    cr_assert_eq(server->game.map.map[0][4].id_list->id, new_player->id);
    cr_assert_eq(server->game.map.map[0][0].id_list->id, server->game.players->id);
    cr_assert_eq(result, 0);
}

Test(eject_test, valid_eject_1_people_top, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = TOP;
    player_t *new_player = init_player_pos(0, &server->game, 0, 0);
    new_player->type = PLAYER;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = eject(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("eject: 3\nok\n");
    cr_assert_eq(server->game.map.map[4][0].id_list->id, new_player->id);
    cr_assert_eq(server->game.map.map[0][0].id_list->id, server->game.players->id);
    cr_assert_eq(result, 0);
}

Test(eject_test, valid_eject_1_people_bot, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = BOTTOM;
    player_t *new_player = init_player_pos(0, &server->game, 0, 0);
    new_player->type = PLAYER;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = eject(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("eject: 1\nok\n");
    cr_assert_eq(server->game.map.map[1][0].id_list->id, new_player->id);
    cr_assert_eq(server->game.map.map[0][0].id_list->id, server->game.players->id);
    cr_assert_eq(result, 0);
}

Test(eject_test, valid_eject_people_and_egg, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->game.players->orientation = RIGHT;

    player_t *new_player = init_player_pos(0, &server->game, 0, 0);
    new_player->type = PLAYER;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);


    player_t *new_egg = init_player_pos(0, &server->game, 0, 0);
    new_egg->type = EGG;
    new_egg->inventory.food = 10;
    new_egg->fd = -1;
    new_egg->was_egg = true;

    server->game.players = add_player_back(server->game.players, new_egg);
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = eject(server, server->game.players, cmds);
    cr_assert_eq(find_id_by_uuid(server->game.map.map[0][0].id_list, new_egg->id)->id, new_egg->id);
    cr_assert_stdout_eq_str("eject: 4\nok\n");
    cr_assert_eq(server->game.map.map[0][1].id_list->id, new_player->id);
    cr_assert_eq(server->game.map.map[0][0].id_list->id, server->game.players->id);
    cr_assert_eq(find_id_by_uuid(server->game.map.map[0][0].id_list, new_egg->id)->id, NULL);
    cr_assert_eq(result, 0);
}

Test(eject_test, side_case, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 1;
    server->game.players->orientation = RIGHT;

    player_t *new_player = init_player_pos(0, &server->game, 0, 0);
    new_player->type = PLAYER;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);


    player_t *dead_player = init_player_pos(0, &server->game, 0, 0);
    dead_player->type = DEAD;
    dead_player->inventory.food = 10;
    dead_player->fd = -1;

    server->game.players = add_player_back(server->game.players, dead_player);
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = eject(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("eject: 4\nok\n");
    cr_assert_eq(server->game.map.map[0][1].id_list->id, new_player->id);
    cr_assert_eq(server->game.map.map[0][0].id_list->id, server->game.players->id);
    cr_assert_eq(result, 0);
}

Test(eject_test, wrong_param_1, .init=redirect_all_stdout)
{
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    int result = eject(NULL, NULL, cmds);
    cr_assert_eq(result, 84);
}


Test(eject_test, pointer_check_subfunctions, .init=redirect_all_stdout)
{
    int result = exec_eject(NULL, NULL, NULL, (int[2]) {0, 0});
    cr_assert_eq(result, 84);
    result = eject_players(0, 0, NULL, NULL);
    cr_assert_eq(result, 84);
    handle_egg(NULL, NULL);
    cr_assert_eq(get_eject_info(NULL), NULL);
    result = switch_direction(5);
    cr_assert_eq(result, 84);
}
