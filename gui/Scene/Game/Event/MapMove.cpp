/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** MapMove
*/

#include "SceneManager.hpp"

void SceneGame::mapMove(gui::Window &window, gui::Data &data)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->camera.getCenter().x < data.getMap().getTiles()[0].size() * TILE_SIZE - 320) {
        this->camera.setCenter(this->camera.getCenter() + sf::Vector2f(5, 0));
        this->camera.setView(window.getWindow());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->camera.getCenter().x > 315) {
        this->camera.setCenter(this->camera.getCenter() + sf::Vector2f(-5, 0));
        this->camera.setView(window.getWindow());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->camera.getCenter().y + 5 < data.getMap().getTiles().size() * TILE_SIZE - 320 + 5) {
        this->camera.setCenter(this->camera.getCenter() + sf::Vector2f(0, 5));
        this->camera.setView(window.getWindow());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->camera.getCenter().y > 315) {
        this->camera.setCenter(this->camera.getCenter() + sf::Vector2f(0, -5));
        this->camera.setView(window.getWindow());
    }
}
