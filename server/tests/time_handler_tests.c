/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** time_handler_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(wait_cycle, wait_cycle_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    struct timespec start;
    struct timespec end;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->cooldown = 1;
    server->game.food_respawn = 0;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    usleep(50500);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    server->game.freq = 2;
    wait_cycle(start, end, &server->game);
    cr_assert_eq(server->game.players->cooldown, 0);
    cr_assert_eq(server->game.food_respawn, 1);
}

Test(wait_cycle, wait_cycle_valid_2)
{
    server_t *server = init_server_test();
    struct timespec start;
    struct timespec end;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->cooldown = 3;
    server->game.food_respawn = 19;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    usleep(1000500);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    server->game.freq = 2;
    wait_cycle(start, end, &server->game);
    cr_assert_eq(server->game.players->cooldown, 1);
    cr_assert_eq(server->game.food_respawn, 0);
}

Test(handle_cooldown, handle_cooldown_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    struct timespec start;
    struct timespec end;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->cooldown = 1;
    handle_cooldown(server->game.players, 3);
    cr_assert_eq(server->game.players->cooldown, 0);
}

Test(handle_cooldown, handle_cooldown_invalid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    server->game.players->cooldown = 1;
    handle_cooldown(NULL, 3);
    cr_assert_eq(server->game.players->cooldown, 1);
}
