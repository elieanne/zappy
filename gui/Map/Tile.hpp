/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Tile
*/

#ifndef TILE_HPP_
    #define TILE_HPP_
    #include "ItemDrawer.hpp"
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    constexpr float TILE_SIZE = 64;

/**
 * @brief Infos struct
 * @struct Infos
 */
struct infos {
    int obj;
    sf::Vector2f pos;
    int spriteId;
};

/**
 * @brief Tile class
 * @class Tile
 */

namespace gui {
class Tile {
    public:
        /**
         * @brief Construct a new Tile object
         */
        Tile() = default;
        /**
         * @brief Destroy the Tile object
         */
        ~Tile() = default;
        /**
         * @brief Construct a new Tile object by copy
         * @param other
         */
        Tile(const Tile& other) = delete;
        /**
         * @brief Construct a new Tile object by move
         * @param other
         */
        Tile(Tile&& other) = default;
        /**
         * @brief Assign a Tile object by copy
         * @param itemDrawer
         * @param window
         */
        Tile& operator=(const Tile& other) = delete;
        /**
         * @brief Assign a Tile object by move
         * @param itemDrawer
         * @param window
         */
        Tile& operator=(Tile&& other) = default;
        /**
         * @brief Set the Resources
         * @param itemDrawer
         * @param window
         */
        void drawContent(gui::ItemDrawer& itemDrawer, sf::RenderWindow& window);
        /**
         * @brief Set the Position
         * @param pos
         */
        void setPosition(const sf::Vector2f& pos);
        /**
        * @brief Set the Rect
        * @param rect
        */
        void setRect(const sf::IntRect& rect);
        /**
        * @brief Set the Float Rect
        * @param fRect
        */
        void setFRect(const sf::FloatRect& fRect);
        /**
        * @brief Set the Shape
        * @param shape
        */
        void setShape(const sf::RectangleShape& shape);
        /**
        * @brief Set the Resources
        * @param resources
        */
        void setResources(const std::vector<infos>& resources);
        /**
        * @brief Set boolean if tiles is selected
        * @param isSelected
        */
        void setIsSelected(const bool& isSelected);
        /**
        * @brief Get the Position
        * @return const sf::Vector2f&
        */
        [[nodiscard]] const sf::Vector2f& getPosition();
        /**
         * @brief Get the Float Rect
         * @return const sf::FloatRect&
         */
        [[nodiscard]] const sf::FloatRect& getFRect();
        /**
        * @brief Get the Shape
        * @return sf::RectangleShape&
        */
        [[nodiscard]] sf::RectangleShape& getShape();
        /**
        * @brief Get the Resources
        * @return std::vector<infos>&
        */
        [[nodiscard]] std::vector<infos>& getResources();
        /**
        * @brief Get the boolean selected
        * @return true
        * @return false
        */
        [[nodiscard]] const bool& getIsSelected();
    private:
        /**
         * @private @var sf::Vector2f pos
         */
        sf::Vector2f pos;
        /**
         * @private @var sf::IntRect rect
         */
        sf::IntRect rect;
        /**
         * @private @var sf::FloatRect fRect
         */
        sf::FloatRect fRect;
        /**
         * @private @var sf::RectangleShape shape
         */
        sf::RectangleShape shape;
        /**
         * @private @var std::vector<infos> resources
         */
        std::vector<infos> resources;
        /**
         * @private @var bool isSelected
         */
        bool isSelected;
    };
}
#endif /* !TILE_HPP_ */
