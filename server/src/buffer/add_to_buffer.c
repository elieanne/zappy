/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** add_to_buffer
*/

#include "zappy_server.h"

// Add the given parameter to the buffer if there is space for it

int add_to_buffer(char **buffer, char *cmd)
{
    char **parsed = NULL;
    int last_index = 0;
    int loc_index = 0;

    parsed = my_str_to_word_array(cmd, "\n");
    if (!parsed || !cmd || !buffer)
        return ERROR;
    for (last_index = 0; last_index < 10; last_index++)
        if (!buffer[last_index])
            break;
    while (last_index < 10 && parsed[loc_index]) {
        buffer[last_index] = parsed[loc_index];
        last_index++;
        loc_index++;
    }
    for (; parsed[loc_index]; loc_index++)
        free(parsed[loc_index]);
    free(parsed);
    free(cmd);
    return SUCCESS;
}
