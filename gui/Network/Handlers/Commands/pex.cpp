/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pex
*/

#include "Handler.hpp"

void gui::Handler::pexCommand(std::istringstream &iss, __attribute__((unused)) gui::Data &game)
{
    PexCommand pex;
    iss >> pex.number;
    std::cout << "Explusion du joueur " << pex.number << std::endl;
}
