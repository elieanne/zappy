/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** server_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"
#include <fcntl.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(create_server, create_server_valid, .init=redirect_all_stdout)
{
    server_t *server = malloc(sizeof(server_t));
    cr_assert_eq(create_server(server, "4243"), SUCCESS);
}

Test(create_server, create_server_invalid, .init=redirect_all_stdout)
{
    server_t *server = malloc(sizeof(server_t));
    cr_assert_eq(create_server(server, NULL), ERROR);
}

Test(create_server, create_server_invalid_2, .init=redirect_all_stdout)
{
    server_t *server = malloc(sizeof(server_t));
    create_server(server, "4244");
    cr_assert_eq(create_server(server, "4244"), ERROR);
}

Test(exec_all_command, exec_all_command_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    player_t *dead = malloc(sizeof(player_t));
    dead->type = DEAD;
    server->game.players->type = PLAYER;
    server->game.players->command_buffer = init_cmd_buffer();
    server->game.players->current_cmd = strdup("Forward");
    server->fd_max = 2;
    FD_SET(server->game.players->fd, &server->wfds);
    server->game.players = add_player_back(server->game.players, dead);
    exec_all_cmd(server);
    cr_assert_stdout_eq_str("ok\n");
}

Test(exec_all_command, exec_all_command_invalid, .init=redirect_all_stdout)
{
    exec_all_cmd(NULL);
    cr_assert_eq(true, true);
}

Test(store_command, store_command_valid, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    int fd = open("tests/samples_commands/no_command.txt", O_RDONLY);
    if (fd == -1)
        cr_assert_fail();
    server->game.players->fd = fd;
    cr_assert_eq(store_command(server), -1);
}

Test(store_command, store_command_valid_2)
{
    server_t *server = init_server_test();
    int fd = open("tests/samples_commands/command1.txt", O_RDONLY);
    if (fd == -1)
        cr_assert_fail();
    server->all_co[1].fd = fd;
    cr_assert_eq(store_command(server), 0);
}

Test(test_signal_handling, test_signal_handling_valid)
{
    siginfo_t *si = malloc(sizeof(siginfo_t));
    si->si_signo = SIGINT;
    handle_signal(SIGINT, si, NULL);
    cr_assert_eq(can_continue(), false);
}

Test(test_signal_handling, test_signal_handling_valid_2)
{
    get_signal();
    cr_assert_eq(can_continue(), true);
}
