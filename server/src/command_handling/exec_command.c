/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** exec_command.c
*/

#include "command.h"

int exec_ai_command(server_t* server, player_t *player, char **cmd)
{
    for (int i = 0; commands[i].identifier != NULL; i++) {
        if (strcmp(commands[i].identifier, cmd[0]) != 0 ||
            commands[i].cmd_type != PLAYER)
            continue;
        if (commands[i].exec(server, player, cmd) != 0)
            send_ko(player->fd);
        return SUCCESS;
    }
    send_ko(player->fd);
    return ERROR;
}

int exec_gui_command(server_t* server, player_t *player, char **cmd)
{
    for (int i = 0; commands[i].identifier != NULL; i++) {
        if (strcmp(commands[i].identifier, cmd[0]) != 0 ||
            commands[i].cmd_type != GUI)
            continue;
        commands[i].exec(server, player, cmd);
        return SUCCESS;
    }
    gui_unknown_cmd(player->fd);
    return ERROR;
}

int find_command(char **tmp, server_t *server, player_t *player)
{
    for (int i = 0; commands[i].identifier != NULL; i++) {
        if (strcmp(commands[i].identifier, tmp[0]) != 0 ||
            commands[i].cmd_type != player->type)
            continue;
        if (commands[i].is_valid(server, player, tmp)) {
            player->cooldown = commands[i].cooldown;
            free_command(tmp);
            return SUCCESS;
        }
        send_bad_parameter(player);
        exit_cmd(tmp, player);
        return ERROR;
    }
    exit_cmd(tmp, player);
    send_unknown(player);
    return ERROR;
}

int is_cmd_valid(server_t *server, player_t *player)
{
    char **tmp = NULL;
    player->current_cmd = rotate_buffer(player->command_buffer);
    tmp = my_str_to_word_array(player->current_cmd, " \n");
    if (!tmp || !tmp[0]) {
        exit_cmd(tmp, player);
        return ERROR;
    }
    return find_command(tmp, server, player);
}

int exec_command(server_t* server, player_t *player)
{
    char **tmp = NULL;
    if (!player || player->cooldown || player->elevating)
        return ERROR;
    if (!player->current_cmd)
        return is_cmd_valid(server, player);
    tmp = my_str_to_word_array(player->current_cmd, " \n");
    if (!tmp || !tmp[0]) {
        exit_cmd(tmp, player);
        return ERROR;
    }
    if (player->type == PLAYER)
        exec_ai_command(server, player, tmp);
    if (player->type == GUI)
        exec_gui_command(server, player, tmp);
    exit_cmd(tmp, player);
    return SUCCESS;
}
