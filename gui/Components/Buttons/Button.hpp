/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Window.hpp"

enum ButtonState {
    BUTTON_IDLE = 0,
    BUTTON_HOVER,
    BUTTON_CLICKED,
    BUTTON_LOCKED
};

namespace gui {
    class Window;
}

namespace gui {
    /**
    * @brief Button class
    * @class Button
    */
    class Button {
        public:
            /**
            * @brief Construct a new Button object
            * @param name
            * @param rectButton
            * @param position
            * @throw Errors::ErrorTexture
            */
            Button(const std::string &name, sf::IntRect rectButton, sf::Vector2f position);
            /**
            * @brief Construct a new Button object by copy
            * @param other
            */
            Button(const Button &other) = delete;
            /**
            * @brief Assign a button object by copy
            * @param other
            * @return Button&
            */
            Button &operator=(const Button &other) = delete;
            /**
            * @brief Construct a new Button object by move
            * @param other
            */
            Button(Button &&other) = default;
            /**
            * @brief Assign a button object by move
            * @param other
            * @return Button&
            */
            Button &operator=(Button &&other) = default;
            /**
            * @brief Destroy the Button object
            */
            ~Button() = default;
            /*
            ** @brief Display the button in the window
            ** @param window The window to display the button
            */
            void displayButton(Window &window, sf::Sprite &sprite);
            /*
            ** @brief Get the name of the button
            ** @return std::string
            */
            [[nodiscard]] const std::string &getName();
            /*
            ** @brief Get the state of the button
            ** @return ButtonState
            */
            [[nodiscard]] const ButtonState &getButtonState();
            /*
            ** @brief Set the state of the button
            ** @param state The state of the button
            */
            void setButtonState(ButtonState state);
            /*
            ** @brief check if the button is pressed
            ** @param mousePos The position of the mouse
            ** @return bool
            */
            bool isButtonPressed(sf::Vector2f mousePos);
            /*
            ** @brief check if the button is hovered
            ** @param mousePos The position of the mouse
            */
            void hoverHandler(sf::Vector2f mousePos);
            /*
            ** @brief Apply the state of the button
            */
            void applyStateButton(sf::Sprite &sprite);
            /*
            ** @brief Get a button position
            ** @return sf::Vector2f The position of the button
            */
            sf::Vector2f &getPos();
            /**
            * @brief Set the Pos of the button object
            * @param pos
            */
            void setPos(sf::Vector2f pos);

          private:
            /**
            * @private @var sf::SoundBuffer bufferButton
            */
            sf::SoundBuffer bufferButton;
            /**
            * @private @var sf::Sound soundButton
            */
            sf::Sound soundButton;
            /**
            * @private @var sf::RectangleShape shapeButton
            */
            sf::RectangleShape shapeButton;
            /**
            * @private @var sf::IntRect rectButton
            */
            sf::IntRect rectButton;
            /**
            * @private @var sf::Vector2f shape
            */
            sf::Vector2f shape;
            /**
             * @private @var sf::Vector2f posButton
             */
            sf::Vector2f posButton;
            /**
            * @private @var ButtonState buttonState
            */
            ButtonState buttonState;
            /**
            * @private @var std::string nameButton
            */
            std::string nameButton;
    };
}

#endif /* !BUTTON_HPP_ */
