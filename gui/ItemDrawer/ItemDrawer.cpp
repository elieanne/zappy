/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ItemDrawer
*/

#include "ItemDrawer.hpp"

namespace gui {
void ItemDrawer::setSprite(sf::Sprite sprite)
{
    this->itemSprite = sprite;
}

void ItemDrawer::drawItem(
    sf::RenderWindow &window, int id, int x, int y, float scale)
{
    this->itemSprite.setTextureRect(this->itemRect[id]);
    this->itemSprite.setScale(scale, scale);
    this->itemSprite.setPosition(x, y);
    window.draw(this->itemSprite);
}

void ItemDrawer::drawLevel(
    sf::RenderWindow &window, int id, int x, int y, float scale)
{
    if (id < 0 || id > 7)
        return;
    this->itemSprite.setTextureRect(this->levelRect[id]);
    this->itemSprite.setScale(scale, scale);
    this->itemSprite.setPosition(x, y);
    window.draw(this->itemSprite);
}

}
