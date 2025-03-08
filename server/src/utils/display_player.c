/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** display_player.c
*/

#include "zappy_server.h"

void display_user(player_t *player)
{
    player_t *save = NULL;
    save = player;
    while (save != NULL) {
        if (save->type != PLAYER) {
            save = save->next;
            continue;
        }
        printf("%ld === [PLAYER] player %d: team => %d", clock(),
            save->id, save->team);
        if (save->command_buffer)
            printf(", buffer[0] => %s", save->command_buffer[0]);
        printf(", current_cmd => %s", save->current_cmd);
        printf("\n");
        save = save->next;
    }
    printf("%ld === ------------------------------\n", clock());
}
