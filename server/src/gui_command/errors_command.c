/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** errors_command.c
*/

#include "zappy_server.h"

void gui_unknown_cmd(int fd)
{
    dprintf(fd, "suc\n");
}

void gui_bad_parameter(int fd)
{
    dprintf(fd, "sbp\n");
}

void exit_cmd(char **tmp, player_t *player)
{
    free_command(tmp);
    release_current_command(player);
}

void send_bad_parameter(player_t *player)
{
    if (player->type == GUI)
        gui_bad_parameter(player->fd);
    if (player->type == PLAYER)
        send_ko(player->fd);
}

void send_unknown(player_t *player)
{
    if (player->type == GUI)
        gui_unknown_cmd(player->fd);
    if (player->type == PLAYER)
        send_ko(player->fd);
}
