/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** IObjects
*/

#ifndef IOBJECTS_HPP_
#define IOBJECTS_HPP_
    #include "Window.hpp"
    #include <SFML/Graphics.hpp>
    /**
    * @brief Path to the sprite
    * @def PATH_SPRITE
    */
    constexpr char PATH_SPRITE[] = "./gui/Resources/spritesheet.png";

/**
* @brief Type of the object
* @enum class TypeObject
*/
enum class TypeObject {};

/**
* @brief IObjects class
* @class IObjects
*/
class IObjects {
    public:
        /**
        * @brief Destroy the IObjects object
        */
        virtual ~IObjects() noexcept = default;
        /**
        * @brief Display the object
        * @param window The window where the object will be displayed
        * @param sprite The sprite of the object
        * @param size The size of the object
        */
        virtual void display(sf::RenderWindow &window, sf::Sprite &sprite, float size) = 0;
        /**
        * @brief Get The type of the object
        * @return The type of the object
        */
        virtual const TypeObject &getType() = 0;
        /**
        * @brief Get The Sprite of the object
        * @return The Sprite of the object
        */
};

#endif /* !IOBJECTS_HPP_ */
