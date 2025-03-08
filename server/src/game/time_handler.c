/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** time_handler.c
*/

#include "zappy_server.h"

void handle_cooldown(player_t *players, int nb)
{
    player_t *tmp = NULL;
    if (!players)
        return;
    tmp = players;
    while (tmp != NULL) {
        if (tmp->cooldown >= nb)
            tmp->cooldown -= nb;
        else
            tmp->cooldown = 0;
        tmp = tmp->next;
    }
}

void wait_cycle(struct timespec start, struct timespec end, game_t *game)
{
    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 +
        (end.tv_nsec - start.tv_nsec) / 1000;
    uint64_t s_freq = 1000000 / game->freq;
    int ticks = 0;
    if (s_freq > delta_us) {
        handle_cooldown(game->players, 1);
        handle_death(game->players, 1);
        game->food_respawn += 1;
        usleep(s_freq - delta_us);
    } else {
        ticks = (int) (delta_us / s_freq);
        handle_cooldown(game->players, ticks);
        handle_death(game->players, ticks);
        game->food_respawn += ticks;
    }
    if (game->food_respawn >= 20) {
        spawn_ressources(game);
        game->food_respawn = 0;
    }
}
