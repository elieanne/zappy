/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** incantation_event.c
*/

#include "zappy_server.h"

char *get_start_inc_infos(player_t *player)
{
    char *result = NULL;
    if (!player)
        return NULL;
    result = malloc(sizeof(char) * 39);
    if (!result)
        return NULL;
    sprintf(result, "pic %d %d %d", player->tile->x, player->tile->y,
        player->level);
    return result;
}

char *get_end_inc_infos(player_t *player)
{
    char *result = NULL;
    if (!player)
        return NULL;
    result = malloc(sizeof(char) * 39);
    if (!result)
        return NULL;
    sprintf(result, "pie %d %d %d\n", player->tile->x, player->tile->y,
        player->level);
    return result;
}

char *add_player_id_to_str(char *str, int id)
{
    char tmp_player_str[20] = {'\0'};
    sprintf(tmp_player_str, " %d", id);
    return my_strcat(str, tmp_player_str);
}
