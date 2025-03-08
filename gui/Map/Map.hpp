/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_
#include "ItemDrawer.hpp"
#include "Tile.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
    constexpr int RECT_GRASS = 64;
    constexpr char PATH_BACK[] = "./gui/Resources/tiles.png";

namespace gui {
    /**
    * @class Map
    * @brief Map Class
    */
    class Map {
        public:
          /**
          * @brief Construct a new Map object
          */
          Map() = default;
          /**
          * @brief Destroy the Map object
          */
          ~Map() = default;
          /**
          * @brief Construct a new Map object by copy
          * @param other
          */
          Map(const Map& other) = delete;
          /**
          * @brief Construct a new Map object
          * @param other
          */
          Map(Map&& other) = default;
          /**
          * @brief Assign a Map object by copy
          * @param other
          * @return Map&
          */
          Map& operator=(const Map& other) = delete;
          /**
          * @brief Assign a Map object by move
          * @param other
          * @return Map&
          */
          Map& operator=(Map&& other) = default;
          /**
          * @brief Init the map
          * @param width
          * @param height
          * @throw Errors::ErrorTexture
          */
          void initMap(unsigned int width, unsigned int height);
          /**
          * @brief Get the tiles
          * @return const std::vector<std::vector<Tile>> &
          */
          [[nodiscard]] std::vector<std::vector<Tile>>& getTiles();
          /**
          * @brief Display the map
          * @param window The window to display the map
          * @param itemDrawer The itemDrawer to display the map
          */
          void display(sf::RenderWindow& window, gui::ItemDrawer& itemDrawer);
          /**
          * @brief Set the Tile Skin
          * @param tileSkin
          */
          void setTileSkin(int tileSkin);

        private:
          /**
          * @private @var std::vector<std::vector<Tile>> tiles
          */
          std::vector<std::vector<Tile>> tiles;
          /**
          * @private @var sf::Texture texture
          */
          sf::Texture texture;
          /**
          * @private @var sf::Sprite backTile
          */
          sf::Sprite backTile;
          /**
          * @private @var unsigned int width
          */
          unsigned int width {0};
          /**
          * @private @var unsigned int height
          */
          unsigned int height {0};
    };
}

#endif /* !MAP_HPP_ */
