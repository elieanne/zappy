/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** take
*/

#include "zappy_server.h"
#include "take_command.h"

char *get_take_drop_info(player_t *player, int object_id, int action)
{
    char *result = NULL;
    if (!player)
        return NULL;
    result = malloc(sizeof(char) * 27);
    if (action == 1)
        sprintf(result, "pgt %d %d\n", player->id, object_id);
    else
        sprintf(result, "pdr %d %d\n", player->id, object_id);
    return result;
}

bool is_valid_take(server_t *server, player_t *player, char **cmds)
{
    if (!server || !player || !cmds)
        return false;
    if (get_command_size(cmds) != 2)
        return false;
    for (int i = 0; take_commands[i].object; i++) {
        if (strcmp(take_commands[i].object, cmds[1]) == 0)
            return true;
    }
    return false;
}

int take_object(server_t *server, player_t *player, char** cmds)
{
    int ret_value = -1;
    if (!player)
        return ERROR;
    if (!cmds || !cmds[1] || cmds[2] || !server)
        return ERROR;
    for (int i = 0; take_commands[i].object; i++) {
        if (strcmp(take_commands[i].object, cmds[1]) == 0) {
            ret_value = take_commands[i].take(player, server);
            gui_inv_event(server->game.players, player);
            return ret_value;
        }
    }
    return ERROR;
}

int drop_object(server_t *server, player_t *player, char** cmds)
{
    int ret_value = -1;
    if (!player)
        return ERROR;
    if (!cmds || !cmds[1] || cmds[2] || !server)
        return ERROR;
    for (int i = 0; take_commands[i].object; i++) {
        if (strcmp(take_commands[i].object, cmds[1]) == 0) {
            ret_value = take_commands[i].drop(player, server);
            gui_inv_event(server->game.players, player);
            return ret_value;
        }
    }
    return ERROR;
}
