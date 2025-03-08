/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** check_incantation
*/

#include "incantation.h"
#include "zappy_server.h"

int get_player_on_tile(game_t *game, tile_t *tile, int level)
{
    int nb = 0;
    player_t *tmp_player = NULL;

    if (!tile || !tile->id_list || !game || !game->players)
        return 0;
    for (user_id_t *tmp = tile->id_list; tmp != NULL; tmp = tmp->next) {
        tmp_player = find_player_by_uuid(game->players, tmp->id);
        if (tmp_player && tmp_player->level == level
        && tmp_player->type == PLAYER) {
            nb++;
        }
    }
    return nb;
}

int remove_resources(inventory_t *inventory, int level)
{
    if (!inventory)
        return ERROR;
    inventory->linemate -= incantation_rule[level - 1].linemate;
    inventory->deraumere -= incantation_rule[level - 1].deraumere;
    inventory->sibur -= incantation_rule[level - 1].sibur;
    inventory->mendiane -= incantation_rule[level - 1].mendiane;
    inventory->phiras -= incantation_rule[level - 1].phiras;
    inventory->thystame -= incantation_rule[level - 1].thystame;
    return SUCCESS;
}

bool check_incantation(server_t *server, player_t *player)
{
    inventory_t inv;
    if (!server || !player || !player->tile)
        return false;
    inv = player->tile->inventory;
    if (get_player_on_tile(&server->game, player->tile, player->level)
    != incantation_rule[player->level - 1].nb_player)
        return false;
    if (inv.linemate != incantation_rule[player->level - 1].linemate)
        return false;
    if (inv.deraumere != incantation_rule[player->level - 1].deraumere)
        return false;
    if (inv.sibur != incantation_rule[player->level - 1].sibur)
        return false;
    if (inv.mendiane != incantation_rule[player->level - 1].mendiane)
        return false;
    if (inv.phiras != incantation_rule[player->level - 1].phiras)
        return false;
    if (inv.thystame != incantation_rule[player->level - 1].thystame)
        return false;
    return true;
}
