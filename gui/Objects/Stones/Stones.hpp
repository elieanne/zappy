/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Stones
*/

#ifndef STONES_HPP_
#define STONES_HPP_
    #include "IObjects.hpp"
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>

/**
* @brief Enum of the type of the stone
* @enum class TypeStone
*/
enum class TypeStone { MENDIANE,
    PHIRAS,
    THYSTAME
};

/**
* @brief Stones class
* @class Stones
*/
class Stones : public IObjects {
    public:
        /**
        * @brief Construct a new Stones object
        * @param type
        * @param pos
        * @param typeObject
        */
        Stones(TypeStone type, sf::Vector2f pos, TypeObject typeObject);
        /**
        * @brief Destroy the Stones object
        */
        ~Stones() noexcept override = default;
        /**
        * @brief Construct a new Stones object by copy
        * @param stone
        */
        Stones(const Stones &stone) = default;
        /**
        * @brief Assign a Stones object by copy
        * @param stone
        * @return Stones&
        */
        Stones &operator=(const Stones &stone) = default;
        /**
        * @brief Construct a new Stones object by move
        * @param stone
        */
        Stones(Stones &&stone) = default;
        /**
        * @brief Assign a Stones object by move
        * @param stone
        * @return Stones&
        */
        Stones &operator=(Stones &&stone) = default;
        /**
        * @brief Display the object
        * @param window The window where the object will be displayed
        */
        void display(sf::RenderWindow& window, sf::Sprite &sprite, float size) override;
        /**
        * @brief Get The type of the object
        * @return The type of the object
        */
        const TypeObject &getType() override;
        /**
        * @brief Get The Sprite of the object
        * @return The Sprite of the object
        */
    private:
        /**
        * @private @var TypeStone type
        */
        TypeStone type;
        /**
        * @private @var TypeObject typeObject
        */
        TypeObject typeObject;
        /**
        * @private @var sf::IntRect rect
        */
        sf::IntRect rect;
        /**
        * @private @var sf::Vector2f pos
        */
        sf::Vector2f pos;
};

#endif /* !STONES_HPP_ */
