/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ICharacters
*/

#ifndef ICHARACTERS_HPP_
#define ICHARACTERS_HPP_
#include "myStruct.h"
#include "ItemDrawer.hpp"
#include "SoundBox.hpp"
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include <memory>

/**
* @brief Enum for the type of character
* @enum class CharacterType
*/
enum class CharacterType {
    Player,
    Egg };

/**
* @brief Interface for the characters
* @class ICharacters
*/
class ICharacters {
    public:
        /**
        * @brief Destroy of the ICharacters object
        */
        virtual ~ICharacters() noexcept = default;
        /**
        * @brief Get the Type object
        * @return CharacterType
        */
        virtual CharacterType getType() const = 0;
        /**
         * @brief Display the character
         * @param window
         * @param sprite
         * @param drawer
         * @param timeUnit
         * @param soundbox
         */
        virtual void display(sf::RenderWindow& window, sf::Sprite& sprite, gui::ItemDrawer &drawer, int timeUnit, SoundBox &soundBox) = 0;
        /**
        * @brief Animate the character
        * @param sprite
        */
        virtual void animate(sf::Sprite& sprite) = 0;
        /**
        * @brief Get the Id of the character
        * @return const int&
        */
        virtual const int& getId() = 0;
        /**
        * @brief Get the Rect Left of the character
        * @return const int&
        */
        virtual const int& getRectLeft() = 0;
        /**
        * @brief Set the Pos of the character
        * @param pos
        * @param orientation
        */
        virtual void setPos(sf::Vector2f pos, Orientation orientation) = 0;
        /**
        * @brief Set the Level of the character
        * @param level
        */
        virtual void setLevel(int level) = 0;
        /**
        * @brief Get the Level of the character
        * @return const int&
        */
        virtual const int& getLevel() = 0;
        /**
        * @brief Get the Color of the character
        * @return const std::string&
        */
        virtual const std::string& getColor() = 0;
        /**
        * @brief Get the Team Name of the character
        * @return const std::string&
        */
        virtual const std::string& getTeamName() = 0;
        /**
        * @brief Set the Inventory of the character
        * @param res
        */
        virtual void setInventory(const std::array<int, 7>& res) = 0;
        /**
        * @brief Get the Inventory of the character
        * @return std::array<int, 7>&
        */
        virtual const std::array<int, 7>& getInventory() = 0;
        /**
         * @brief Check if the character is alive
         * @return true
         * @return false
         */
        virtual const bool &isAlive() = 0;
        /**
         * @brief Set the Alive boolean of the character
         * @param alive
         */
        virtual void setAlive(bool alive) = 0;
        /**
        * @brief Set the Laying boolean of the character
        * @param laying
        */
        virtual void setLaying(bool laying) = 0;
        /**
        * @brief Check if the character is broadcasting
        * @return true
        * @return false
        */
        virtual const bool &isBroadcasting() = 0;
        /**
        * @brief Set the Broadcasting boolean of the character
        * @param broadcasting
        */
        virtual void setBroadcasting(bool broadcasting) = 0;
        /**
         * @brief Set the Elevating process of the character
         * @param elevating
         */
        virtual void setElevating(int elevating) = 0;
        /**
        * @brief Get the Pos of the character
        * @return sf::Vector2f
        */
        virtual const sf::Vector2f &getPos() = 0;
        /**
        * @brief Get the Orientation of the character
        * @return const Orientation&
        */
        virtual const Orientation& getOrientation() = 0;
};

#endif /* !ICHARACTERS_HPP_ */
