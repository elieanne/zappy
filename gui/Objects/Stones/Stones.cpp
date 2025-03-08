/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Stones
*/

#include "Stones.hpp"
#include <vector>

static std::vector<sf::IntRect> rects = {
    sf::IntRect(794, 1665, 75, 83), // TypeStone::LINEMATE
    sf::IntRect(958, 1670, 75, 85), // TypeStone::DERAUMERE
    sf::IntRect(1200, 1670, 65, 83), // TypeStone::SIBUR
    sf::IntRect(1050, 1675, 77, 70), // TypeStone::MENDIANE
    sf::IntRect(1128, 1675, 65, 75), // TypeStone::PHIRAS
    sf::IntRect(875, 1660, 80, 89) // TypeStone::THYSTAME
};

static sf::IntRect findRect(TypeStone type)
{
    return rects[static_cast<int>(type)];
}

void Stones::display(sf::RenderWindow &window, sf::Sprite &sprite, float size)
{
    sprite.setTextureRect(this->rect);
    sprite.setPosition(this->pos);
    sprite.setScale(size, size);
    window.draw(sprite);
}

const TypeObject &Stones::getType()
{
    return this->typeObject;
}

// sf::Sprite &Stones::getSprite()
// {
//     return this->sprite;
// }

Stones::Stones(TypeStone type, sf::Vector2f pos, TypeObject typeObject)
{
    // if (this->texture.loadFromFile(std::string(PATH_SPRITE)) == false)
    //     throw std::runtime_error("Cannot load texture");
    // this->sprite.setTexture(texture);
    // this->sprite.setTextureRect(findRect(type));
    // this->sprite.setPosition(pos);
    this->type = type;
    this->pos = pos;
    this->rect = findRect(this->type);
    this->typeObject = typeObject;
}
