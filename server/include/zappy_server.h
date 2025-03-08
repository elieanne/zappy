/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myftp-elouan.savy-camaret
** File description:
** socket
*/

#ifndef SOCKET_H_
    #define SOCKET_H_
    #define _GNU_SOURCE
    #define SOCKET_INDEX 0
    #define SUCCESS 0
    #define ERROR 84
    #include <arpa/inet.h>
    #include <errno.h>
    #include <netinet/in.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/select.h>
    #include <sys/socket.h>
    #include <unistd.h>
    #include "utils.h"
    #include <time.h>
    #include "game.h"
    #include "map.h"

typedef struct user_s {
    char **buffer;
    int id;
    int fd;
    bool is_player;
} user_t;

typedef struct server_s {
    int socket_fd;
    user_t all_co[FD_SETSIZE];
    fd_set rfds;
    fd_set wfds;
    int fd_max;
    game_t game;
} server_t;

/**
 * @brief Create a new socket
 * @param port : The port number to listen to
 * @param ip : The ip address to listen to
 * @retval : The socket fd if success otherwise -1
 */
int create_socket(int port, char* ip);
/**
 * @brief Create a new server on the given port
 * @param server : The server data structure
 * @param port : The port number to listen to
 * @retval : 0 if success otherwise 84
 */
int create_server(server_t* server, char *port);
/**
 * @brief Handle the connection of a new client
 * @param server : The server data structure
 * @retval : 0 if success otherwise 84
 */
int handle_connection(server_t* server);
/**
 * @brief Handle the server loop
 * @param server : The server data structure
 * @param infos : The parsed info structure
 * @retval : 0 if success otherwise 84
 */
int server_loop(server_t* server, parsed_info_t *infos);
/**
 * @biref Check if a command has been sent by a client
 * @param server : The server data structure
 * @retval : 0 if success otherwise 84
 */
int check_command(server_t* server);
/**
 * @brief Split a string into an array of string
 * @param str : The string to split
 * @param separator : The separator to use
 * @return The array of string
 */
char** my_str_to_word_array(char const* str, char* separator);
/**
 * @brief Add a new client to the server
 * @param s : The server data structure
 * @param fd : The client fd
 * @param index : The index of the client in the server structure
 * @retval : 0 if success otherwise 84
 */
int add_client(server_t* s, int fd, int index);
/**
 * @brief Remove a client from the server
 * @param s : The server data structure
 * @param index : The index of the client in the server structure
 * @retval : 0 if success otherwise 84
 */
void remove_client(server_t* server, int index);
/**
 * @brief Exec a command sent by a client
 * @param server : The server data structure
 * @param player : The player who sent the command
 * @retval : 0 if success otherwise 84
 */
int exec_command(server_t* server, player_t *player);
/**
 * @brief Init the connection sequence for a new client
 * @param server : The server data structure
 * @param index : The index of the client in the server structure
 * @param team_index : The index of the team in the server structure
 */
void init_connection_sequence(server_t *server, int index, int team_index);
/**
 * @brief Handle the connection of a new AI client
 * @param server : The server data structure
 * @param index : The index of the client in the server structure
 * @param team_index : The index of the team in the server structure
 */
int handle_team_connection(const char *cmd, server_t *server, int index);
/**
 * @brief Handle the connection of a new GUI client
 * @param server : The server data structure
 * @param index : The index of the client in the server structure
 */
int handle_gui_connection(const char *cmd, server_t *server, int index);
/**
 * @brief Check if the connection sequence is sent to the server
 * @param server : The server data structure
 */
void check_connection_sequence(server_t *server);
/**
 * @brief Connect a gui to the server
 * @param server : The server data structure
 * @param index : The index of the client in the server structure
 * @retval : 0 if success otherwise 84
 */
int connect_gui(server_t *server, int index);
/**
 * @brief Exit the program and free all the allocated memory
 * @param server : The server data structure
 * @param infos : The parsed info structure
 * @return The exit status
 */
int exit_program(server_t *server, parsed_info_t *infos);
/**
 * @brief Check if the server is still running
 * @param server : The server data structure
 * @retval : true if the server is still running otherwise false
 */
bool can_continue(void);
/**
 * @biref Check if a signal has been sent to the program
 * @return The signal number if a signal has been sent otherwise 0
 */
int get_signal(void);
/**
 * @brief Check if a CTRL+D has been sent to the program
 */
void check_stdin(void);
/**
 * @brief Remove all the dead players
 * @param server : The server data structure
 */
void remove_dead_players(server_t *server);
/**
 * @brief Fill the fd list of the server
 * @param server : server data structure
 */
void fill_fd_list(server_t* server);
/**
 * @brief init the game structure
 * @param server : server data structure
 * @param infos : parsed info structure
**/
int init_game(server_t *server, parsed_info_t *parsed_info);
/**
 * @brief Free the game structure
 * @param server : server data structure
 * @param infos : parsed info structure
 * @retval : 0 if success otherwise 84
 */
int free_game_struct(server_t *server, parsed_info_t *infos);
/**
 * @brief Free the server structure
 * @param server : server data structure
 * @param infos : parsed info structure
 * @retval : 0 if success otherwise 84
 */
void free_server_base(server_t *server, parsed_info_t *infos);
/**
 * @brief Init the buffer command of a player
 * @param player : The player to init
 * @return The player with the buffer command initialized
 */
player_t *init_player_command(player_t *player);
/**
 * @brief Generate a new id for a player
 * @return The new id
 */
user_id_t *gen_new_id(void);
/**
 * @brief Send the existing players to a new client
 * @param s : The server data structure
 * @param player : The new player
 * @retval : 0 if success otherwise 84
 */
int send_existing_players(server_t* s, player_t* player);
/**
 * @brief Reset the game
 * @param server : The server data structure
 */
void reset_game(server_t *server);

#endif /* !SOCKET_H_ */
