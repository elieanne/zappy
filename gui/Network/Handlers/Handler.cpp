/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Handler
*/

#include "Handler.hpp"

void gui::Handler::handle(const std::string &keyword, gui::Data &game, std::istringstream &iss)
{
    for (auto &command : this->commands) {
        if (command.keyword == keyword) {
            command.handler(iss, game);
            return;
        }
    }
}

std::istream &operator>>(std::istream &is, Orientation &orientation)
{
    std::string tmp;
    is >> tmp;

    if (tmp == "1") {
        orientation = Orientation::North;
    } else if (tmp == "2") {
        orientation = Orientation::East;
    } else if (tmp == "3") {
        orientation = Orientation::South;
    } else if (tmp == "4") {
        orientation = Orientation::West;
    }
    return is;
}
