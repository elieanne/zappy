/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ItemDrawer
*/

#ifndef ITEMDRAWER_HPP_
#define ITEMDRAWER_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <functional>

namespace gui {
    /**
    * @brief ItemDrawer class
    * @class ItemDrawer
    */
    class ItemDrawer {
        public:
          /**
          * @brief Construct a new Item Drawer object
          */
          ItemDrawer() = default;
          /**
          * @brief Destroy the Item Drawer object
          */
          ~ItemDrawer() = default;
          /**
          * @brief Construct a new Item Drawer object by copy = deleted
          * @param other
          */
          ItemDrawer(const ItemDrawer& other) = delete;
          /**
          * @brief Construct a new Item Drawer object by move = default
          * @param other
          * @return ItemDrawer&
          */
          ItemDrawer(ItemDrawer&& other) = default;
          /**
          * @brief Assign a Item Drawer object by copy = deleted
          * @param other
          * @return ItemDrawer&
          */
          ItemDrawer& operator=(const ItemDrawer& other) = delete;
          /**
          * @brief Assign a Item Drawer object by move = default
          * @param other
          * @return ItemDrawer&
          */
          ItemDrawer& operator=(ItemDrawer&& other) = default;
          /**
          * @brief Set the Sprite
          * @param sprite
          */
          void setSprite(sf::Sprite sprite);
          /**
          * @brief draw the item
          * @param window
          * @param id
          * @param x
          * @param y
          * @param scale
          */
          void drawItem(sf::RenderWindow& window, int id, int x, int y, float scale);
          /**
          * @brief draw the level
          * @param window
          * @param id
          * @param x
          * @param y
          * @param scale
          */
          void drawLevel(sf::RenderWindow& window, int id, int x, int y, float scale);

        private:
          /**
          * @private @var std::vector<sf::IntRect> levelRect
          */
          std::vector<sf::IntRect> levelRect = {
            sf::IntRect(2215, 50, 170, 130), // Level 1
            sf::IntRect(2410, 50, 170, 130), // Level 2
            sf::IntRect(2610, 50, 170, 130), // Level 3
            sf::IntRect(2310, 190, 170, 130), // Level 4
            sf::IntRect(2520, 190, 170, 130), // Level 5
            sf::IntRect(2215, 320, 170, 130), // Level 6
            sf::IntRect(2410, 320, 170, 130), // Level 7
            sf::IntRect(2610, 320, 170, 130) // Level 8
          };
          /**
          * @private @var std::vector<sf::IntRect> itemRect
          */
          std::vector<sf::IntRect> itemRect = {
              sf::IntRect(800, 1560, 75, 95),
              sf::IntRect(795, 1665, 75, 80), // TypeStone::LINEMATE
              sf::IntRect(960, 1670, 80, 70), // TypeStone::DERAUMERE
              sf::IntRect(1190, 1670, 75, 80), // TypeStone::SIBUR
              sf::IntRect(1040, 1675, 75, 80), // TypeStone::MENDIANE
              sf::IntRect(1115, 1675, 65, 80), // TypeStone::PHIRAS
              sf::IntRect(885, 1660, 65, 80), // TypeStone::THYSTAME
              sf::IntRect(800, 1560, 75, 95),
              sf::IntRect(895, 1560, 75, 95),   // TypeFood::VANILLA_ICE_CREAM
              sf::IntRect(995, 1560, 75, 95),   // TypeFood::CHOCLATE_CAKE
              sf::IntRect(1095, 1560, 75, 95),   // TypeFood::STRAWBERRY_CAKE
              sf::IntRect(1200, 1560, 75, 95),  // TypeFood::CREAM_CAKE
              sf::IntRect(1300, 1560, 75, 95),   // TypeFood::DONUT
              sf::IntRect(1400, 1560, 75, 95),   // TypeFood::STRABERRY_PIE
              sf::IntRect(1500, 1560, 75, 95),   // TypeFood::CHOCOLATE_PIE
              sf::IntRect(1610, 1560, 75, 95),   // TypeFood::VANILLA_PIE
              sf::IntRect(1720, 1560, 75, 95),   // TypeFood::CUPCAKE
              sf::IntRect(1815, 1560, 75, 95),   // TypeFood::CROISSANT
              sf::IntRect(1920, 1560, 75, 95),   // TypeFood::MACARON
              sf::IntRect(2025, 1560, 75, 95),   // TypeFood::LOVE_CAKE
              sf::IntRect(2120, 1560, 85, 95),   // TypeFood::ROULER
              sf::IntRect(2230, 1560, 75, 95),   // TypeFood::PANCAKE
              sf::IntRect(2330, 1560, 75, 95),   // TypeFood::MUFFIN
              sf::IntRect(2432, 1560, 85, 95)    // TypeFood::COOKIE
          };
          /**
          * @private @var std::vector<sf::IntRect> meteorRect
          */
          std::vector<sf::IntRect> meteorRect = {
              sf::IntRect(2775, 1265, 345, 255), // Fire meteor
              sf::IntRect(3150, 1330, 360, 225), // Big meteor
              sf::IntRect(2710, 1575, 100, 95),  // Top left meteor
              sf::IntRect(2815, 1575, 115, 85),
              sf::IntRect(2950, 1570, 90, 110)
          };
          /**
          * @private @var sf::Sprite itemSprite
          */
          sf::Sprite itemSprite;
    };
}

#endif /* !ITEMDRAWER_HPP_ */
