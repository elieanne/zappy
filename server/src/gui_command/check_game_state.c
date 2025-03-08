/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** check_game_state.c
*/

#include "zappy_server.h"

static void free_resources(char *result, int *teams)
{
    free(result);
    free(teams);
}

int send_seg_event(int size, int *teams, game_t *game)
{
    char *result = NULL;
    if (!teams || !game)
        return -1;
    result = strdup("seg ");
    if (size == 0) {
        send_gui_event(game->players, my_strcat(result, "NULL\n"));
        free(teams);
        return 0;
    }
    for (int i = 0; i < game->teams_nb; i++) {
        if (teams[i] < 6)
            continue;
        result = my_strcat(result, game->team_names[i]);
        send_gui_event(game->players, my_strcat(result, "\n"));
        free(teams);
        return 0;
    }
    free_resources(result, teams);
    return -1;
}

int check_game_state(game_t *game)
{
    int size = 0;
    player_t *save = game->players;
    int *teams = NULL;

    if (game->is_win)
        return 0;
    teams = malloc(sizeof(int) * game->teams_nb);
    if (!teams)
        return -1;
    for (int i = 0; i < game->teams_nb; i++)
        teams[i] = 0;
    for (; save != NULL; save = save->next) {
        if (save->type == GUI)
            continue;
        size++;
        if (save->level < 8)
            continue;
        teams[save->team]++;
    }
    return send_seg_event(size, teams, game);
}
