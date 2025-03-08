/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SoundBox
*/

#ifndef SOUNDBOX_HPP_
#define SOUNDBOX_HPP_
    #include <SFML/Audio.hpp>
    #include <unordered_map>
    #include <string>
    #include "SoundPlayers.hpp"

/**
* @brief Song struct
* @struct Song
*/
struct Song {
    std::string name;
    SoundPlayer soundPlayer;
};

/**
* @brief SoundBox class
* @class SoundBox
*/
class SoundBox {
    public:
        /**
        * @brief Construct a new SoundBox object
        */
        SoundBox() = default;
        /**
        * @brief Destroy the SoundBox object
        */
        ~SoundBox() noexcept = default;
        /**
        * @brief Construct a new SoundBox object by copy
        * @param other
        */
        SoundBox(const SoundBox& other) = delete;
        /**
        * @brief Assign a SoundBox object by copy
        * @param other
        * @return SoundBox&
        */
        SoundBox& operator=(const SoundBox& other) = delete;
        /**
        * @brief Construct a new SoundBox object by move
        * @param other
        */
        SoundBox(SoundBox&& other) = default;
        /**
        * @brief Assign a SoundBox object by move
        * @param other
        * @return SoundBox&
        */
        SoundBox& operator=(SoundBox&& other) = default;
        /**
        * @brief Init a song
        * @param songName
        * @param filePath
        */
        void initSong(const std::string& songName, const std::string& filePath, bool looping);
        /**
        * @brief Play a song
        * @param songName
        */
        void play(const std::string& songName);
        /**
        * @brief Stop a song
        * @param songName
        */
        void stop(const std::string& songName);
        /**
        * @brief Set the Volume object
        * @param songName
        * @param volume
        */
        void setVolume(float volume);
        /**
         * @brief Get the Volume object
         *
         * @return int
         */
        int getVolume();
        sf::SoundSource::Status getSoundStatus(const std::string &songName);
    private:
        float volume{30};
        std::vector<Song> sounds;
};

#endif /* !SOUNDBOX_HPP_ */
