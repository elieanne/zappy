/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** broadcast
*/

#include "zappy_server.h"
#include <math.h>

bool is_valid_broadcast(server_t *server, player_t *player, char **cmds)
{
    if (!server || !player || !cmds)
        return false;
    if (get_command_size(cmds) < 2)
        return false;
    return true;
}

void get_side_distances(int dist[4], coord_t player_pos,
coord_t tmp_pos, game_t *game)
{
    if (!game)
        return;
    if (tmp_pos.x > player_pos.x) {
        dist[3] = tmp_pos.x - player_pos.x;
        dist[2] = - (game->map.width - dist[3]);
    } else if (tmp_pos.x < player_pos.x) {
        dist[2] = - (player_pos.x - tmp_pos.x);
        dist[3] = game->map.width + dist[2];
    }

    if (tmp_pos.y > player_pos.y) {
        dist[1] = tmp_pos.y - player_pos.y;
        dist[0] = - (game->map.height - dist[1]);
    } else if (tmp_pos.y < player_pos.y) {
        dist[0] = - (player_pos.y - tmp_pos.y);
        dist[1] = game->map.height + dist[0];
    }
}

float get_front_len(player_t *tmp, coord_t tmp_pos)
{
    coord_t player_pos = {0, 0};
    float len_front = 0;
    if (!tmp)
        return -1;
    switch (tmp->orientation) {
    case TOP:
        len_front = get_len(player_pos, (coord_t) {tmp_pos.x, tmp_pos.y -1});
        break;
    case BOTTOM:
        len_front = get_len(player_pos, (coord_t) {tmp_pos.x, tmp_pos.y + 1});
        break;
    case LEFT:
        len_front = get_len(player_pos, (coord_t) {tmp_pos.x -1, tmp_pos.y});
        break;
    case RIGHT:
        len_front = get_len(player_pos, (coord_t) {tmp_pos.x + 1, tmp_pos.y});
        break;
    }
    return len_front;
}

// TOP BOT LEFT RIGH
int get_angle(game_t *game, player_t *player, player_t *tmp)
{
    coord_t player_pos = {0, 0};
    coord_t tmp_pos = {0, 0};
    int dist[4] = { 0, 0, 0, 0 };
    float len_player = 0;
    float len_front = 0;
    float angle = 0;
    if (!game || !player || !tmp)
        return -1;
    if (player->tile == tmp->tile)
        return 0;
    player_pos = (coord_t) { player->tile->x, player->tile->y };
    tmp_pos = (coord_t) {tmp->tile->x, tmp->tile->y};
    get_side_distances(dist, player_pos, tmp_pos, game);
    tmp_pos = get_closest_dir(dist);
    player_pos = (coord_t) {0, 0};
    len_player = get_len(player_pos, tmp_pos);
    len_front = get_front_len(tmp, tmp_pos);
    angle = acos((pow(len_player, 2) + 1 - pow(len_front, 2))
    / (2 * len_player)) * 180 / M_PI;
    return get_right_split(convert_angle(angle, tmp, tmp_pos));
}

int broadcast(server_t *server, player_t *player, char** cmds)
{
    char *full_msg = NULL;

    if (!server || !player || !cmds || !server->game.players)
        return ERROR;
    for (int i = 1; cmds[i]; i++) {
        full_msg = my_strcat(full_msg, cmds[i]);
        if (cmds[i + 1])
            full_msg = my_strcat(full_msg, " ");
    }
    for (player_t* tmp = server->game.players; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == PLAYER && tmp->id != player->id) {
            dprintf(tmp->fd, "message %d, %s\n",
                get_angle(&server->game, player, tmp), full_msg);
        }
    }
    send_ok(player->fd);
    send_gui_event(server->game.players,
    format_broadcast_info(player->id, full_msg));
    free(full_msg);
    return SUCCESS;
}
