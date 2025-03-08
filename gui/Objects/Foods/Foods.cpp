/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Foods
*/

#include "Foods.hpp"
#include <vector>

static std::vector<sf::IntRect> rects = {
    sf::IntRect(800, 1560, 75, 95),    // TypeFood::CITRON_CAKE
    sf::IntRect(720, 1555, 75, 95),   // TypeFood::VANILLA_ICE_CREAM
    // sf::IntRect(64, 0, 32, 32),   // TypeFood::CHOCLATE_CAKE
    // sf::IntRect(96, 0, 32, 32),   // TypeFood::STRAWBERRY_CAKE
    // sf::IntRect(128, 0, 32, 32),  // TypeFood::CREAM_CAKE
    // sf::IntRect(160, 0, 32, 32),   // TypeFood::DONUT
    // sf::IntRect(192, 0, 32, 32),   // TypeFood::STRABERRY_PIE
    // sf::IntRect(224, 0, 32, 32),   // TypeFood::CHOCOLATE_PIE
    // sf::IntRect(256, 0, 32, 32),   // TypeFood::VANILLA_PIE
    // sf::IntRect(288, 0, 32, 32),   // TypeFood::CUPCAKE
    // sf::IntRect(320, 0, 32, 32),   // TypeFood::CROISSANT
    // sf::IntRect(352, 0, 32, 32),   // TypeFood::MACARON
    // sf::IntRect(384, 0, 32, 32),   // TypeFood::LOVE_CAKE
    // sf::IntRect(416, 0, 32, 32),   // TypeFood::ROULER
    // sf::IntRect(448, 0, 32, 32),   // TypeFood::PANCAKE
    // sf::IntRect(480, 0, 32, 32),   // TypeFood::MUFFIN
    // sf::IntRect(512, 0, 32, 32),   // TypeFood::COOKIE
};

sf::IntRect findRect()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    size_t randomIndex = std::rand() % rects.size();
    return rects[randomIndex];
}

void Foods::display(sf::RenderWindow &window, sf::Sprite &sprite, float size)
{
    sprite.setTextureRect(this->rect);
    sprite.setPosition(this->pos);
    sprite.setScale(size, size);
    window.draw(sprite);
}

const TypeObject &Foods::getType()
{
    return this->type;
}
