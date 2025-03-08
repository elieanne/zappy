/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** player
*/

#include "zappy_server.h"

void free_player(player_t *player)
{
    if (!player) {
        return;
    }
    free_command(player->command_buffer);
    if (player->current_cmd)
        free(player->current_cmd);
    free(player);
}

player_t *add_player_back(player_t *player, player_t *new_player)
{
    player_t* tmp = NULL;

    if (player == NULL) {
        new_player->next = NULL;
        return new_player;
    }
    tmp = player;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_player;
    return player;
}

player_t *find_player_by_uuid(player_t *player, int uuid)
{
    player_t* tmp = player;
    if (!player)
        return NULL;
    while (tmp) {
        if (check_uuid(tmp->id, uuid))
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

player_t *remove_node(player_t *list, player_t *prev, player_t *player)
{
    player_t *tmp = NULL;
    if (prev == NULL) {
        if (!player->next) {
            free_player(player);
            return NULL;
        }
        tmp = player->next;
        player->next = NULL;
        free_player(player);
        return tmp;
    } else {
        prev->next = player->next;
        player->next = NULL;
        free_player(player);
        return list;
    }
}
