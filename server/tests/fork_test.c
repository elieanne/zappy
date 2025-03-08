/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** fork_test
*/

#include "test.h"
#include "ai_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(fork_test, basic_fork, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 0;
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    int result = fork_cmd(server, server->game.players, cmds);
    cr_assert_stdout_eq_str("ok\n");
    cr_assert_eq(result, 0);
    cr_assert_eq(server->game.team_slot[0], 1);

    player_t *new_player = server->game.players->next;

    cr_assert_eq(new_player->type, EGG);
    cr_assert_eq(new_player->tile, server->game.players->tile);
    cr_assert_eq(server->game.players->tile->id_list->next->id, new_player->id);
}

Test(fork_test, null_ptr, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.team_slot = malloc(sizeof(int) * 1);
    server->game.team_slot[0] = 0;
    char **cmds = malloc(sizeof(char *) * 2);
    cmds[0] = strdup("oui");
    cmds[1] = NULL;
    if (server == NULL) {
        cr_assert_eq(true, false);
    }
    cr_assert_eq(fork_cmd(server, NULL, cmds), 84);
    cr_assert_eq(fork_cmd(NULL, server->game.players, cmds), 84);
}

Test(fork_test, null_ptr_subfunction, .init=redirect_all_stdout)
{
    cr_assert_eq(get_egg_infos(NULL, NULL),  NULL);
    cr_assert_eq(get_player_infos(NULL), NULL);
}
