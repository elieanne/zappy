/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "parsing.h"

enum player_type {
    EGG,
    PLAYER,
    DEAD,
    GUI };

enum orientation {
    TOP = 1,
    RIGHT,
    BOTTOM,
    LEFT
};

typedef struct user_id_s {
    int id;
    struct user_id_s *next;
} user_id_t;

typedef struct inventory_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory_t;

typedef struct player_s {
    int fd;
    int id;
    bool was_egg;
    int client_index;
    int food_clock;
    char **command_buffer;
    struct tile_s* tile;
    inventory_t inventory;
    enum player_type type;
    int cooldown;
    char *current_cmd;
    bool elevating;
    unsigned short level;
    int team;
    struct player_s *next;
    enum orientation orientation;
} player_t;

typedef struct tile_s {
    inventory_t inventory;
    user_id_t *id_list;
    int x;
    int y;
} tile_t;

typedef struct map_s {
    int width;
    int height;
    tile_t **map;
} map_t;

typedef struct game_s {
    map_t map;
    bool is_win;
    player_t *players;
    int *team_slot;
    char **team_names;
    int teams_nb;
    int freq;
    int food_respawn;
    int max_client;
} game_t;

typedef struct coord_s {
    int x;
    int y;
} coord_t;

/**
 * @brief Init the game structure
 * @param game : the game data structure
 * @param parsed_info : the parsed info data structure
 * @retval 0 if the game structure is initialized otherwise 84
 */
int init_game_struct(game_t *game, parsed_info_t *parsed_info);
/**
 * @brief Init the player list
 * @param game : the game data structure
 * @retval none
 */
void init_player_list(game_t *game);
/**
 * @brief Init one player at a random position
 * @param team_id : the team id of the team
 * @param game : the game data structure
 * @return : the player chained list
 */
player_t* init_player(int team_id, game_t* game);
/**
 * @brief Init one player at a specific position
 * @param team_id : the team id of the team
 * @param game : the game data structure
 * @param x : the x position of the player
 * @param y : the y position of the player
 * @return : the player chained list
 */
player_t* init_player_pos(int team_id, game_t* game, int x, int y);
/**
 * @brief Init the map
 * @param parsed_info : the parsed info data structure
 * @param game : the game data structure
 * @retval 0 if the map is initialized otherwise 84
 */
int init_game_map(parsed_info_t *parsed_info, game_t *game);
/**
 * @brief Init the tile structure
 * @param tile : the tile data structure
 * @param x : the x position of the tile
 * @param y : the y position of the tile
 */
void init_tile(tile_t *tile, int x, int y);
/**
 * @brief Spawn all the ressources on the map
 * @param game : the game data structure
 * @retval 0 if the ressources are spawned otherwise 84
 */
int spawn_ressources(game_t* game);
/**
 * @brief Handle the time of a server tick to match the given frequency
 * @param start : the start time of the tick
 * @param end : the end time of the tick
 * @param game : the game data structure
 */
void wait_cycle(struct timespec start, struct timespec end, game_t *game);
/**
 * @brief Free and release the current executing command of the player
 * @param player : the player data structure
 */
void release_current_command(player_t *player);
/**
 * @brief Handle the cooldown of a command
 * @param player : the player data structure
 */
void handle_cooldown(player_t *players, int nb);
/**
 * @brief Add a player back in the player chained list
 * @param player : The player chained list
 * @param new_player : The new player to add
 * @return : The player chained list
 */
player_t *add_player_back(player_t *player, player_t *new_player);
/**
 * @brief Exit the command execution with a free and an error
 * @param tmp : The parsed command
 * @param player : The player data structure
 */
void exit_cmd(char **tmp, player_t *player);
/**
 * @brief Send the unknown command to the player according to the protocol
 * @param player : The player data structure
 */
void send_unknown(player_t *player);
/**
 * @brief Send the bad parameter command to the player according to the protocol
 * @param player
 */
void send_bad_parameter(player_t *player);
/**
 * @brief Format the team name to match the tna command
 * @param name : The name of the team
 * @return The formatted name
 */
char *format_team_name(char *name);
/**
 * @brief Format a string with the content of a tile to fill the bct command
 * @param tile : The tile data structure
 */
char *get_str_tile_content(tile_t tile);
/**
 * @brief Concat all tile string of the map to fill the mct command
 * @param game : The game data structure
 * @return The formatted string
 */
char *get_team_names(game_t *game);
/**
 * @brief Concat all tile string of the map
 * @param game : The game data structure
 * @return The formatted string
 */
char *format_tile_info(game_t *game);
/**
 * @brief Format the string to the sst command
 * @param game : The game data structure
 * @return The formatted string
 */
char *format_server_freq(game_t *game);
/**
 * @brief Adjust the food number of a player according to the frequency
 * @param player : The player data structure
 * @param nb : The number of food to remove
 */
void handle_death(player_t *player, int nb);
/**
 * @brief The and event to all GUI connected
 * @param players : The player chained list
 * @param cmd : The command string
 */
void send_gui_event(player_t *players, char *cmd);
/**
 * @brief Format the string for the pgt and pdr command
 * @param player : The player data structure
 * @param object_id : The id of the object
 * @param action : The action to perform
 * @return The formatted string
 */
char *get_take_drop_info(player_t *player, int object_id, int action);
/**
 * @brief Format the string for the start of an incantation
 * @param player : The player data structure
 * @return The formatted string
 */
char *get_start_inc_infos(player_t *player);
/**
 * @biref Add the id to the string
 * @param str : The string to add the id
 * @param id : The id to add
 * @return The formatted string
 */
char *add_player_id_to_str(char *str, int id);
/**
 * @brief Format the string to get connection info
 * @param player : The player data structure
 * @param game : The game data structure
 * @return The formatted string
 */
char *get_connection_info(player_t *player, game_t *game);
/**
 * @brief Format the string to get the end of an incantation
 * @param player : The player data structure
 * @return The formatted string
 */
char *get_end_inc_infos(player_t *player);
/**
 * @brief Format the string to fit the player position command
 * @param gui : The player data structure
 * @param player : The player data structure
 * @retval 0 if the player position is sent otherwise -1
 */
int gui_player_pos_event(player_t *gui, player_t *player);
/**
 * @brief Format the string to fit the player inventory command
 * @param player_list : The player chained list
 * @param player : The player data structure
 * @retval 0 if the player inventory is sent otherwise -1
 */
void gui_inv_event(player_t *player_list, player_t *player);
/**
 * @brief Send the player level to the all the GUI connected
 * @param player_list : The player chained list
 * @param player : The player data structure
 */
void gui_player_lvl_event(player_t* player_list, player_t* player);
/**
 * @brief Check the state of the game and update it
 * @param game : The game data structure
 * @retval 0 if the game is running otherwise 1
 */
int check_game_state(game_t* game);
/**
 * @brief Format the string to fit the broadcast command
 * @param player_list : The player chained list
 * @param player : The player data structure
 * @retval 0 if the player death is sent otherwise -1
 */
char *format_broadcast_info(int id, char *msg);
#endif /*GAME_H_*/
