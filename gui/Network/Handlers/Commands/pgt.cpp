/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pgt
*/

#include "Handler.hpp"

void gui::Handler::pgtCommand(std::istringstream &iss, __attribute__((unused)) gui::Data &game)
{
    PgtCommand pgt;
    iss >> pgt.number >> pgt.resource;
    // std::cout << "Number charact = " << pgt.number << " " << pgt.resource << std::endl;
    //game->getCharacterById(pgt.number).setResources(pgt.resource, 1);
    //std::cout << "pos x = " << game->getCharacterById(pgt.number).getPos().x << " pos y = " << game->getCharacterById(pgt.number).getPos().y << std::endl;
    //game.getMap().getTiles()[game.getCharacterById(pgt.number).getPos().y][game.getCharacterById(pgt.number).getPos().x].setResources(pgt.resource, -1);
}
