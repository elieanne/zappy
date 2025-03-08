/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** uuid
*/

#include <stdbool.h>
#include <string.h>
#include <uuid/uuid.h>
#include <stdlib.h>

bool check_uuid(const int id, int ref)
{
    return id == ref;
}

int generate_uuid(void)
{
    static int id = 0;
    return id++;
}
