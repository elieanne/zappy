/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** rotate_buffer
*/

#include "game.h"
#include <string.h>

// Rotate the buffer : return the first element and pop it

char *rotate_buffer(char **buffer)
{
    char *tmp = NULL;

    if (!buffer)
        return NULL;
    if (!buffer[0])
        return NULL;
    tmp = buffer[0];
    for (int i = 0; i < 10; i++) {
        buffer[i] = buffer[i + 1];
    }
    return tmp;
}
