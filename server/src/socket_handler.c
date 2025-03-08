/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myftp-elouan.savy-camaret
** File description:
** socket_handler
*/

#include "zappy_server.h"

int handle_connection(server_t* server)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int new_fd = -1;

    new_fd = accept(server->socket_fd, (struct sockaddr*)&addr, &len);
    if (new_fd < 0)
        return ERROR;
    for (int i = 1; i < FD_SETSIZE; i++) {
        if (add_client(server, new_fd, i) == SUCCESS) {
            return SUCCESS;
        }
    }
    close(new_fd);
    return ERROR;
}

int create_socket(int port, char* ip)
{
    struct sockaddr_in my_addr;
    int s;

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = inet_addr(ip);
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(s, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1) {
        printf("Error in binding\n");
        close(s);
        return -1;
    }
    return s;
}
