/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** sst
*/

#include "Handler.hpp"

void gui::Handler::sstCommand(std::istringstream &iss, __attribute__((unused)) gui::Data &game)
{
    SstCommand sst;
    iss >> sst.freq;
    game.setFrequency(sst.freq);
}
