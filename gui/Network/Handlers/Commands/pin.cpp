/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pin
*/

#include "Handler.hpp"

void gui::Handler::pinCommand(std::istringstream &iss, gui::Data &game)
{
    PinCommand pin;
    iss >> pin.number >> pin.x >> pin.y;
    for (int i = 0; i < 7; i++)
        iss >> pin.resources[i];
    // std::cout << "pin " << pin.number << " " << pin.x << " " << pin.y << " " << pin.resources[0] << " " << pin.resources[1] << " " << pin.resources[2] << " " << pin.resources[3] << " " << pin.resources[4] << " " << pin.resources[5] << " " << pin.resources[6] << std::endl;
    game.getCharacterById(pin.number).setInventory(pin.resources);
}
