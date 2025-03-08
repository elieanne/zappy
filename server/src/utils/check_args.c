/*
** EPITECH PROJECT, 2023
** teams
** File description:
** check_args
*/

#include "zappy_server.h"

int get_command_size(char** command_tab)
{
    int i = 0;

    if (command_tab == NULL)
        return 0;

    while (command_tab[i] != NULL) {
        i++;
    }
    return i;
}

void free_command(char** command_tab)
{
    int i = 0;
    if (!command_tab)
        return;
    while (command_tab[i] != NULL) {
        if (command_tab[i])
            free(command_tab[i]);
        i++;
    }
    free(command_tab);
}
