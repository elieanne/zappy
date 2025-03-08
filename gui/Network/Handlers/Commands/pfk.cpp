/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pfk
*/

#include "Handler.hpp"

void gui::Handler::pfkCommand(std::istringstream &iss, gui::Data &game)
{
    PfkCommand pfk;
    iss >> pfk.number;
    std::cout << "pfk " << pfk.number << std::endl;
    game.getCharacterById(pfk.number).setLaying(true);
}
