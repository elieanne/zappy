/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** eject
*/

#include "zappy_server.h"
#include "ai_command.h"

int exec_eject(server_t *server, player_t **list_player, player_t *player,
int dir[2])
{
    if (!server || !list_player || !player)
        return ERROR;

    for (int j = 0; list_player[j] != NULL; j++) {
        switch (list_player[j]->type) {
            case EGG:
                handle_egg(server, list_player[j]);
                break;
            case PLAYER:
                move_player(server, list_player[j], dir[0], dir[1]);
                dprintf(list_player[j]->fd, "eject: %d\n",
                switch_direction(player->orientation));
                gui_player_pos_event(server->game.players, list_player[j]);
                break;
            default:
                break;
        }
    }
    return SUCCESS;
}

int eject_players(int x_off, int y_off, server_t *server, player_t *player)
{
    int nb_player = 0;
    int i = 0;
    if (!server || !server->game.players || !player || !player->tile->id_list)
        return ERROR;
    if ((nb_player = get_len_player(player->tile->id_list)) <= 1)
        return ERROR;
    player_t** list_player = malloc(sizeof(player_t*) * nb_player);
    if (list_player == NULL)
        return ERROR;
    list_player[nb_player - 1] = NULL;
    for (user_id_t* tm = player->tile->id_list; tm != NULL; tm = tm->next) {
        if (player->id == tm->id)
            continue;
        list_player[i] = find_player_by_uuid(server->game.players, tm->id);
        i++;
    }
    exec_eject(server, list_player, player, (int[2]) {x_off, y_off});
    free(list_player);
    send_gui_event(server->game.players, get_eject_info(player));
    return SUCCESS;
}

int eject(server_t *server, player_t *player, char** cmds)
{
    int ret_val = 0;
    if (!player || !server || !server->game.players || cmds[1])
        return ERROR;
    if (player->orientation == TOP)
        ret_val += eject_players(0, -1, server, player);
    if (player->orientation == BOTTOM)
        ret_val += eject_players(0, 1, server, player);
    if (player->orientation == LEFT)
        ret_val += eject_players(-1, 0, server, player);
    if (player->orientation == RIGHT)
        ret_val += eject_players(1, 0, server, player);
    if (ret_val == ERROR)
        return ERROR;
    send_ok(player->fd);
    return SUCCESS;
}
