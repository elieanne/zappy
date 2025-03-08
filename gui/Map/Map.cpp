/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Map
*/

#include "Map.hpp"
#include "Tile.hpp"
#include <iostream>
#include "Errors.hpp"

namespace gui {
void Map::initMap(unsigned int widthParam, unsigned int heightParam)
{
    this->width = widthParam;
    this->height = heightParam;
    if (!this->texture.loadFromFile(std::string(PATH_BACK)))
        throw Errors::ErrorTexture("Error: texture not found");
    this->backTile.setTexture(this->texture);
    this->backTile.setTextureRect(sf::IntRect(0, 0, RECT_GRASS, RECT_GRASS));
    this->backTile.setScale(1, 1);
    this->tiles = std::vector<std::vector<Tile>>();
    for (unsigned int i = 0; i < this->height; i++) {
        this->tiles.emplace_back();
        for (unsigned int j = 0; j < this->width; j++) {
            this->tiles[i].emplace_back();
            this->backTile.setScale(sf::Vector2f((static_cast<float>(RECT_GRASS)), (static_cast<float>(RECT_GRASS))));
            this->tiles[i][j].setPosition(sf::Vector2f(j, i));
            this->tiles[i][j].setRect(sf::IntRect(0, 0, RECT_GRASS, RECT_GRASS));
            this->tiles[i][j].setFRect(sf::FloatRect(this->tiles[i][j].getPosition() * TILE_SIZE, sf::Vector2f(TILE_SIZE, TILE_SIZE)));
            this->tiles[i][j].setShape(sf::RectangleShape(sf::Vector2f((TILE_SIZE - 1), (TILE_SIZE - 1))));
            this->tiles[i][j].getShape().setPosition(sf::Vector2f(this->tiles[i][j].getPosition().x * TILE_SIZE, this->tiles[i][j].getPosition().y * TILE_SIZE));
            this->tiles[i][j].getShape().setFillColor(sf::Color::Transparent);
            this->tiles[i][j].getShape().setOutlineColor(sf::Color::Transparent);
            this->tiles[i][j].getShape().setOutlineThickness(2);
            this->tiles[i][j].setIsSelected(false);
            this->tiles[i][j].setResources({
                { 0, sf::Vector2f((static_cast<float>((rand() % 60)) / 100), (static_cast<float>((rand() % 60)) / 100)), (rand() % 16) + 8},
                { 0, sf::Vector2f((static_cast<float>((rand() % 60)) / 100), (static_cast<float>((rand() % 60)) / 100)), 1},
                { 0, sf::Vector2f((static_cast<float>((rand() % 60)) / 100), (static_cast<float>((rand() % 60)) / 100)), 2},
                { 0, sf::Vector2f((static_cast<float>((rand() % 60)) / 100), (static_cast<float>((rand() % 60)) / 100)), 3},
                { 0, sf::Vector2f((static_cast<float>((rand() % 60)) / 100), (static_cast<float>((rand() % 60)) / 100)), 4},
                { 0, sf::Vector2f((static_cast<float>((rand() % 60)) / 100), (static_cast<float>((rand() % 60)) / 100)), 5},
                { 0, sf::Vector2f((static_cast<float>((rand() % 60)) / 100), (static_cast<float>((rand() % 60)) / 100)), 6}
            });
        }
    }
}

std::vector<std::vector<Tile>>& Map::getTiles()
{
    return this->tiles;
}

void Map::display(sf::RenderWindow& window, ItemDrawer& itemDrawer)
{
    for (auto &row: tiles) {
        for (auto &tile: row) {
            this->backTile.setPosition(sf::Vector2f(tile.getPosition().x * TILE_SIZE, tile.getPosition().y * TILE_SIZE));
            this->backTile.setScale(1, 1);
            window.draw(this->backTile);
            tile.drawContent(itemDrawer, window);
            // window.draw(tile.shape);
        }
    }
    for (auto& row : tiles) {
        for (auto& tile : row)
            window.draw(tile.getShape());
    }
}

void Map::setTileSkin(int tileSkin)
{
    this->backTile.setTextureRect(sf::IntRect(tileSkin, 0, RECT_GRASS, RECT_GRASS));
}
}
