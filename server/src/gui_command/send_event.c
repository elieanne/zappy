/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** send_event.c
*/

#include "zappy_server.h"

int send_existing_players(server_t *s, player_t *player)
{
    player_t *tmp = NULL;
    char *str = NULL;
    if (!player || !s || !s->game.players)
        return ERROR;

    for (tmp = s->game.players; tmp; tmp = tmp->next) {
        if (tmp->type == PLAYER &&
        (str = get_connection_info(tmp, &s->game))) {
            dprintf(player->fd, "%s", str);
            free(str);
        }
    }
    return SUCCESS;
}

void send_gui_event(player_t *players, char *cmd)
{
    player_t *tmp = NULL;
    if (!cmd)
        return;
    if (!players) {
        free(cmd);
        return;
    }
    tmp = players;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->type != GUI || tmp->fd == -1)
            continue;
        dprintf(tmp->fd, "%s", cmd);
    }
    free(cmd);
}
