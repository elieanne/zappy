/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** smg
*/

#include "Handler.hpp"

void gui::Handler::smgCommand(std::istringstream &iss,__attribute__((unused)) gui::Data &game)
{
    SmgCommand smg;
    iss >> smg.message;
    std::cout << smg.message << std::endl;
}
