/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** count_player
*/

#include "zappy_server.h"

int get_len_player(user_id_t *list)
{
    int len = 0;
    user_id_t *tmp = list;

    if (!list)
        return 0;
    for (; tmp != NULL; tmp = tmp->next)
        len++;
    return len;
}
