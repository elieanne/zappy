/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** test.h
*/
#ifndef TEST_H_
    #define TEST_H_
    #include "zappy_server.h"
    #include <signal.h>

server_t *init_server_test(void);
void redirect_all_stdout(void);

int eject_players(int x_off, int y_off, server_t* server, player_t* player);
int exec_eject(server_t* server,
player_t** list_player, player_t* player, int dir[2]);

void handle_egg(server_t* server, player_t* tmp_player);
char* get_eject_info(player_t* player);
int switch_direction(int dir);

char* get_egg_infos(player_t* egg, player_t* player);
char* get_player_infos(player_t* player);

void get_side_distances(int dist[4], coord_t player_pos,
coord_t tmp_pos, game_t* game);
float get_front_len(player_t* tmp, coord_t tmp_pos);
int get_angle(game_t* game, player_t* player, player_t* tmp);

int take_deraumere(player_t *player, server_t *server);
int drop_deraumere(player_t *player, server_t *server);
int take_food(player_t *player, server_t *server);
int drop_food(player_t *player, server_t *server);
int take_linemate(player_t *player, server_t *server);
int drop_linemate(player_t *player, server_t *server);
int take_mendiane(player_t *player, server_t *server);
int drop_mendiane(player_t *player, server_t *server);
int take_sibur(player_t *player, server_t *server);
int drop_sibur(player_t *player, server_t *server);
int take_phiras(player_t *player, server_t *server);
int drop_phiras(player_t *player, server_t *server);
int take_thystame(player_t *player, server_t *server);
int drop_thystame(player_t *player, server_t *server);
int get_nb_deraumere(map_t *map);
int get_nb_food(map_t *map);
int get_nb_linemate(map_t *map);
int get_nb_mendiane(map_t *map);
int get_nb_sibur(map_t *map);
int get_nb_phiras(map_t *map);
int get_nb_thystame(map_t *map);
char *get_take_drop_info(player_t *player, int object_id, int action);
char *fill_tile_content(char *full_c, tile_t *tile);
char **fill_content(tile_t *tile, player_t *players_list);
int get_player_on_tile(game_t *game, tile_t *tile, int level);
int remove_resources(inventory_t *inventory, int level);
int connect_nbr(server_t *server, player_t *player, char** cmds);
int get_command_string(server_t* server, int index);
int check_gui_co(server_t *server, char **cmd, int index);
int check_ai_co(server_t *server, char **cmd, int index);
int is_cmd_valid(server_t *server, player_t *player);
int init_game_map(parsed_info_t *parse_info, game_t *game);
player_t *init_player_inventory(player_t *player);
int spawn_linemate(map_t *map, int size);
int spawn_food(map_t *map, int size);
int spawn_deraumere(map_t *map, int size);
int spawn_sibur(map_t *map, int size);
int spawn_mendiane(map_t *map, int size);
int spawn_phiras(map_t *map, int size);
int spawn_thystame(map_t *map, int size);
void send_death_message(player_t *player, server_t *server);
char *get_death_infos(player_t *player);
int send_seg_event(int size, int *teams, game_t *game);
int send_gui_information(server_t *server, player_t *player);
char *get_arg(char const *flag, char **argv);
int get_nb_teams(char **argv);
char** get_teams(char** argv);
bool need_help(char **argv);
void exec_all_cmd(server_t *serv);
int store_command(server_t *s);
void handle_signal(int sig, siginfo_t *si, void *unused);
void free_player(player_t *player);
user_id_t *remove_node_uuid(user_id_t *list, user_id_t *prev, user_id_t *id);
void send_msg_to_gui(player_t *players, char *msg);
int print_parsing_error(char* str);
#endif /*TEST_H_*/
