/*
** EPITECH PROJECT, 2023
** Bootstrap-FTP
** File description:
** main
*/

#include <stdio.h>
#include "parsing.h"
#include "zappy_server.h"

void display_usage(void)
{
    FILE* fd = fopen("server/doc/help.txt", "r");
    char* str = NULL;
    size_t len = 0;
    if (!fd)
        return;
    getdelim(&str, &len, 0, fd);
    if (str)
        printf("%s", str);
}

server_t *init_server(server_t *server, parsed_info_t *parsed_info)
{
    if (!parsed_info)
        return NULL;
    server = malloc(sizeof(server_t));
    if (!server)
        return NULL;
    if (create_server(server, parsed_info->port) == ERROR) {
        free_server_base(server, parsed_info);
        return NULL;
    }
    return server;
}

int main(int argc, char** argv)
{
    server_t* server = NULL;
    (void)argc;
    parsed_info_t *parsed_info = parse_args(argv);
    srand(time(NULL));
    if (parsed_info == NULL) {
        display_usage();
        return ERROR;
    }
    server = init_server(server, parsed_info);
    if (server == NULL)
        return ERROR;
    if (init_game(server, parsed_info) == ERROR)
        return ERROR;
    init_player_list(&server->game);
    display_user(server->game.players);
    spawn_ressources(&server->game);
    return server_loop(server, parsed_info);
}
