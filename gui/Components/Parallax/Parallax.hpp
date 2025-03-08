/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Parallax
*/

#ifndef PARALLAX_HPP_
#define PARALLAX_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "Window.hpp"

/**
* @brief Background struct
* @struct Background
*/
struct Background {
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;
    float speed;
};

namespace gui {
    /**
    * @brief Parallax class
    * @class Parallax
    */
    class Parallax {
        public:
            /**
            * @brief Construct a new Parallax object
            * @throw Errors::ErrorTexture
            */
            Parallax();
            /**
            * @brief Construct a new Parallax object by copy
            * @param other
            */
            Parallax(const Parallax &other) = delete;
            /**
            * @brief Assign a Parallax object by copy
            * @param other
            * @return Parallax&
            */
            Parallax &operator=(const Parallax &other) = delete;
            /**
            * @brief Construct a new Parallax object by move
            * @param other
            */
            Parallax(Parallax &&other) = default;
            /**
            * @brief Assign a Parallax object by move
            * @param other
            * @return Parallax&
            */
            Parallax &operator=(Parallax &&other) = default;
            /**
            * @brief Destroy the Parallax object
            */
            ~Parallax() = default;
            /**
            * @brief Move each layer of the parallax by a certain speed
            */
            void move();
            /**
            * @brief Load the parallax by setting the position of each layer
            */
            void load();
            /**
            * @brief Display the parallax
            * @param window The window where the parallax will be displayed
            */
            void display(gui::Window &window);
            /**
            * @brief Reset the parallax to make it loop
            */
            void reset();
        private:
            /**
            * @private @var std::vector<std::unique_ptr<Background>> parallax
            */
            std::vector<std::unique_ptr<Background>> parallax;
            /**
            * @private @var sf::Clock clock
            */
            sf::Clock clock;
    };
}

#endif /* !PARALLAX_HPP_ */
