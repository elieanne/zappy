/*
** EPITECH PROJECT, 2023
** teams
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_
    #include "stdbool.h"
    #include "game.h"

bool is_numeric(char* str);
int get_command_size(char** command_tab);
void free_command(char** command_tab);
bool check_uuid(int id, int ref);
int generate_uuid(void);

void free_player_list(player_t* players);
void free_map(game_t* game);
void free_id_list(user_id_t *id);
char** init_cmd_buffer(void);
int add_to_buffer(char **buffer, char* cmd);
char* rotate_buffer(char **buffer);
void free_game(game_t *game);

player_t *remove_node(player_t *list, player_t *prev, player_t *player);
void display_user(player_t *player);
void send_ok(int fd);
void send_ko(int fd);
player_t *find_player_by_uuid(player_t *player, int uuid);

user_id_t* find_id_by_uuid(user_id_t* id, int uuid);
user_id_t* remove_id_by_uuid(user_id_t* ids, int uuid);
user_id_t* add_id_back(user_id_t* id, user_id_t* new_id);
int get_len_player(user_id_t* list);

char *get_tile_content(tile_t* tile, player_t* player,
player_t* players_list, char *str);
tile_t* find_tile(game_t* game, int x, int y);
char *my_strcat(char *str, char *new_str);
int mod(int a, int b);

float get_len(coord_t pt1, coord_t pt2);
coord_t get_closest_dir(int dist[4]);
int get_right_split(float angle);
float convert_angle(float angle, player_t* tmp, coord_t tmp_pos);

#endif /* !UTILS_H_ */
