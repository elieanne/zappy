/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pdi
*/

#include "Handler.hpp"
#include "Errors.hpp"

void gui::Handler::pdiCommand(std::istringstream &iss, gui::Data &game)
{
    PdiCommand pdi;
    iss >> pdi.number;
    try {
        game.getCharacterById(pdi.number).setAlive(false);
    } catch (Errors::ErrorCharacter &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
}
