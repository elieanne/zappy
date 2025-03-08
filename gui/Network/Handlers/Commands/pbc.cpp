/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pbc
*/

#include "Handler.hpp"

void gui::Handler::pbcCommand(std::istringstream &iss, __attribute__((unused)) gui::Data &game)
{
    PbcCommand pbc;
    iss >> pbc.number >> pbc.message;
    std::cout << "Message du joueur " << pbc.number << " : " << pbc.message << std::endl;
    game.getCharacterById(pbc.number).setBroadcasting(true);
}
