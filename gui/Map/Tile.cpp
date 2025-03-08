/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Tile
*/

#include "Tile.hpp"
#include <iostream>

namespace gui {
void Tile::drawContent(gui::ItemDrawer& itemDrawer, sf::RenderWindow& window)
{
    int i = 0;

    for (auto& resource : this->resources) {
        if (resource.obj > 0) {
            itemDrawer.drawItem(window, resource.spriteId, (resource.pos.x + this->pos.x) * TILE_SIZE,
                ((resource.pos.y + this->pos.y) * TILE_SIZE), 0.3);
        }
        i++;
    }
}

void Tile::setPosition(const sf::Vector2f& pos)
{
    this->pos = pos;
}

void Tile::setRect(const sf::IntRect& rect)
{
    this->rect = rect;
}

void Tile::setFRect(const sf::FloatRect& fRect)
{
    this->fRect = fRect;
}

void Tile::setShape(const sf::RectangleShape& shape)
{
    this->shape = shape;
}

void Tile::setResources(const std::vector<infos>& resources)
{
    this->resources = resources;
}

void Tile::setIsSelected(const bool& selected)
{
    this->isSelected = selected;
}

const sf::Vector2f& Tile::getPosition()
{
    return this->pos;
}

const sf::FloatRect& Tile::getFRect()
{
    return this->fRect;
}

sf::RectangleShape& Tile::getShape()
{
    return this->shape;
}

std::vector<infos>& Tile::getResources()
{
    return this->resources;
}

const bool& Tile::getIsSelected()
{
    return this->isSelected;
}
}
