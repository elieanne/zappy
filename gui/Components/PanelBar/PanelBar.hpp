/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** PanelBar
*/

#ifndef PANELBAR_HPP_
#define PANELBAR_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Camera.hpp"
#include "Map.hpp"
#include "Window.hpp"
#include "Data.hpp"

namespace gui {
    /**
    * @brief PanelBar class
    * @class PanelBar
    */
    class PanelBar {
        public:
            /**
            * @brief Construct a new Panel Bar object
            * @param pos
            * @throw Errors::ErrorTexture
            */
            PanelBar(sf::Vector2f pos);
            /**
            * @brief Destroy the Panel Bar object
            */
            ~PanelBar() noexcept = default;
            /**
            * @brief Construct a new Panel Bar object by copy
            * @param panelBar
            */
            PanelBar(const PanelBar &panelBar) = delete;
            /**
            * @brief Assign a Panel Bar object by copy
            * @param panelBar
            * @return PanelBar&
            */
            PanelBar &operator=(const PanelBar &panelBar) = delete;
            /**
            * @brief Construct a new Panel Bar object by move
            * @param panelBar
            */
            PanelBar(PanelBar &&panelBar) = default;
            /**
            * @brief Assign a Panel Bar object by move
            * @param panelBar
            * @return PanelBar&
            */
            PanelBar &operator=(PanelBar &&panelBar) = default;
            /*
            * @brief Display the object
            * @param window The window where the object will be displayed
            */
            void display(sf::RenderWindow &window, sf::Sprite &sprite);
            /*
            * @brief Get The Sprite of the object
            * @return The Sprite of the object
            */
            gui::Camera &getCamera();
            /**
            * @brief Set the Ressources Text
            * @param resources
            */
            void setRessourcesText(std::vector<infos> &resources);
            /**
            * @brief Set the Inventory Text
            * @param character
            */
            void setInventoryText(ICharacters &character);
            /**
             * @brief Display the Ressources Text
             * @param window
             * @param drawer
             */
            void displayRessourcesText(gui::Window &window, gui::ItemDrawer &drawer);
            /**
            * @brief Display the Inventory Text
            * @param window
            * @param drawer
            * @param sprite
            */
            void displayInventoryText(gui::Window &window, gui::ItemDrawer &drawer, sf::Sprite &sprite);

        private:
            /**
            * @brief Create a Text object
            * @param str
            * @param pos
            * @return sf::Text
            */
            sf::Text createText(const std::string &str, const sf::Vector2f &pos);
            /**
            * @private @var std::vector<sf::Text> resourcesText
            */
            std::vector<sf::Text> resourcesText;
            /**
            * @private @var std::vector<sf::Text> resourcesInvText
            */
            std::vector<sf::Text> resourcesInvText;
            /**
            * @private @var int playerLevel
            */
            int playerLevel;
            /**
            * @private @var int facingRectColor
            */
            int facingRectColor;
            /**
            * @private @var sf::Font font
            */
            sf::Font font;
            /**
            * @private @var gui::Camera camera
            */
            gui::Camera camera{1920, 1080};
            /**
            * @private @var sf::Vector2f pos
            */
            sf::Vector2f pos;
    };
}

#endif /* !PANELBAR_HPP_ */
