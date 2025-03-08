/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** seg
*/

#include "Handler.hpp"

void gui::Handler::segCommand(std::istringstream &iss, __attribute__((unused)) gui::Data &game)
{
    std::string tmp;
    iss >> tmp;
    game.setWinningTeam(tmp);
}
