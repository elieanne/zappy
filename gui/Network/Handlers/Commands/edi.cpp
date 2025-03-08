/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** edi
*/

#include "Handler.hpp"

void gui::Handler::ediCommand(std::istringstream &iss, gui::Data &game)
{
    EdiCommand edi;
    iss >> edi.eggId;
    std::cout << "edi " << edi.eggId << std::endl;
    game.getCharacterById(edi.eggId).setAlive(false);
}
