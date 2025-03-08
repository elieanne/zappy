/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** incantation
*/

#include "zappy_server.h"
#include "ai_command.h"

int start_incantation(server_t *server, player_t *player)
{
    user_id_t *tmp = NULL;
    player_t *tmp_p = NULL;
    char *result = NULL;
    if (!player || !player->tile || !player->tile->id_list ||
    !server || !server->game.players)
        return ERROR;
    result = get_start_inc_infos(player);
    tmp = player->tile->id_list;
    for (; tmp != NULL; tmp = tmp->next) {
        tmp_p = find_player_by_uuid(server->game.players, tmp->id);
        if (tmp_p && tmp_p->level == player->level && tmp_p->type == PLAYER) {
            tmp_p->elevating = true;
            dprintf(tmp_p->fd, "Elevation underway\n");
            result = add_player_id_to_str(result, tmp_p->id);
        }
    }
    player->elevating = false;
    send_gui_event(server->game.players, my_strcat(result, "\n"));
    return SUCCESS;
}

bool is_valid_incantation(server_t *server, player_t *player, char **cmds)
{
    if (!server || !player || !cmds)
        return false;
    if (get_command_size(cmds) != 1)
        return false;
    if (check_incantation(server, player) == false)
        return false;
    start_incantation(server, player);
    return true;
}

int reset_elevation(server_t *server, player_t *player)
{
    user_id_t *tmp = NULL;
    player_t *tmp_player = NULL;
    if (!player || !player->tile || !player->tile->id_list ||
    !server || !server->game.players)
        return ERROR;
    tmp = player->tile->id_list;
    player->elevating = false;
    for (; tmp != NULL; tmp = tmp->next) {
        tmp_player = find_player_by_uuid(server->game.players, tmp->id);
        if (tmp_player && tmp_player->level == player->level &&
            tmp_player != player) {
            tmp_player->elevating = false;
            send_ko(tmp_player->fd);
        }
    }
    return SUCCESS;
}

int level_up_players(server_t *server, player_t *player)
{
    user_id_t *tmp = NULL;
    player_t *tmp_p = NULL;
    int save_level = 0;
    if (!player || !player->tile || !player->tile->id_list
    || !server || !server->game.players)
        return ERROR;
    save_level = player->level;
    tmp = player->tile->id_list;
    for (; tmp != NULL; tmp = tmp->next) {
        tmp_p = find_player_by_uuid(server->game.players, tmp->id);
        if (tmp_p && tmp_p->level == save_level && tmp_p->type == PLAYER) {
            tmp_p->level++;
            tmp_p->elevating = false;
            gui_player_lvl_event(server->game.players, tmp_p);
            dprintf(tmp_p->fd, "Current level: %d\n", tmp_p->level);
        }
    }
    return SUCCESS;
}

int finish_incantation(server_t *server, player_t *player, char** cmds)
{
    if (!server || !player || !cmds)
        return ERROR;
    if (get_command_size(cmds) != 1) {
        send_gui_event(server->game.players, get_end_inc_infos(player));
        return ERROR;
    }
    if (check_incantation(server, player) == false) {
        reset_elevation(server, player);
        send_gui_event(server->game.players, get_end_inc_infos(player));
        return ERROR;
    }
    remove_resources(&player->tile->inventory, player->level);
    send_gui_event(server->game.players, get_end_inc_infos(player));
    level_up_players(server, player);
    return SUCCESS;
}
