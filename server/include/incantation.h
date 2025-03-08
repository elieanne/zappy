/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** incantation
*/

#ifndef INCANTATION_H_
    #define INCANTATION_H_

typedef struct incantation_s {
    int nb_player;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} incantation_t;

incantation_t incantation_rule[] = {
    { 1, 1, 0, 0, 0, 0, 0 },
    { 2, 1, 1, 1, 0, 0, 0 },
    { 2, 2, 0, 1, 0, 2, 0 },
    { 4, 1, 1, 2, 0, 1, 0 },
    { 4, 1, 2, 1, 3, 0, 0 },
    { 6, 1, 2, 3, 0, 1, 0 },
    { 6, 2, 2, 2, 2, 2, 1 },
};

#endif /* !INCANTATION_H_ */
