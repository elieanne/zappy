/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** gui_command.h
*/
#ifndef GUI_COMMAND_H_
    #define GUI_COMMAND_H_
    #include "zappy_server.h"

/**
 * @brief Return the player position
 * @param server : The server data structure
 * @param player : The player data structure
 * @param cmds : The command parsed
 * @return
 */
int gui_player_pos(server_t *server, player_t *player, char **cmds);
/**
 * @brief Send the bad parameter trigger to the GUI
 * @param fd : The fd of the GUI
 */
void gui_bad_parameter(int fd);
/**
 * @biref Send the unknown command to the trigger
 * @param fd : The ds of the GUI
 */
void gui_unknown_cmd(int fd);

/**
 * @brief Check if all the parameter are valid for the ppo command
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
bool is_valid_ppo(server_t *server, player_t *player, char **cmds);

/**
 * @brief Check if all the parameter are valid for the plv command
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
bool is_valid_lvl(server_t *server, player_t *player, char **cmds);

/**
 * @brief Check if all the parameter are valid for the pin command
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
bool is_valid_pin(server_t *server, player_t *player, char **cmds);

/**
 * @brief Check if all the parameter are valid for the command
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
bool is_valid_one_arg(server_t *server, player_t *player, char **cmds);

/**
 * @brief Check if all the parameter are valid for the command
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
bool is_valid_sst(server_t *server, player_t *player, char **cmds);

/**
 * @brief Allow the gui to receive map size
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
int gui_map_size(server_t *server, player_t *player, char **cmds);

/**
 * @brief Allow the gui to receive map content
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
int gui_map_content(server_t *server, player_t *player, char **cmds);

/**
 * @brief Allow the gui to receive tile content
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
int gui_tile_content(server_t *server, player_t *player, char **cmds);

/**
 * @brief Check if all the parameter are valid for the bct command
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
bool is_valid_bct(server_t *server, player_t *player, char **cmds);

/**
 * @brief Allow the gui to receive the server frequency
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
int gui_time_unit(server_t *server, player_t *player, char **cmds);

/**
 * @brief Allow the gui to receive the teams registered
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
int gui_teams_name(server_t *server, player_t *player, char **cmds);

/**
 * @brief Allow the gui to receive the inventory of a player
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
int gui_player_pin(server_t *server, player_t *player, char **cmds);

/**
 * @brief Allow the gui to receive the level of a player
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
int gui_player_lvl(server_t *server, player_t *player, char **cmds);

/**
 * @brief Allow the server to send messages to GUI
 * @param players : the player list
 * @param msg : the message
 */
void send_msg_to_gui(player_t *players, char *msg);

/**
 * @brief Allow the gui to receive the time_unit of the server
 * @param server : the server data structure
 * @param player : the player data structure
 * @param cmds : the parsed command
 * @return : true if the command is valid otherwise false
 */
int gui_sst(server_t *server, player_t *player, char **cmds);
#endif /*GUI_COMMAND_H_*/
