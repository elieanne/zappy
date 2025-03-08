/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** check_parsing
*/

#include "parsing.h"
#include "zappy_server.h"

int print_parsing_error(char *str)
{
    if (!str)
        return ERROR;
    printf("Error: %s\n", str);
    return ERROR;
}

int check_parsing(parsed_info_t *infos)
{
    if (!infos)
        return ERROR;

    if (infos->clients_nb && atoi(infos->clients_nb) < 1)
        return print_parsing_error("clients_nb must be > 0");
    if (infos->width && (atoi(infos->width) < 10 || atoi(infos->width) > 30))
        return print_parsing_error("width must be between 10 and 30");
    if (infos->height &&
    (atoi(infos->height) < 10 || atoi(infos->height) > 30))
        return print_parsing_error("height must be between 10 and 30");
    if (infos->freq && (atoi(infos->freq) < 2 || atoi(infos->freq) > 10000))
        return print_parsing_error("freq must be between 2 and 10000");
    if (infos->port && (atoi(infos->port) < 1 || atoi(infos->port) > 65535))
        return print_parsing_error("port must be between 1 and 65535");
    if (infos->names && infos->names[0] == NULL)
        return print_parsing_error("names must be at least one");
    return SUCCESS;
}
