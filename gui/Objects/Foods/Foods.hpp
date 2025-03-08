/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Foods
*/

#ifndef FOODS_HPP_
#define FOODS_HPP_
    #include "IObjects.hpp"
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>

/**
* @brief Foods class
* @class Foods
*/
class Foods : public IObjects {
    public:
    /**
     * @brief Destroy the Foods object
     */
        ~Foods() noexcept override = default;
        /**
        * @brief Construct a new Foods object by copy
        * @param stone
        */
        Foods(const Foods &stone) = default;
        /**
        * @brief Assign a Foods object by copy
        * @param stone
        * @return Foods&
        */
        Foods &operator=(const Foods &stone) = default;
        /**
        * @brief Construct a new Foods object by move
        * @param stone
        */
        Foods(Foods &&stone) = default;
        /**
        * @brief Assign a Foods object by move
        * @param stone
        * @return Foods&
        */
        Foods &operator=(Foods &&stone) = default;
        /**
        * @brief Display the object
        * @param window The window where the object will be displayed
        * @param sprite The sprite of the object
        * @param size The size of the object
        */
        void display(sf::RenderWindow &window, sf::Sprite &sprite, float size) override;
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
        * @private @var TypeObject type
        */
        TypeObject type;
        /**
        * @private @var sf::IntRect rect
        */
        sf::IntRect rect;
        /**
        * @private @var sf::Vector2f pos
        */
        sf::Vector2f pos;
};

#endif /* !FOODS_HPP_ */
