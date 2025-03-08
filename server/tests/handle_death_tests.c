/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** handle_death_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(handle_death, handle_death, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->food_clock = 125;
    server->game.players->inventory.food = 1;
    server->game.players->type = PLAYER;
    handle_death(server->game.players, 1);
    cr_assert_eq(server->game.players->inventory.food, 0);
    cr_assert_eq(server->game.players->type, DEAD);
    cr_assert_eq(server->game.players->food_clock, 0);
}

Test(handle_death, handle_death_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->food_clock = 125;
    server->game.players->inventory.food = 1;
    server->game.players->type = PLAYER;
    handle_death(NULL, 1);
    cr_assert_eq(server->game.players->inventory.food, 1);
    cr_assert_eq(server->game.players->type, PLAYER);
    cr_assert_eq(server->game.players->food_clock, 125);
}

Test(handle_death, handle_death_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->food_clock = 125;
    server->game.players->inventory.food = 1;
    server->game.players->type = GUI;
    handle_death(server->game.players, 1);
    cr_assert_eq(server->game.players->inventory.food, 1);
    cr_assert_eq(server->game.players->type, GUI);
    cr_assert_eq(server->game.players->food_clock, 125);
}
