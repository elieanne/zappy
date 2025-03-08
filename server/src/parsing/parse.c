/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** parse
*/

#include "parsing.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *get_arg(char const *flag, char **argv)
{
    int i = 0;

    if (!flag)
        return NULL;
    while (argv[i]) {
        if (strcmp(argv[i], flag) == 0 && argv[i + 1])
            return argv[i + 1];
        i++;
    }
    return NULL;
}

int get_nb_teams(char **argv)
{
    int i = 0;
    int nb = 0;
    if (!argv)
        return -1;
    while (argv[i] && strcmp(argv[i], "-n") != 0)
        i++;
    i++;
    while (argv[i] && argv[i][0] != '-') {
        i++;
        nb++;
    }
    return nb;
}

char** get_teams(char** argv)
{
    int nb_teams = get_nb_teams(argv);
    int i = 0;
    char** teams = NULL;
    if (!argv || nb_teams < 0)
        return NULL;
    teams = malloc(sizeof(char*) * (nb_teams + 1));
    if (!teams)
        return NULL;
    teams[nb_teams] = NULL;
    while (argv[i] && strcmp(argv[i], "-n") != 0)
        i++;
    i++;
    for (int j = 0; j < nb_teams; j++) {
        if (argv[i])
            teams[j] = strdup(argv[i]);
        i++;
    }
    return teams;
}

bool need_help(char **argv)
{
    if (!argv)
        return true;
    for (int i = 0; argv[i]; i++) {
        if (argv[i] &&
        (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0))
            return true;
    }
    return false;
}

parsed_info_t* parse_args(char ** argv)
{
    if (!argv)
        return NULL;
    if (need_help(argv))
        return NULL;
    parsed_info_t* parsed_info = malloc(sizeof(parsed_info_t));
    if (!parsed_info)
        return NULL;
    parsed_info->port = get_arg("-p", argv);
    parsed_info->width = get_arg("-x", argv);
    parsed_info->height = get_arg("-y", argv);
    parsed_info->clients_nb = get_arg("-c", argv);
    parsed_info->freq = get_arg("-f", argv);
    parsed_info->names = get_teams(argv);
    if (!parsed_info->port || !parsed_info->width || !parsed_info->height ||
    !parsed_info->clients_nb || !parsed_info->names ||
    check_parsing(parsed_info) == 84) {
        free_parsing(parsed_info);
        return NULL;
    }
    return parsed_info;
}
