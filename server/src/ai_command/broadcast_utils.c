/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** broadcast_utils
*/

#include "zappy_server.h"
#include <math.h>

float get_len(coord_t pt1, coord_t pt2)
{
    return sqrt(pow(pt2.x - pt1.x, 2) + pow(pt2.y - pt1.y, 2));
}

coord_t get_closest_dir(int dist[4])
{
    coord_t tmp_pos = { 0, 0 };
    int top_left = abs(dist[0]) + abs(dist[2]);
    int top_right = abs(dist[0]) + abs(dist[3]);
    int bot_left = abs(dist[1]) + abs(dist[2]);
    int bot_right = abs(dist[1]) + abs(dist[3]);

    if (top_left <= top_right && top_left <= bot_left && top_left <= bot_right)
        tmp_pos = (coord_t) {dist[2], dist[0]};
    if (top_right <= top_left && top_right
    <= bot_left && top_right <= bot_right)
        tmp_pos = (coord_t) {dist[3], dist[0]};
    if (bot_left <= top_left && bot_left <= top_right && bot_left <= bot_right)
        tmp_pos = (coord_t) {dist[2], dist[1]};
    if (bot_right <= top_left && bot_right
    <= top_right && bot_right <= bot_left)
        tmp_pos = (coord_t) {dist[3], dist[1]};

    return tmp_pos;
}

int get_right_split(float angle)
{
    if (angle >= 67.5 && angle < 112.5)
        return 3;
    if (angle >= 112.5 && angle < 157.5)
        return 4;
    if (angle >= 157.5 && angle < 202.5)
        return 5;
    if (angle >= 202.5 && angle < 247.5)
        return 6;
    if (angle >= 247.5 && angle < 292.5)
        return 7;
    if (angle >= 292.5 && angle < 337.5)
        return 8;
    if ((angle >= 337.5 && angle <= 360) || (angle >= 0 && angle < 22.5))
        return 1;
    if (angle >= 22.5 && angle < 67.5)
        return 2;
    return 0;
}

float convert_angle(float angle, player_t *tmp, coord_t tmp_pos)
{
    if (!tmp)
        return angle;
    if (tmp->orientation == RIGHT && tmp_pos.y < 0)
        angle = 360 - angle;
    if (tmp->orientation == LEFT && tmp_pos.y > 0)
        angle = 360 - angle;
    if (tmp->orientation == BOTTOM && tmp_pos.x > 0)
        angle = 360 - angle;
    if (tmp->orientation == TOP && tmp_pos.x < 0)
        angle = 360 - angle;
    return angle;
}
