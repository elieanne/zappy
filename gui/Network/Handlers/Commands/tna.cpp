/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** tna
*/

#include "Handler.hpp"

void gui::Handler::tnaCommand(std::istringstream &iss, gui::Data &game)
{
    TnaCommand tna;
    iss >> tna.teamName;
    if ((game.isTeam(tna.teamName)) == false)
        game.getTeams().emplace_back(tna.teamName);
}
