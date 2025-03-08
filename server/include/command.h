/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myftp-elouan.savy-camaret
** File description:
** command
*/

#ifndef COMMAND_H_
    #define COMMAND_H_
    #include "zappy_server.h"
    #include "utils.h"
    #include "ai_command.h"
    #include "gui_command.h"

typedef struct commands_s {
    bool (*is_valid)(server_t *server, player_t *player, char **cmds);
    char* identifier;
    int (*exec)(server_t *server, player_t *player, char **cmds);
    enum player_type cmd_type;
    int cooldown;
} command_t;

const command_t commands[] = {
    { &is_valid_inv, "Inventory", &ai_inventory, PLAYER, 1 },
    { &is_valid_one_arg, "Forward", &forward, PLAYER, 7 },
    { &is_valid_one_arg, "Right", &rotate_right, PLAYER, 7 },
    { &is_valid_one_arg, "Left", &rotate_left, PLAYER , 7},
    { &is_valid_one_arg, "Look", &look, PLAYER, 7 },
    { &is_valid_take, "Take", &take_object, PLAYER, 7 },
    { &is_valid_take, "Set", &drop_object, PLAYER, 7 },
    { &is_valid_one_arg, "Connect_nbr", &connect_nbr, PLAYER, 0 },
    { &is_valid_fork, "Fork", &fork_cmd, PLAYER, 42 },
    { &is_valid_one_arg, "Eject", &eject, PLAYER, 7 },
    { &is_valid_broadcast, "Broadcast", &broadcast, PLAYER, 7 },
    { &is_valid_incantation, "Incantation", &finish_incantation, PLAYER, 300 },
    { &is_valid_one_arg, "msz", &gui_map_size, GUI, 0},
    { &is_valid_pin, "pin", &gui_player_pin, GUI, 0 },
    { &is_valid_one_arg, "mct", &gui_map_content, GUI, 0},
    { &is_valid_bct, "bct", &gui_tile_content, GUI, 0},
    { &is_valid_one_arg, "sgt", &gui_time_unit, GUI, 0},
    { &is_valid_one_arg, "tna", &gui_teams_name, GUI, 0},
    { &is_valid_ppo, "ppo", &gui_player_pos, GUI, 0},
    { &is_valid_lvl, "plv", &gui_player_lvl, GUI, 0},
    { &is_valid_sst, "sst", &gui_sst, GUI, 0},
    { NULL, NULL, NULL, DEAD, 0 }
};

#endif /* !COMMAND_H_ */
