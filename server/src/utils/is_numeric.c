/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myftp-elouan.savy-camaret
** File description:
** is_numeric
*/

#include "zappy_server.h"

bool is_numeric(char *str)
{
    if (!str)
        return false;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}
