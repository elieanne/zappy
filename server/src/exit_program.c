/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** exit_program.c
*/

#include "zappy_server.h"

int exit_program(server_t *server, parsed_info_t *infos)
{
    if (!server)
        return 84;
    free_game(&server->game);
    FD_ZERO(&server->wfds);
    FD_ZERO(&server->rfds);
    free(server);
    free(infos);
    return 0;
}

void free_server_base(server_t *server, parsed_info_t *infos)
{
    int i = 0;
    if (server) {
        FD_ZERO(&server->wfds);
        FD_ZERO(&server->rfds);
        free(server);
    }
    if (infos) {
        while (infos->names != NULL && infos->names[i] != NULL) {
            free(infos->names[i]);
            i++;
        }
        if (infos->names)
            free(infos->names);
        free(infos);
    }
}

int free_game_struct(server_t *server, parsed_info_t *infos)
{
    int i = 0;
    if (!server)
        return 84;
    free_game(&server->game);
    FD_ZERO(&server->wfds);
    FD_ZERO(&server->rfds);
    free(server);
    while (infos->names != NULL && infos->names[i] != NULL) {
        free(infos->names[i]);
        i++;
    }
    if (infos->names)
        free(infos->names);
    free(infos);
    return 0;
}
