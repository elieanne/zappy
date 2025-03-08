/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Team
*/

#include "Team.hpp"

const std::string &gui::Team::getName() const
{
    return this->name;
}

void gui::Team::addCharacter(const int &id)
{
    characters.emplace_back(id);
}
