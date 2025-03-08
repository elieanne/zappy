/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SoundPlayers
*/

#include "SoundPlayers.hpp"

void SoundPlayer::init(const std::string& filePath)
{
    if (!this->buffer.loadFromFile(filePath))
        throw std::runtime_error("Cannot load sound file");
    this->sound.setBuffer(buffer);
    this->sound.setVolume(30);
    this->isPlaying = false;
}

void SoundPlayer::setBuffer(const sf::SoundBuffer& buffer)
{
    this->buffer = buffer;
}

void SoundPlayer::setSound(const sf::Sound& sound)
{
    this->sound = sound;
}

void SoundPlayer::setIsPlaying(bool isPlaying)
{
    this->isPlaying = isPlaying;
}

const sf::SoundBuffer& SoundPlayer::getBuffer() const
{
    return this->buffer;
}

sf::Sound& SoundPlayer::getSound()
{
    return this->sound;
}

const bool& SoundPlayer::getIsPlaying() const
{
    return this->isPlaying;
}
