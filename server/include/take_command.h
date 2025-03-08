/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** take_command
*/

#ifndef TAKE_COMMAND_H_
    #define TAKE_COMMAND_H_

    #include "zappy_server.h"

/**
 * @brief Take one deraumere on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int take_deraumere(player_t* player, server_t *server);
/**
 * @brief Take one food on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int take_food(player_t* player, server_t *server);
/**
 * @brief Take one linemate on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int take_linemate(player_t* player, server_t *server);
/**
 * @brief Take one phiras on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int take_phiras(player_t* player, server_t *server);
/**
 * @brief Take one sibur on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int take_sibur(player_t* player, server_t *server);
/**
 * @brief Take one thystame on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int take_thystame(player_t* player, server_t *server);
/**
 * @brief Take one mendiane on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int take_mendiane(player_t* player, server_t *server);

/**
 * @brief Drop one deraumere on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int drop_deraumere(player_t* player, server_t *server);
/**
 * @brief Drop one food on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int drop_food(player_t* player, server_t *server);
/**
 * @brief Drop one linemate on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int drop_linemate(player_t* player, server_t *server);
/**
 * @brief Drop one phiras on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int drop_phiras(player_t* player, server_t *server);
/**
 * @brief Drop one sibur on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int drop_sibur(player_t* player, server_t *server);
/**
 * @brief Drop one thystame on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int drop_thystame(player_t* player, server_t *server);
/**
 * @brief Drop one mendiane on the tile
 * @param player : the player data structure
 * @param server : the server data structure
 * @retval 0 if the action is valid otherwise 84
 */
int drop_mendiane(player_t* player, server_t *server);


typedef struct take_commands_s {
    char* object;
    int (*take)(player_t *player, server_t *server);
    int (*drop)(player_t *player, server_t *server);
} take_commands_t;


const take_commands_t take_commands[] = {
    { "food", &take_food, &drop_food },
    { "linemate", &take_linemate, &drop_linemate },
    { "deraumere", &take_deraumere, &drop_deraumere },
    { "sibur", &take_sibur, &drop_sibur },
    { "mendiane", &take_mendiane, &drop_mendiane },
    { "phiras", &take_phiras, &drop_phiras },
    { "thystame", &take_thystame, &drop_thystame },
    { NULL, NULL, NULL }
};

#endif /* !TAKE_COMMAND_H_ */
