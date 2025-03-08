/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** enw
*/

#include "Handler.hpp"
#include "Eggs.hpp"

void gui::Handler::enwCommand(std::istringstream &iss, gui::Data &game)
{
    EnwCommand enw;
    iss >> enw.eggId >> enw.number >> enw.x >> enw.y;
    std::cout << "enw " << enw.eggId << " " << enw.number << " " << enw.x << " " << enw.y << std::endl;
    Orientation orientation = game.getCharacterById(enw.number).getOrientation();
    game.getCharacters().push_back(game.getFactoryCharacters().createPlayers<Eggs>(sf::Vector2f(enw.x, enw.y), enw.eggId, game.getTeamNameByPlayerId(enw.number), game, orientation));
}
