/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** broadcast_event.c
*/

#include "zappy_server.h"

char *format_broadcast_info(int id, char *msg)
{
    char *result = NULL;
    size_t size = 0;
    if (!msg)
        return NULL;
    size = strlen(msg);
    result = malloc(sizeof(char) * (17 + size));
    if (!result)
        return NULL;
    sprintf(result, "pbc %d %s\n", id, msg);
    return result;
}
