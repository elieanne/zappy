/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ppo
*/

#include "Handler.hpp"

void gui::Handler::ppoCommand(std::istringstream &iss, gui::Data &game)
{
    PpoCommand ppo;
    iss >> ppo.number >> ppo.x >> ppo.y >> ppo.orientation;
    game.getCharacterById(ppo.number).setPos(sf::Vector2f(ppo.x, ppo.y ), ppo.orientation);
}
