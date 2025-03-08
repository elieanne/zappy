/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pnw
*/

#include "Handler.hpp"
#include "Players.hpp"

void gui::Handler::pnwCommand(std::istringstream &iss, gui::Data &game)
{
    PnwCommand pnw;
    iss >> pnw.number >> pnw.x >> pnw.y >> pnw.orientation >> pnw.level >> pnw.teamName;
    std::cout << "pnw " << pnw.number << " " << pnw.x << " " << pnw.y << " " << pnw.level << " " << pnw.teamName << std::endl;
    if (game.isPlayer(pnw.number) == false) {
        game.getCharacters().push_back(game.getFactoryCharacters().createPlayers<Players>(sf::Vector2f(pnw.x, pnw.y), pnw.number, pnw.level, pnw.teamName, pnw.orientation, game, false));
        game.getTeamByName(pnw.teamName).addCharacter(pnw.number);
    }
}
