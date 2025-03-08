/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pdr
*/

#include "Handler.hpp"

void gui::Handler::pdrCommand(std::istringstream &iss, __attribute__((unused)) gui::Data &game)
{
    PdrCommand pdr;
    iss >> pdr.number >> pdr.resource;
    //game->getCharacterById(pdr.number).setResources(pdr.resource, -1);
    //game.getMap().getTiles()[game.getCharacterById(pdr.number).getPos().y][game.getCharacterById(pdr.number).getPos().x].setResources(pdr.resource, 1);
}
