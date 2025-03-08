/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** plv
*/

#include "Handler.hpp"

void gui::Handler::plvCommand(std::istringstream &iss, gui::Data &game)
{
    PlvCommand plv;
    iss >> plv.number >> plv.level;
    std::cout << "plv " << plv.number << " " << plv.level << std::endl;
    game.getCharacterById(plv.number).setLevel(plv.level);
}
