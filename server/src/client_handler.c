/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myftp-elouan.savy-camaret
** File description:
** client_handler
*/

#include "zappy_server.h"

void remove_client(server_t* server, int index)
{
    player_t *tmp = NULL;
    close(server->all_co[index].fd);
    server->all_co[index].fd = -1;
    server->all_co[index].is_player = false;
    tmp = find_player_by_uuid(server->game.players, server->all_co[index].id);
    server->all_co[index].id = -1;
    if (!tmp) {
        free_command(server->all_co[index].buffer);
        server->all_co[index].buffer = NULL;
        return;
    }
    server->all_co[index].buffer = NULL;
    tmp->type = DEAD;
    tmp->fd = -1;
    tmp->client_index = -1;
}

int add_client(server_t* s, int fd, int index)
{
    if (s->all_co[index].fd != -1) {
        return ERROR;
    }
    dprintf(fd, "WELCOME\n");
    s->all_co[index].id = -1;
    s->all_co[index].fd = fd;
    s->all_co[index].buffer = init_cmd_buffer();
    return SUCCESS;
}
