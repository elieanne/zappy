/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** add_palyer
*/

#include "zappy_server.h"

player_t *get_egg(server_t *server, int team_id)
{
    player_t *save = server->game.players;
    while (save != NULL) {
        if ((save->team != team_id) || save->type == PLAYER) {
            save = save->next;
            continue;
        }
        return save;
    }
    return NULL;
}

char *get_connection_info(player_t *player, game_t *game)
{
    char *result = NULL;
    char *team_name = NULL;
    if (!player || !game)
        return NULL;
    team_name = game->team_names[player->team];
    if (!team_name)
        return NULL;
    result = malloc(sizeof(char) * (62 + strlen(team_name)));
    if (!player->was_egg) {
        sprintf(result, "pnw %d %d %d %d %d %s\n", player->id, player->tile->x,
            player->tile->y, player->orientation, player->level, team_name);
    } else
        sprintf(result, "ebo %d\n", player->id);
    return result;
}

void init_connection_sequence(server_t *s, int index, int team_id)
{
    int fd = s->all_co[index].fd;
    int available = s->game.team_slot[team_id];
    player_t *egg = NULL;
    if ((available - 1) < 0)
        return send_ko(s->all_co[index].fd);
    s->game.team_slot[team_id]--;
    dprintf(fd, "%d\n%d %d\n", available - 1, s->game.map.width,
    s->game.map.height);
    egg = get_egg(s, team_id);
    if (!egg)
        return;
    egg->type = PLAYER;
    egg->fd = fd;
    egg->inventory.food = 10;
    egg->team = team_id;
    egg->command_buffer = s->all_co[index].buffer;
    egg->client_index = index;
    s->all_co[index].id = egg->id;
    s->all_co[index].is_player = true;
    send_gui_event(s->game.players, get_connection_info(egg, &s->game));
}
