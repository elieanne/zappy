/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Parallax
*/

#include "Parallax.hpp"
#include <iostream>
#include "Errors.hpp"

gui::Parallax::Parallax()
{
    std::unique_ptr<Background> sky = std::make_unique<Background>();
    if (!(sky->texture.loadFromFile("./gui/Resources/parallax/sky.png")))
        throw Errors::ErrorTexture("Error: could not load sky texture");
    sky->sprite.setTexture(sky->texture);
    sky->position = sf::Vector2f(0, 0);
    sky->sprite.setPosition(sky->position);
    sky->speed = 2;
    parallax.push_back(std::move(sky));

    std::unique_ptr<Background> planet = std::make_unique<Background>();
    if(!(planet->texture.loadFromFile("./gui/Resources/parallax/planet.png")))
        throw Errors::ErrorTexture("Error: could not load planet texture");
    planet->sprite.setTexture(planet->texture);
    planet->position = sf::Vector2f(0, 0);
    planet->sprite.setPosition(planet->position);
    planet->speed = 0.3;
    parallax.push_back(std::move(planet));

    std::unique_ptr<Background> foreground = std::make_unique<Background>();
    if (!(foreground->texture.loadFromFile("./gui/Resources/parallax/foreground.png")))
        throw Errors::ErrorTexture("Error: could not load foreground texture");
    foreground->sprite.setTexture(foreground->texture);
    foreground->position = sf::Vector2f(0, 0);
    foreground->sprite.setPosition(foreground->position);
    foreground->speed = 2.5;
    parallax.push_back(std::move(foreground));

    std::unique_ptr<Background> middle = std::make_unique<Background>();
    if (!(middle->texture.loadFromFile("./gui/Resources/parallax/middle.png")))
        throw Errors::ErrorTexture("Error: could not load middle texture");
    middle->sprite.setTexture(middle->texture);
    middle->position = sf::Vector2f(0, 0);
    middle->sprite.setPosition(middle->position);
    middle->speed = 3;
    parallax.push_back(std::move(middle));

    std::unique_ptr<Background> background = std::make_unique<Background>();
    if (!(background->texture.loadFromFile("./gui/Resources/parallax/background.png")))
        throw Errors::ErrorTexture("Error: could not load background texture");
    background->sprite.setTexture(background->texture);
    background->position = sf::Vector2f(0, 0);
    background->sprite.setPosition(background->position);
    background->speed = 3.5;
    parallax.push_back(std::move(background));

    std::unique_ptr<Background> ground = std::make_unique<Background>();
    if (!(ground->texture.loadFromFile("./gui/Resources/parallax/ground.png")))
        throw Errors::ErrorTexture("Error: could not load ground texture");
    ground->sprite.setTexture(ground->texture);
    ground->position = sf::Vector2f(0, 0);
    ground->sprite.setPosition(ground->position);
    ground->speed = 4;
    parallax.push_back(std::move(ground));
}

void gui::Parallax::display(gui::Window &window)
{
    for (auto &background : parallax) {
        background->sprite.setPosition(background->position);
        window.getWindow().draw(background->sprite);
    }
}

void gui::Parallax::move()
{
    sf::Time time = clock.getElapsedTime();
    float seconds = time.asSeconds();

    if (seconds > 0.01) {
        parallax[1]->sprite.setRotation(parallax[1]->sprite.getRotation() + parallax[1]->speed);
        for (auto &background : parallax) {
            if (background->speed != 0.3)
                background->position.x -= background->speed;
        }
        clock.restart();
    }
}

void gui::Parallax::load()
{
    for (auto &background : parallax)
        background->sprite.setPosition(background->position);
}

void gui::Parallax::reset()
{
    for (auto &background : parallax) {
        if (background->position.x <= -1920)
            background->position.x = 0;
    }
}
