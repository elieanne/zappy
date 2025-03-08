/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Selected
*/

#include "SceneManager.hpp"
#include <iostream>

void SceneGame::previousSelected(std::vector<std::vector<gui::Tile>> &map)
{
    bool wasSelected = false;

    for (auto &row2 : map) {
        for (auto &tile2 : row2) {
            if (tile2.getIsSelected() == true && wasSelected == false) {
                wasSelected = true;
                continue;
            }
            if (wasSelected == true) {
                tile2.getShape().setOutlineColor(sf::Color::Transparent);
                tile2.setIsSelected(false);
            }
        }
    }
}

void SceneGame::selected(std::vector<std::vector<gui::Tile>> &map, sf::Vector2f pos)
{
    for (auto &row : map) {
        for (auto &tile : row) {
            if (tile.getIsSelected() == true) {
                tile.getShape().setOutlineColor(sf::Color::Transparent);
                tile.setIsSelected(false);
                this->panelBarVisible = false;
                continue;
            }
            if (tile.getFRect().contains(pos)) {
                tile.getShape().setOutlineColor(sf::Color::White);
                tile.setIsSelected(true);
                this->panelBarVisible = true;
                break;
            } else {
                tile.getShape().setOutlineColor(sf::Color::Transparent);
                tile.setIsSelected(false);
                this->panelBarVisible = false;
            }
        }
        if (this->panelBarVisible == true)
            break;
    }
    this->previousSelected(map);
}
