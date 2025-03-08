/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pie
*/

#include "Handler.hpp"

void gui::Handler::pieCommand(std::istringstream &iss, __attribute__((unused)) gui::Data &game)
{
    PieCommand pie;
    iss >> pie.x >> pie.y >> pie.result;
    std::cout << "Incantation en " << pie.x << " " << pie.y << " : " << pie.result << std::endl;
}
