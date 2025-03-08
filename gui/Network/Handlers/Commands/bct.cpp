/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** bct
*/

#include "Handler.hpp"

std::size_t get_char_occurrence(std::string &str, char c)
{
    std::size_t count = 0;
    for (char i : str)
        if (i == c)
            count++;
    return count;
}

void gui::Handler::bctCommand(std::istringstream &iss, gui::Data &game)
{
    std::string tmp = iss.str();
    BctCommand bct;
    if (get_char_occurrence(tmp, ' ') != 9 || tmp.back() == ' ')
        return;
    iss >> bct.x >> bct.y;
    for (int i = 0; i < 7; i++)
        iss >> bct.resources[i];
    for (std::size_t i = 0; i < bct.resources.size(); ++i)
        game.getMap().getTiles()[bct.y][bct.x].getResources()[i].obj = bct.resources[i];
}
