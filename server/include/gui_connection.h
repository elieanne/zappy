/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** gui_connection.h
*/
#ifndef GUI_CONNECTION_H_
    #define GUI_CONNECTION_H_
    #include "zappy_server.h"

typedef struct steps_s {
    char *(*exec)(game_t *game);
} steps_t;

const steps_t steps[] = {
    {&format_server_freq},
    {&format_tile_info},
    {&get_team_names},
    {NULL}
};
#endif /*GUI_CONNECTION_H_*/
