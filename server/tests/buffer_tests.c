/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** add_to_buffer_tests.c
*/

#include "../include/test.h"
#include "../include/ai_command.h"
#include "../include/gui_command.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(add_to_buffer, add_to_buffer_valid, .init=redirect_all_stdout)
{
    char **buffer = init_cmd_buffer();
    char *cmd = strdup("Forward\nLeft\nRight\nLook\nInventory\nBroadcast\n"
        "Connect_nbr\nFork\nEject\nTake\nSet\nIncantation\n");
    add_to_buffer(buffer, cmd);
    cr_assert_str_eq(buffer[0], "Forward");
    cr_assert_str_eq(buffer[1], "Left");
    cr_assert_str_eq(buffer[2], "Right");
    cr_assert_str_eq(buffer[3], "Look");
    cr_assert_str_eq(buffer[4], "Inventory");
    cr_assert_str_eq(buffer[5], "Broadcast");
    cr_assert_str_eq(buffer[6], "Connect_nbr");
    cr_assert_str_eq(buffer[7], "Fork");
    cr_assert_str_eq(buffer[8], "Eject");
    cr_assert_str_eq(buffer[9], "Take");
    cr_assert_eq(buffer[10], NULL);
}

Test(add_to_buffer, add_to_buffer_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(add_to_buffer(NULL, NULL), ERROR);
}

Test(rotate_buffer, rotate_buffer_valid, .init=redirect_all_stdout)
{
    char **buffer = init_cmd_buffer();
    char *cmd = strdup("Forward\nLeft\nRight\nLook\nInventory\nBroadcast\n"
                       "Connect_nbr\nFork\nEject\nTake\nSet\nIncantation\n");
    add_to_buffer(buffer, cmd);
    char *tmp = rotate_buffer(buffer);
    cr_assert_str_eq(buffer[0], "Left");
    cr_assert_str_eq(buffer[1], "Right");
    cr_assert_str_eq(buffer[2], "Look");
    cr_assert_str_eq(buffer[3], "Inventory");
    cr_assert_str_eq(buffer[4], "Broadcast");
    cr_assert_str_eq(buffer[5], "Connect_nbr");
    cr_assert_str_eq(buffer[6], "Fork");
    cr_assert_str_eq(buffer[7], "Eject");
    cr_assert_str_eq(buffer[8], "Take");
    cr_assert_eq(buffer[9], NULL);
    cr_assert_eq(buffer[10], NULL);
    cr_assert_str_eq(tmp, "Forward");
}

Test(rotate_buffer, rotate_buffer_invalid, .init=redirect_all_stdout)
{
    cr_assert_eq(rotate_buffer(NULL), NULL);
}
