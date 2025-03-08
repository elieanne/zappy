/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** user_id
*/

#include "game.h"
#include "utils.h"

user_id_t *add_id_back(user_id_t *id, user_id_t *new_id)
{
    user_id_t* tmp = NULL;

    if (id == NULL) {
        new_id->next = NULL;
        return new_id;
    }
    tmp = id;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_id;
    return id;
}

user_id_t *find_id_by_uuid(user_id_t *id, int uuid)
{
    user_id_t* tmp = id;
    if (!id)
        return NULL;
    while (tmp) {
        if (check_uuid(tmp->id, uuid) == true)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

user_id_t *remove_node_uuid(user_id_t *list, user_id_t *prev, user_id_t *id)
{
    user_id_t *tmp = NULL;
    if (prev == NULL) {
        if (!id->next)
            return NULL;
        tmp = id->next;
        return tmp;
    } else {
        prev->next = id->next;
        return list;
    }
}

user_id_t *remove_id_by_uuid(user_id_t *ids, int uuid)
{
    user_id_t* tmp = ids;
    user_id_t* prev = NULL;
    if (ids == NULL)
        return NULL;
    while (tmp != NULL) {
        if (check_uuid(tmp->id, uuid) == true)
            return remove_node_uuid(ids, prev, tmp);
        prev = tmp;
        tmp = tmp->next;
    }
    return ids;
}
