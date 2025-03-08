/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** server_message.c
*/

#include "zappy_server.h"

void send_msg_to_gui(player_t *players, char *msg)
{
    player_t *tmp = NULL;
    if (!players || !msg)
        return;
    tmp = players;
    while (tmp != NULL) {
        if (tmp->type != GUI || tmp->fd == -1) {
            tmp = tmp->next;
            continue;
        }
        dprintf(tmp->fd, "%s", msg);
        tmp = tmp->next;
    }
    free(msg);
}
