/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ebo
*/

#include "Handler.hpp"
#include "Players.hpp"

void gui::Handler::eboCommand(std::istringstream &iss, gui::Data &game)
{
    EboCommand ebo;
    iss >> ebo.eggId;
    std::cout << "ebo " << ebo.eggId << std::endl;
    sf::Vector2f pos = game.getCharacterById(ebo.eggId).getPos();
    std::string teamName = game.getCharacterById(ebo.eggId).getTeamName();
    Orientation orientation = game.getCharacterById(ebo.eggId).getOrientation();
    bool broadcast = game.getCharacterById(ebo.eggId).isBroadcasting();
    game.getCharacterById(ebo.eggId).setAlive(false);
    game.getCharacters().push_back(game.getFactoryCharacters().createPlayers<Players>(pos, ebo.eggId, 1, teamName, orientation, game, broadcast));
    game.getTeamByName(teamName).addCharacter(ebo.eggId);
}
