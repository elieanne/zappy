/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** free_parsing.c
*/

#include "zappy_server.h"

void free_parsing(parsed_info_t *info)
{
    int i = 0;
    if (!info)
        return;
    while (info->names != NULL && info->names[i] != NULL) {
        free(info->names[i]);
        i++;
    }
    if (info->names)
        free(info->names);
    free(info);
}
