/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Data
*/

#include "Data.hpp"
#include "Foods.hpp"
#include "Stones.hpp"
#include "PanelBar.hpp"
#include "Players.hpp"
#include "Eggs.hpp"
#include <cstdlib>
#include <ctime>
#include "Errors.hpp"

bool gui::Data::isPlayer(int id)
{
    for (auto &player : this->characters) {
        if (player->getId() == id)
            return true;
    }
    return false;
}

bool gui::Data::isTeam(const std::string &path)
{
    for (auto &team : this->teams) {
        if (team.getName() == path)
            return true;
    }
    return false;
}

gui::Team &gui::Data::getTeamByName(const std::string &name)
{
    for (auto &team : this->teams) {
        if (team.getName() == name)
            return team;
    }
    throw Errors::ErrorTeam("Team not found");
}

const std::string &gui::Data::getTeamNameByPlayerId(int id)
{
    for (auto &character : this->characters) {
        if (character->getId() == id)
            return character->getTeamName();
    }
    throw Errors::ErrorTeam("Team not found");
}

gui::Map &gui::Data::getMap()
{
    return this->map;
}

std::vector<gui::Team> &gui::Data::getTeams()
{
    return this->teams;
}

std::vector<std::unique_ptr<ICharacters>> &gui::Data::getCharacters()
{
    return this->characters;
}

FactoryPlayers &gui::Data::getFactoryCharacters()
{
    return this->factoryCharacters;
}

ICharacters &gui::Data::getCharacterById(int id)
{
    for (auto &character : this->characters) {
        if (character->getId() == id) {
            return *character;
        }
    }
    throw Errors::ErrorCharacter("Character not found");
}

void gui::Data::setFrequency(int frequency)
{
    this->timeUnit = frequency;
}

const int &gui::Data::getFrequency()
{
    return this->timeUnit;
}

TextBox &gui::Data::getTextBox()
{
    return this->textBox;
}

const std::string &gui::Data::getWinningTeam()
{
    return this->winningTeam;
}

void gui::Data::setWinningTeam(const std::string &team)
{
    this->winningTeam = team;
}

void gui::Data::setMapFrame(int frame)
{
    this->mapFrame = frame;
}

const int &gui::Data::getMapFrame()
{
    return this->mapFrame;
}

void gui::Data::setTilesRect(int rect)
{
    this->tilesRect = rect;
}

const int &gui::Data::getTilesRect()
{
    return this->tilesRect;
}
