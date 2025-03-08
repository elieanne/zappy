/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** msz
*/

#include "Handler.hpp"

void gui::Handler::mszCommand(std::istringstream &iss, gui::Data &game)
{
    MszCommand msz;
    iss >> msz.x >> msz.y;
    if (game.getMap().getTiles().size() == 0)
        game.getMap().initMap(msz.x, msz.y);
}
