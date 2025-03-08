/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** sgt
*/

#include "Handler.hpp"

void gui::Handler::sgtCommand(std::istringstream &iss, __attribute__((unused)) gui::Data &game)
{
    SgtCommand sgt;
    iss >> sgt.freq;
    game.setFrequency(sgt.freq);
}
