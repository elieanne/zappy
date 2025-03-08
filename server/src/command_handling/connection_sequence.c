/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** find_command.c
*/

#include "zappy_server.h"

int check_ai_co(server_t *server, char **cmd, int index)
{
    if (get_command_size(cmd) != 1) {
        return -1;
    }
    return handle_team_connection(cmd[0], server, index);
}

int check_gui_co(server_t *server, char **cmd, int index)
{
    if (get_command_size(cmd) != 1)
        return -1;
    return handle_gui_connection(cmd[0], server, index);
}

void check_connection_sequence(server_t *serv)
{
    char *cmd = NULL;
    char **parsed = NULL;
    if (!serv)
        return;
    for (int i = 1; i < FD_SETSIZE; i++) {
        if (serv->all_co[i].fd < 1 || serv->all_co[i].is_player)
            continue;
        cmd = rotate_buffer(serv->all_co[i].buffer);
        if (!cmd)
            continue;
        parsed = my_str_to_word_array(cmd, " \n");
        if (!check_ai_co(serv, parsed, i) || !check_gui_co(serv, parsed, i)) {
            free(cmd);
            return free_command(parsed);
        }
        free(cmd);
        free_command(parsed);
        send_ko(serv->all_co[i].fd);
    }
}
