/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** teams.c
*/

#include "zappy_server.h"

char *format_team_name(char *name)
{
    size_t size = 0;
    char *result = NULL;
    if (!name)
        return NULL;
    size = strlen(name);
    result = malloc(sizeof(char) * (6 + size));
    if (!result)
        return NULL;
    sprintf(result, "tna %s\n", name);
    return result;
}

char *get_team_names(game_t *game)
{
    char *result = NULL;
    char *tmp = NULL;
    if (!game)
        return NULL;
    for (int i = 0; i < game->teams_nb; i++) {
        tmp = format_team_name(game->team_names[i]);
        result = my_strcat(result, tmp);
        free(tmp);
    }
    return result;
}

int gui_teams_name(server_t *server, player_t *player, char **cmds)
{
    char *result = NULL;
    if (!server || !player || !cmds)
        return -1;
    result = get_team_names(&server->game);
    dprintf(player->fd, "%s", result);
    free(result);
    return 0;
}
