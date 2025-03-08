/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** pic
*/

#include "Handler.hpp"

void gui::Handler::picCommand(std::istringstream &iss, __attribute__((unused)) gui::Data &game)
{
    PicCommand pic;
    std::string tmp;
    iss >> pic.x >> pic.y >> pic.level;
    while (iss >> tmp) {
        pic.numbers.push_back(std::stoi(tmp));
        game.getCharacterById(std::stoi(tmp)).setElevating(1);
    }
}
