/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** broadcast_test
*/

#include "test.h"
#include "ai_command.h"
#include <math.h>

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(broadcast_test, side_distances, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();

    int dist[4] = { 0, 0, 0, 0 };
    coord_t pos = { 1, 1 };
    coord_t pos2 = { 3, 3 };

    get_side_distances(dist, pos, pos2, &server->game);
    cr_assert_eq(dist[0], -3);
    cr_assert_eq(dist[1], 2);
    cr_assert_eq(dist[2], -3);
    cr_assert_eq(dist[3], 2);
}

Test(broadcast_test, side_distances_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();

    int dist[4] = { 0, 0, 0, 0 };
    coord_t pos = { 3, 3 };
    coord_t pos2 = { 1, 1 };

    get_side_distances(dist, pos, pos2, &server->game);
    cr_assert_eq(dist[0], -2);
    cr_assert_eq(dist[1], 3);
    cr_assert_eq(dist[2], -2);
    cr_assert_eq(dist[3], 3);
}

Test(broadcast_test, side_distances_3, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();

    int dist[4] = { 0, 0, 0, 0 };
    coord_t pos = { 1, 3 };
    coord_t pos2 = { 3, 1 };

    get_side_distances(dist, pos, pos2, &server->game);
    cr_assert_eq(dist[0], -2);
    cr_assert_eq(dist[1], 3);
    cr_assert_eq(dist[2], -3);
    cr_assert_eq(dist[3], 2);
}

Test(broadcast_test, side_distances_4, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();

    int dist[4] = { 0, 0, 0, 0 };
    coord_t pos = { 3, 1 };
    coord_t pos2 = { 1, 3 };

    get_side_distances(dist, pos, pos2, &server->game);
    cr_assert_eq(dist[0], -3);
    cr_assert_eq(dist[1], 2);
    cr_assert_eq(dist[2], -2);
    cr_assert_eq(dist[3], 3);
}

Test(broadcast_test, side_distances_null, .init=redirect_all_stdout)
{
    int dist[4] = { 0, 0, 0, 0 };
    coord_t pos = { 3, 1 };
    coord_t pos2 = { 1, 3 };

    get_side_distances(dist, pos, pos2, NULL);
    cr_assert_eq(dist[0], 0);
    cr_assert_eq(dist[1], 0);
    cr_assert_eq(dist[2], 0);
    cr_assert_eq(dist[3], 0);
}

Test(broadcast_test, front_len_top)
{
    server_t *server = init_server_test();
    server->game.players->orientation = TOP;
    coord_t close_pos = { 2, 2 };
    float angle = get_front_len(server->game.players, close_pos);
    if (angle > 2.23 && angle < 2.24)
        cr_assert_eq(0, 0);
    else
        cr_assert_eq(0, 1);
}

Test(broadcast_test, front_len_bot)
{
    server_t *server = init_server_test();
    server->game.players->orientation = BOTTOM;
    coord_t close_pos = { 2, 2 };
    float angle = get_front_len(server->game.players, close_pos);
    if (angle > 3.60 && angle < 3.61)
        cr_assert_eq(0, 0);
    else
        cr_assert_eq(0, 1);
}

Test(broadcast_test, front_len_right)
{
    server_t *server = init_server_test();
    server->game.players->orientation = RIGHT;
    coord_t close_pos = { 2, 2 };
    float angle = get_front_len(server->game.players, close_pos);
    if (angle > 3.60 && angle < 3.61)
        cr_assert_eq(0, 0);
    else
        cr_assert_eq(0, 1);
}

Test(broadcast_test, front_len_left)
{
    server_t *server = init_server_test();
    server->game.players->orientation = LEFT;
    coord_t close_pos = { 2, 2 };
    float angle = get_front_len(server->game.players, close_pos);
    if (angle > 2.23 && angle < 2.24)
        cr_assert_eq(0, 0);
    else
        cr_assert_eq(0, 1);
}

Test(broadcast_test, front_len_null_ptr)
{
    server_t *server = init_server_test();
    server->game.players->orientation = LEFT;
    coord_t close_pos = { 2, 2 };
    float angle = get_front_len(NULL, close_pos);
    cr_assert_eq(angle, -1);
}

Test(broadcast_test, simple_broadcast, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();

    player_t *new_player = init_player_pos(0, &server->game, 4, 3);
    new_player->type = PLAYER;
    new_player->orientation = TOP;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);

    char **cmds = malloc(sizeof(char *) * 4);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("Test");
    cmds[2] = strdup("Broadcast");
    cmds[3] = NULL;

    cr_assert_eq(broadcast(server, server->game.players, cmds), 0);
    cr_assert_stdout_eq_str("message 6, Test Broadcast\nok\n");
}

Test(broadcast_test, simple_broadcast_2, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = BOTTOM;
    player_t* new_player = init_player_pos(0, &server->game, 4, 3);
    new_player->type = PLAYER;
    new_player->orientation = TOP;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);

    char **cmds = malloc(sizeof(char *) * 4);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("Test");
    cmds[2] = strdup("Broadcast");
    cmds[3] = NULL;

    cr_assert_eq(broadcast(server, server->game.players->next, cmds), 0);
    cr_assert_stdout_eq_str("message 6, Test Broadcast\nok\n");
}

Test(broadcast_test, same_tile_broadcast, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();

    player_t *new_player = init_player_pos(0, &server->game, 0, 0);
    new_player->type = PLAYER;
    new_player->orientation = TOP;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);

    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("Test");
    cmds[2] = NULL;

    cr_assert_eq(broadcast(server, server->game.players, cmds), 0);
    cr_assert_stdout_eq_str("message 0, Test\nok\n");
}

Test(broadcast_test, broadcast_null_ptr, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();

    player_t *new_player = init_player_pos(0, &server->game, 0, 0);
    new_player->type = PLAYER;
    new_player->orientation = TOP;
    new_player->inventory.food = 10;
    new_player->fd = 1;
    server->game.players = add_player_back(server->game.players, new_player);

    char **cmds = malloc(sizeof(char *) * 3);
    cmds[0] = strdup("oui");
    cmds[1] = strdup("Test");
    cmds[2] = NULL;

    cr_assert_eq(broadcast(NULL, server->game.players, cmds), 84);
}

Test(broadcast_test, broadcast_angle, .init=redirect_all_stdout)
{
    cr_assert_eq(get_angle(NULL, NULL, NULL), -1);
}

Test(broadcast_test, convert_angle_top, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = TOP;
    cr_assert_eq(convert_angle(120, server->game.players, (coord_t) {-1, 0}), 240);
}

Test(broadcast_test, convert_angle_bot, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = BOTTOM;
    cr_assert_eq(convert_angle(120, server->game.players, (coord_t) {1, 0}), 240);
}

Test(broadcast_test, convert_angle_right, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = RIGHT;
    cr_assert_eq(convert_angle(120, server->game.players, (coord_t) {0, -1}), 240);
}

Test(broadcast_test, convert_angle_left, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = LEFT;
    cr_assert_eq(convert_angle(120, server->game.players, (coord_t) {0, 1}), 240);
}

Test(broadcast_test, convert_angle_normal, .init=redirect_all_stdout)
{
    server_t *server = init_server_test();
    server->game.players->orientation = LEFT;
    cr_assert_eq(convert_angle(120, server->game.players, (coord_t) {0, 0}), 120);
}

Test(broadcast_test, convert_angle_null_ptr, .init=redirect_all_stdout)
{
    cr_assert_eq(convert_angle(120, NULL, (coord_t) {0, 0}), 120);
}

Test(broadcast_test, get_right_split_1, .init=redirect_all_stdout)
{
    cr_assert_eq(get_right_split(100), 3);
}

Test(broadcast_test, get_right_split_2, .init=redirect_all_stdout)
{
    cr_assert_eq(get_right_split(120), 4);
}

Test(broadcast_test, get_right_split_3, .init=redirect_all_stdout)
{
    cr_assert_eq(get_right_split(190), 5);
}

Test(broadcast_test, get_right_split_4, .init=redirect_all_stdout)
{
    cr_assert_eq(get_right_split(210), 6);
}

Test(broadcast_test, get_right_split_5, .init=redirect_all_stdout)
{
    cr_assert_eq(get_right_split(250), 7);
}

Test(broadcast_test, get_right_split_6, .init=redirect_all_stdout)
{
    cr_assert_eq(get_right_split(300), 8);
}

Test(broadcast_test, get_right_split_7, .init=redirect_all_stdout)
{
    cr_assert_eq(get_right_split(356), 1);
}

Test(broadcast_test, get_right_split_8, .init=redirect_all_stdout)
{
    cr_assert_eq(get_right_split(40), 2);
}

Test(broadcast_test, get_right_split_9, .init=redirect_all_stdout)
{
    cr_assert_eq(get_right_split(400), 0);
}

Test(broadcast_test, get_closest_dir_1, .init=redirect_all_stdout)
{
    int info[] = { 1, -2, 3, -4 };
    coord_t res = get_closest_dir(info);
    cr_assert_eq(res.x, 3);
    cr_assert_eq(res.y, 1);

}

Test(broadcast_test, get_closest_dir_2, .init=redirect_all_stdout)
{
    int info[] = { 4, -2, 3, -4 };
    coord_t res = get_closest_dir(info);
    cr_assert_eq(res.x, 3);
    cr_assert_eq(res.y, -2);

}

Test(broadcast_test, get_closest_dir_3, .init=redirect_all_stdout)
{
    int info[] = { 1, -2, 10, -4 };
    coord_t res = get_closest_dir(info);
    cr_assert_eq(res.x, -4);
    cr_assert_eq(res.y, 1);

}


Test(broadcast_test, get_closest_dir_4, .init=redirect_all_stdout)
{
    int info[] = { 10, -2, 38, -4 };
    coord_t res = get_closest_dir(info);
    cr_assert_eq(res.x, -4);
    cr_assert_eq(res.y, -2);

}

Test(format_broadcast_info, format_broadcast_info_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(format_broadcast_info(0, NULL), NULL);
}
