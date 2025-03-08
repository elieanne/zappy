/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_buffer
*/

#include <stdlib.h>

char **init_cmd_buffer(void)
{
    char **command_buffer = malloc(sizeof(char*) * 11);
    if (!command_buffer)
        return NULL;
    for (int i = 0; i < 11; i++) {
        command_buffer[i] = NULL;
    }
    return command_buffer;
}
