/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** server_loop_utils.c
*/

#include "zappy_server.h"

int get_fd_max (server_t *server)
{
    int max = 0;

    for (int i = 0; i < FD_SETSIZE; i++) {
        if (server->all_co[i].fd > max)
            max = server->all_co[i].fd;
    }
    return max;
}

void fill_fd_list(server_t* server)
{
    FD_ZERO(&server->rfds);
    FD_ZERO(&server->wfds);
    server->fd_max = 0;
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (server->all_co[i].fd > 0) {
            FD_SET(server->all_co[i].fd, &server->rfds);
            FD_SET(server->all_co[i].fd, &server->wfds);
        }
    }
    FD_SET(0, &server->rfds);
    server->fd_max = get_fd_max(server);
}
