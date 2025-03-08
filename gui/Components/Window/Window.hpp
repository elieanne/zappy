/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.hpp"
#include "Camera.hpp"

namespace gui {
    class Button;
}

namespace gui {
    /**
     * @brief Window class
     * @class Window
     */
    class Window {
    public:
        /**
         * @brief Default constructor
         */
        Window() = default;
        /**
         * @brief Destroy the Window object
         */
        ~Window() noexcept = default;
        /**
         * @brief Construct a new Window object by copy = delete
         */
        Window(const Window &w) = delete;
        /**
         * @brief Construct a new Window object by move = delete
         * @param w
         */
        Window(Window &&w) = default;
        /**
         * @brief Overload equal operator by copy = delete
         * @param w
         * @return Window&
         */
        Window &operator=(const Window &w) = delete;
        /**
         * @brief Assign a Window object by move = default
         * @param w
         * @return Window&
         */
        Window &operator=(Window &&w) = default;
        /**
         * @brief Creates a window in SFML.
         * @param title The title of the window.
         * @param width The width of the window.
         * @param height The height of the window.
         * @param port The port of the server.
         * @param hostname The hostname of the server.
         * @throw Errors::ErrorTexture
         * @throw Errors::ErrorFont
         */
        void createWindow(const std::string &title, int width, int height, int port, const std::string &hostname);
        /**
         * @brief Set the clear color in SFML
         * @param color The color to set.
         */
        void setClearColor(sf::Color color);
        /**
         * @brief Clear the window in SFML
         */
        void clearWindow();
        /**
         * @brief Display the window in SFML
         */
        void displayWindow();
        /**
         * @brief Display the text in SFML
         */
        void displayHostPortText();
        /**
         * @brief Check if the window is open in SFML
         * @return True if the window is open, False otherwise.
         */
        bool isOpenWindow();
        /**
         * @brief Set the background in SFML
         * @param path The path of the background.
         * @throw Errors::ErrorTexture
         */
        void setBackground(const std::string &path);
        /**
         * @brief Get the background in SFML
         * @return sf::Sprite The background.
         */
        [[nodiscard]] sf::Sprite &getBackground();
        /**
         * @brief Get the mouse position in SFML
         * @return sf::Vector2f The mouse position.
         */
        [[nodiscard]] const sf::Vector2f &getMousePos() const;
        /**
         * @brief Get the event in SFML
         * @return sf::Event The event.
         */
        [[nodiscard]] sf::Event &getEvent();
        /**
         * @brief Set the mouse position in SFML
         * @return sf::Vector2f The mouse position.
         */
        void setMousePos(sf::Vector2f mousePos);
        /**
         * @brief Get the window in SFML
         * @return sf::RenderWindow The window.
         */
        [[nodiscard]] sf::RenderWindow &getWindow();
        /**
         * @brief Set the cursor in SFML
         * @param size The size of the cursor.
         */
        void setCursor(float size);
        /**
        * @brief Set the Cursor Pos
        * @param pos
        */
        void setCursorPos(sf::Vector2f pos);
    private:
        /**
         * @private @var sf::RenderWindow window
         */
        sf::RenderWindow window;
        /**
        * @private @var sf::Texture texture
        */
        sf::Texture texture;
        /**
        * @private @var sf::Sprite sprite
        */
        sf::Sprite sprite;
        /**
        * @private @var sf::Event event
        */
        sf::Event event;
        /**
        * @private @var sf::Vector2f mousePos
        */
        sf::Vector2f mousePos;
        /**
        * @private @var sf::Sprite cursorSprite
        */
        sf::Sprite cursorSprite;
        /**
        * @private @var sf::Texture cursorTexture
        */
        sf::Texture cursorTexture;
        /**
        * @private @var int port
        */
        int port;
        /**
        * @private @var std::string hostname
        */
        std::string hostname;
        /**
        * @private @var sf::Font font
        */
        sf::Font font;
        /**
        * @private @var sf::Text hostText
        */
        sf::Text hostText;
        /**
        * @private @var sf::Text portText
        */
        sf::Text portText;
        /**
         * @private The clear color in SFML
         */
        sf::Color clearColor;
    };
}

#endif /* !WINDOW_HPP_ */
