/*
** EPITECH PROJECT, 2023
** teams
** File description:
** check_command
*/

#include "zappy_server.h"

int handle_team_connection(const char *cmd, server_t *server, int index)
{
    if (!cmd || !server)
        return -1;
    if (server->all_co[index].is_player)
        return -1;
    for (int i = 0; i < server->game.teams_nb; i++) {
        if (!strcmp(cmd, server->game.team_names[i])) {
            init_connection_sequence(server, index, i);
            return 0;
        }
    }
    return -1;
}

int get_command_string(server_t* server, int index)
{
    size_t size = 0;
    char *buff = NULL;
    player_t *tmp = NULL;
    buff = malloc(sizeof(char) * 4096);
    if (!buff)
        return ERROR;
    memset(buff, '\0', 4096);
    size = read(server->all_co[index].fd, buff, 4096);
    if (size <= 0) {
        remove_client(server, index);
        free(buff);
        return ERROR;
    }
    tmp = find_player_by_uuid(server->game.players, server->all_co[index].id);
    if (!tmp) {
        add_to_buffer(server->all_co[index].buffer, buff);
        return 0;
    }
    add_to_buffer(tmp->command_buffer, buff);
    return 0;
}

int check_command(server_t* server)
{
    for (int i = 1; i < FD_SETSIZE; i++) {
        if (FD_ISSET(server->all_co[i].fd, &server->rfds)) {
            get_command_string(server, i);
        }
    }
    return SUCCESS;
}
