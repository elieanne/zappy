/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SoundPlayers
*/

#ifndef SOUNDPLAYERS_HPP_
#define SOUNDPLAYERS_HPP_
    #include "SFML/Audio.hpp"

/**
* @brief SoundPlayer class
* @class SoundPlayer
*/
class SoundPlayer {
    public:
        /**
        * @brief Construct a new Sound Player object
        */
        SoundPlayer() = default;
        /**
        * @brief Destroy the Sound Player object
        */
        ~SoundPlayer() noexcept = default;
        /**
        * @brief Construct a new Sound Player object by copy
        * @param other
        */
        SoundPlayer(const SoundPlayer& other) = delete;
        /**
        * @brief Assign a Sound Player object by copy
        * @param other
        */
        SoundPlayer& operator=(const SoundPlayer& other) = delete;
        /**
        * @brief Construct a new Sound Player object by move
        * @param other
        */
        SoundPlayer(SoundPlayer&& other) = default;
        /**
        * @brief Assign a Sound Player object by move
        * @param other
        */
        SoundPlayer& operator=(SoundPlayer&& other) = default;
        /**
        * @brief Play the sound
        * @param filePath
        */
        void init(const std::string& filePath);
        void setBuffer(const sf::SoundBuffer& buffer);
        void setSound(const sf::Sound& sound);
        void setIsPlaying(bool isPlaying);
        const sf::SoundBuffer &getBuffer() const;
        sf::Sound &getSound();
        const bool& getIsPlaying() const;

      private:
        /**
        * @private @var sf::SoundBuffer buffer
        */
        sf::SoundBuffer buffer;
        /**
        * @private @var sf::Sound sound
        */
        sf::Sound sound;
        /**
        * @private @var bool isPlaying
        */
        bool isPlaying;
};

#endif /* !SOUNDPLAYERS_HPP_ */
