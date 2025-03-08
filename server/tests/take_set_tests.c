/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** take_set_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(take, take_linemate, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    take_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.linemate, 1);
}

Test(set, set_linemate, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.linemate = 1;
    drop_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.linemate, 0);
}

Test(set, invalid_set, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.linemate = 0;
    int result = drop_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.linemate, 0);
    cr_assert_eq(result, ERROR);
}

Test(take, invalid_take, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("deraumere");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    int result = drop_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.deraumere, 0);
    cr_assert_eq(result, ERROR);
}

Test(take, take_food, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("food");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.food = 1;
    take_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.food, 11);
}

Test(set, set_food, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("food");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.food = 1;
    drop_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.food, 0);
}

Test(take, take_deraumere, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("deraumere");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.deraumere = 1;
    take_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.deraumere, 1);
}

Test(set, set_deraumere, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("deraumere");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.deraumere = 1;
    drop_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.deraumere, 0);
}

Test(take, take_sibur, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("sibur");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.sibur = 1;
    take_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.sibur, 1);
}

Test(set, set_sibur, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("sibur");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.sibur = 1;
    drop_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.sibur, 0);
}

Test(take, take_mendiane, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("mendiane");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.mendiane = 1;
    take_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.mendiane, 1);
}

Test(set, set_mendiane, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("mendiane");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.mendiane = 1;
    drop_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.mendiane, 0);
}

Test(take, take_phiras, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("phiras");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.phiras = 1;
    take_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.phiras, 1);
}

Test(set, set_phiras, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("phiras");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.phiras = 1;
    drop_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.phiras, 0);
}

Test(take, take_thystame, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("thystame");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.thystame = 1;
    take_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.thystame, 1);
}

Test(set, set_thystame, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("thystame");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.thystame = 1;
    drop_object(server, server->game.players, cmds);
    cr_assert_eq(server->game.players->inventory.thystame, 0);
}

Test(set, set_thystame_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("thystame");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.thystame = 1;
    drop_thystame(NULL, server);
    cr_assert_eq(server->game.players->inventory.thystame, 1);
}

Test(take, take_thystame_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("thystame");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.thystame = 1;
    take_thystame(NULL, server);
    cr_assert_eq(server->game.players->inventory.thystame, 0);
}

Test(set, set_food_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("food");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.food = 1;
    drop_food(NULL, server);
    cr_assert_eq(server->game.players->inventory.food, 1);
}

Test(take, take_food_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("food");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.food = 1;
    take_food(NULL, server);
    cr_assert_eq(server->game.players->inventory.food, 10);
}

Test(set, set_linemate_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.linemate = 1;
    drop_linemate(NULL, server);
    cr_assert_eq(server->game.players->inventory.linemate, 1);
}

Test(take, take_linemate_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.linemate = 1;
    take_linemate(NULL, server);
    cr_assert_eq(server->game.players->inventory.linemate, 0);
}

Test(set, set_deraumere_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("deraumere");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.deraumere = 1;
    drop_deraumere(NULL, server);
    cr_assert_eq(server->game.players->inventory.deraumere, 1);
}

Test(take, take_deraumere_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("deraumere");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.thystame = 1;
    take_deraumere(NULL, server);
    cr_assert_eq(server->game.players->inventory.deraumere, 0);
}

Test(set, set_sibur_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("sibur");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.sibur = 1;
    drop_sibur(NULL, server);
    cr_assert_eq(server->game.players->inventory.sibur, 1);
}

Test(take, take_sibur_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("sibur");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.sibur = 1;
    take_sibur(NULL, server);
    cr_assert_eq(server->game.players->inventory.sibur, 0);
}

Test(set, set_mendiane_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("mendiane");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.mendiane = 1;
    drop_mendiane(NULL, server);
    cr_assert_eq(server->game.players->inventory.mendiane, 1);
}

Test(take, take_mendiane_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("mendiane");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.mendiane = 1;
    take_mendiane(NULL, server);
    cr_assert_eq(server->game.players->inventory.mendiane, 0);
}

Test(set, set_phiras_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("phiras");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.phiras = 1;
    drop_phiras(NULL, server);
    cr_assert_eq(server->game.players->inventory.phiras, 1);
}

Test(take, take_phiras_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("phiras");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.phiras = 1;
    take_phiras(NULL, server);
    cr_assert_eq(server->game.players->inventory.phiras, 0);
}

Test(take, take_thystame_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("thystame");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.thystame = 0;
    take_thystame(server->game.players, server);
    cr_assert_eq(server->game.players->inventory.thystame, 0);
}

Test(take, take_food_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("food");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.food = 0;
    take_food(server->game.players, server);
    cr_assert_eq(server->game.players->inventory.food, 10);
}

Test(take, take_linemate_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.linemate = 0;
    take_linemate(server->game.players, server);
    cr_assert_eq(server->game.players->inventory.linemate, 0);
}

Test(take, take_deraumere_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("deraumere");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.deraumere = 0;
    take_deraumere(server->game.players, server);
    cr_assert_eq(server->game.players->inventory.deraumere, 0);
}

Test(take, take_sibur_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("sibur");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.sibur = 0;
    take_sibur(server->game.players, server);
    cr_assert_eq(server->game.players->inventory.sibur, 0);
}

Test(take, take_mendiane_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("mendiane");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.mendiane = 0;
    take_mendiane(server->game.players, server);
    cr_assert_eq(server->game.players->inventory.mendiane, 0);
}

Test(take, take_phiras_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("phiras");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->tile->inventory.phiras = 0;
    take_phiras(server->game.players, server);
    cr_assert_eq(server->game.players->inventory.phiras, 0);
}

Test(get_nb, get_nb_food, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("food");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_food(&server->game.map), 16);
}

Test(get_nb, get_nb_food_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("food");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->tile->inventory.food = 3;
    cr_assert_eq(get_nb_food(NULL), -1);
}

Test(get_nb, get_nb_linemate, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_linemate(&server->game.map), 9);
}

Test(get_nb, get_nb_linemate_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_linemate(NULL), -1);
}


Test(get_nb, get_nb_deraumere, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("deraumere");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_deraumere(&server->game.map), 3);
}

Test(get_nb, get_nb_deraumere_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("deraumere");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_deraumere(NULL), -1);
}

Test(get_nb, get_nb_sibur, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("sibur");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_sibur(&server->game.map), 3);
}

Test(get_nb, get_nb_sibur_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("sibur");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_sibur(NULL), -1);
}

Test(get_nb, get_nb_mendiane, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("mendiane");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_mendiane(&server->game.map), 1);
}

Test(get_nb, get_nb_mendiane_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("mendiane");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_mendiane(NULL), -1);
}

Test(get_nb, get_nb_phiras, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("phiras");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_phiras(&server->game.map), 3);
}

Test(get_nb, get_nb_phiras_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("phiras");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_phiras(NULL), -1);
}

Test(get_nb, get_nb_thystame, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("thystame");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_thystame(&server->game.map), 1);
}

Test(get_nb, get_nb_thystame_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("thystame");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(get_nb_thystame(NULL), -1);
}

Test(set, set_food_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("food");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.food = 0;
    drop_food(server->game.players, server);
    cr_assert_eq(server->game.players->tile->inventory.food, 1);
}

Test(set, set_linemate_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("linemate");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.linemate = 0;
    drop_linemate(server->game.players, server);
    cr_assert_eq(server->game.players->tile->inventory.linemate, 1);
}

Test(set, set_deraumere_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("deraumere");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.deraumere = 0;
    drop_deraumere(server->game.players, server);
    cr_assert_eq(server->game.players->tile->inventory.deraumere, 0);
}

Test(set, set_sibur_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("sibur");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.sibur = 0;
    drop_sibur(server->game.players, server);
    cr_assert_eq(server->game.players->tile->inventory.sibur, 0);
}

Test(set, set_mendiane_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("mendiane");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.mendiane = 0;
    drop_mendiane(server->game.players, server);
    cr_assert_eq(server->game.players->tile->inventory.mendiane, 0);
}

Test(set, set_phiras_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("phiras");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.phiras = 0;
    drop_phiras(server->game.players, server);
    cr_assert_eq(server->game.players->tile->inventory.phiras, 0);
}

Test(set, set_thystame_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("thystame");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->orientation = RIGHT;
    server->game.players->inventory.thystame = 0;
    drop_thystame(server->game.players, server);
    cr_assert_eq(server->game.players->tile->inventory.thystame, 0);
}

Test(get_take_drop_info, get_take_drop_info_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(get_take_drop_info(NULL, 0, 0), NULL);
}

Test(is_valid_take, is_valid_take_invalid_4, .init=redirect_all_stdout)
{
    cr_assert_eq(is_valid_take(NULL, NULL, NULL), false);
}

Test(take_object, take_object_invalid_1, .init=redirect_all_stdout)
{
    cr_assert_eq(take_object(NULL, NULL, NULL), ERROR);
}

Test(take_object, take_object_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(take_object(server, server->game.players, NULL), ERROR);
}

Test(take_object, take_object_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(take_object(server, server->game.players, cmds), ERROR);
}

Test(drop_object, drop_object_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(drop_object(NULL, NULL, NULL), ERROR);
}

Test(drop_object, drop_object_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(drop_object(server, server->game.players, NULL), ERROR);
}

Test(drop_object, drop_object_invalid_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("oui");
    cmds[2] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(drop_object(server, server->game.players, cmds), ERROR);
}
