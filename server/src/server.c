/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myftp-elouan.savy-camaret
** File description:
** server_loop
*/

#include <signal.h>
#include <unistd.h>
#include "zappy_server.h"

int store_command(server_t *s)
{
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    int read_value = 0;
    fill_fd_list(s);
    read_value = select(s->fd_max + 1, &s->rfds, NULL, NULL, &tv);
    if (!read_value)
        return -1;
    if (FD_ISSET(s->socket_fd, &s->rfds))
        handle_connection(s);
    if (FD_ISSET(0, &s->rfds))
        check_stdin();
    check_command(s);
    return 0;
}

void exec_all_cmd(server_t *serv)
{
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    player_t *save = NULL;
    if (!serv)
        return;
    save = serv->game.players;
    if (!select(serv->fd_max + 1, NULL, &serv->wfds, NULL, &tv))
        return;
    while (save != NULL) {
        if (save->type == DEAD) {
            save = save->next;
            continue;
        }
        if (save->fd != -1 && FD_ISSET(save->fd, &serv->wfds))
            exec_command(serv, save);
        save = save->next;
    }
}

int server_loop(server_t* serv, parsed_info_t *infos)
{
    struct timespec start;
    struct timespec end;
    signal(SIGPIPE, SIG_IGN);
    listen(serv->socket_fd, FD_SETSIZE);
    while (can_continue()) {
        get_signal();
        clock_gettime(CLOCK_MONOTONIC_RAW, &start);
        store_command(serv);
        check_connection_sequence(serv);
        display_user(serv->game.players);
        exec_all_cmd(serv);
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);
        wait_cycle(start, end, &serv->game);
        remove_dead_players(serv);
        if (check_game_state(&serv->game) == 0)
            reset_game(serv);
    }
    return exit_program(serv, infos);
}

int create_server(server_t* server, char *port)
{
    int port_int = 0;
    if (!port || !server)
        return ERROR;
    port_int = atoi(port);
    server->socket_fd = create_socket(port_int, "0.0.0.0");
    if (server->socket_fd == -1)
        return ERROR;
    for (int i = 0; i < FD_SETSIZE; i++) {
        server->all_co[i].fd = -1;
        server->all_co[i].id = -1;
        server->all_co[i].is_player = false;
    }
    server->all_co[SOCKET_INDEX].fd = server->socket_fd;
    server->fd_max = server->socket_fd;
    return SUCCESS;
}
