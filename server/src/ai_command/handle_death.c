/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** handle_death.c
*/

#include "zappy_server.h"

void handle_death(player_t *player, int nb)
{
    player_t *save = NULL;
    if (!player)
        return;
    save = player;
    while (save != NULL) {
        if (save->type != PLAYER) {
            save = save->next;
            continue;
        }
        save->food_clock += nb;
        if (save->food_clock >= 126) {
            save->inventory.food -= 1;
            save->food_clock %= 126;
        }
        if (save->inventory.food <= 0)
            save->type = DEAD;
        save = save->next;
    }
}
