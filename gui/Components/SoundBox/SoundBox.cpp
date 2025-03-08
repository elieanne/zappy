/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SoundBox
*/

#include "SoundBox.hpp"
#include <iostream>

void SoundBox::initSong(const std::string& songName, const std::string& filePath, bool looping)
{
    this->sounds.emplace_back(Song{songName, SoundPlayer{}});
    this->sounds.back().soundPlayer.init(filePath);
    this->sounds.back().soundPlayer.getSound().setLoop(looping);
}

void SoundBox::play(const std::string& songName)
{
    for (auto &a : this->sounds) {
        if (a.name == songName) {
            a.soundPlayer.getSound().setBuffer(a.soundPlayer.getBuffer());
            a.soundPlayer.getSound().play();
            return;
        }
    }
}

void SoundBox::stop(const std::string& songName)
{
    for (auto &a : this->sounds) {
        if (a.name == songName) {
            a.soundPlayer.getSound().stop();
            return;
        }
    }
}

void SoundBox::setVolume(float volume)
{
    this->volume = volume;
    for (auto &a : this->sounds) {
        a.soundPlayer.getSound().setVolume(this->volume);
    }
}

int SoundBox::getVolume()
{
    return this->volume;
}

sf::SoundSource::Status SoundBox::getSoundStatus(const std::string &songName)
{
    for (auto &a : this->sounds) {
        if (a.name == songName) {
            return a.soundPlayer.getSound().getStatus();
        }
    }
    return sf::SoundSource::Status::Stopped;
}