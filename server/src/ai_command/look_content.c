/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** look_content
*/

#include "zappy_server.h"

char *my_strcat(char *str, char *new_str)
{
    int i = 0;
    int j = 0;

    if (!new_str)
        return str;
    if (!str)
        return strdup(new_str);
    str = realloc(str, sizeof(char) * (strlen(str) + strlen(new_str) + 1));
    i = strlen(str);
    for (; new_str[j]; j++)
        str[i + j] = new_str[j];
    str[i + j] = '\0';
    return str;
}

char *get_tile_element(char * name, int nb, char *full_content)
{
    if (!name || nb < 1)
        return full_content;
    for (int i = 0; i < nb; i++)
        full_content = my_strcat(full_content, name);
    return full_content;
}

char *fill_tile_content(char *full_c, tile_t *tile)
{
    if (!tile)
        return NULL;
    full_c = get_tile_element("food ", tile->inventory.food, full_c);
    full_c = get_tile_element("linemate ", tile->inventory.linemate, full_c);
    full_c = get_tile_element("deraumere ", tile->inventory.deraumere, full_c);
    full_c = get_tile_element("sibur ", tile->inventory.sibur, full_c);
    full_c = get_tile_element("mendiane ", tile->inventory.mendiane, full_c);
    full_c = get_tile_element("phiras ", tile->inventory.phiras, full_c);
    full_c = get_tile_element("thystame ", tile->inventory.thystame, full_c);
    return full_c;
}

char **fill_content(tile_t *tile, player_t *players_list)
{
    user_id_t* tmp = NULL;
    char *full_c = NULL;
    char **parsed_content = NULL;
    player_t *tmp_player = NULL;
    if (!tile || !players_list)
        return NULL;
    tmp = tile->id_list;
    for (; tmp != NULL; tmp = tmp->next) {
        tmp_player = find_player_by_uuid(players_list, tmp->id);
        if (tmp_player && tmp_player->type == PLAYER) {
            full_c = my_strcat(full_c, "player ");
        }
    }
    full_c = fill_tile_content(full_c, tile);
    if (!full_c)
        return NULL;
    parsed_content = my_str_to_word_array(full_c, " ");
    free(full_c);
    return parsed_content;
}

char *get_tile_content(tile_t *tile, player_t *player,
player_t *players_list, char *str)
{
    char **parsed_content = NULL;

    if (!tile || !player || !players_list || !player->tile)
        return NULL;
    parsed_content = fill_content(tile, players_list);
    if (!parsed_content)
        return str;
    if (tile != player->tile)
        str = my_strcat(str, " ");
    for (int i = 0; parsed_content[i]; i++) {
        str = my_strcat(str, parsed_content[i]);
        free(parsed_content[i]);
        if (parsed_content[i + 1]) {
            str = my_strcat(str, " ");
        }
    }
    free(parsed_content);
    return str;
}
