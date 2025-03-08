/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ai_command.h
*/
#ifndef AI_COMMAND_H_
    #define AI_COMMAND_H_
    #include "zappy_server.h"

/**
 * @brief Check if all the parameter are valid for the inventory command
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
bool is_valid_inv(server_t *server, player_t *player, char **cmds);

/**
 * @brief Check if all the parameter are valid for the take command
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
bool is_valid_take(server_t* server, player_t* player, char** cmds);
/**
 * @brief Check the elevation of the player is possible
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return true if the elevation is possible otherwise false
 */
bool is_valid_incantation(server_t* server, player_t* player, char** cmds);

/**
 * @brief Check if the command is well formatted for the fork
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return true if the elevation is possible otherwise false
 */
bool is_valid_fork(server_t *server, player_t *player, char **cmds);
/**
 * @brief Check if the command is well formatted for the broadcast
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return true if the elevation is possible otherwise false
 */
bool is_valid_broadcast(server_t *server, player_t *player, char **cmds);

/**
 * @brief Allow the user to check his inventory
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
int ai_inventory(server_t* server, player_t* player, char** cmds);

/****************************************************************
   * @brief  Allow the player to move forward
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   * @retval 0 or 84 in case of error
   ****************************************************************/
int forward(server_t *server, player_t *player, char** cmds);
/****************************************************************
   * @brief  Allow the player to move following offset
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  x_of : the x offset
   * @param  y_of : the y offset
   ****************************************************************/
void move_player(server_t* server, player_t* player, int x_of, int y_of);
/****************************************************************
 * @brief  Allow the player to rotate left
 * @param  server: the server data structure
 * @param  player: the player data structure
 * @param  cmds: the command
 * @retval 0 or 84 in case of error
 ****************************************************************/
int rotate_left(server_t *server, player_t *player, char** cmds);
/****************************************************************
   * @brief  Allow the player to rotate right
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   * @retval 0 or 84 in case of error
   ****************************************************************/
int rotate_right(server_t *server, player_t *player, char** cmds);
/****************************************************************
   * @brief  Allow the player to look in front of him
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   * @retval 0 or 84 in case of error
   ****************************************************************/
int look(server_t* server, player_t* player, char** cmds);
/****************************************************************
   * @brief  Allow the player to take an object
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   * @retval 0 or 84 in case of error
   ****************************************************************/
int take_object(server_t* server, player_t* player, char** cmds);
/****************************************************************
   * @brief  Allow the player to drop an object
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   * @retval 0 or 84 in case of error
   ****************************************************************/
int drop_object(server_t* server, player_t* player, char** cmds);
/****************************************************************
   * @brief  Tell the player the nb of free slots in his team
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   * @retval 0 or 84 in case of error
   ****************************************************************/
int connect_nbr(server_t* server, player_t* player, char** cmds);
/****************************************************************
   * @brief  Eject all the others players on the same tile of the player
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   ****************************************************************/
int eject(server_t* server, player_t* player, char** cmds);
/****************************************************************
   * @brief  Fork the player and create a new player in the same team
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   ****************************************************************/
int fork_cmd(server_t* server, player_t* player, char** cmds);
/****************************************************************
   * @brief  Finish the incantation of the player and level up
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   ****************************************************************/
int finish_incantation(server_t* server, player_t* player, char** cmds);
/****************************************************************
   * @brief  Broadcast a message to all the players on the map
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @param  cmds: the command
   ****************************************************************/
int broadcast(server_t* server, player_t* player, char** cmds);

// Utils subfunctions

/****************************************************************
   * @brief  Get the map info on the top relative to the array
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @retval 0 or 84 in case of error
   ****************************************************************/
char *look_top(server_t* server, player_t* player, char *str);
/****************************************************************
   * @brief  Get the map info on the right relative to the array
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @retval 0 or 84 in case of error
   ****************************************************************/
char *look_right(server_t* server, player_t* player, char *str);
/****************************************************************
   * @brief  Get the map info on the left relative to the array
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @retval 0 or 84 in case of error
   ****************************************************************/
char *look_left(server_t* server, player_t* player, char *str);
/****************************************************************
   * @brief  Get the map info on the bottom relative to the array
   * @param  server: the server data structure
   * @param  player: the player data structure
   * @retval 0 or 84 in case of error
   ****************************************************************/
char *look_bot(server_t* server, player_t* player, char *str);
int remove_resources(inventory_t* inventory, int level);
bool check_incantation(server_t* server, player_t* player);
void handle_egg(server_t* server, player_t* tmp_player);
char* get_eject_info(player_t* player);
int switch_direction(int dir);

#endif /*AI_COMMAND_H_*/
