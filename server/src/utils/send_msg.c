/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myftp-elouan.savy-camaret
** File description:
** send_msg
*/

#include "zappy_server.h"

void send_ok(int fd)
{
    dprintf(fd, "ok\n");
}

void send_ko(int fd)
{
    dprintf(fd, "ko\n");
}
