/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** DisplayTile
*/

#include "SceneManager.hpp"
#include "Players.hpp"

void SceneGame::displayInventory(gui::Data &data, gui::Tile &tile)
{
    bool tileSelected = false;
    ICharacters *chosenPlayer = nullptr;

    for (auto &character : data.getCharacters()) {
        if (character->getType() == CharacterType::Player && character->getPos().x == tile.getPosition().x && character->getPos().y == tile.getPosition().y) {
            chosenPlayer = character.get();
            tileSelected = true;
            break;
        }
    }
    if (!tileSelected && currentPlayerIndex >= 0 && currentPlayerIndex < static_cast<int>(data.getCharacters().size()))
        chosenPlayer = data.getCharacters()[currentPlayerIndex].get();

    if (chosenPlayer != nullptr && chosenPlayer->getType() == CharacterType::Player) {
        this->panelBars[1].setInventoryText(*chosenPlayer);
        showInventory = true;
    }
}

void SceneGame::displaySelected(gui::Window &window, gui::Data &data, gui::ItemDrawer &itemDrawer, gui::Tile &tile)
{
    this->panelBars[0].display(window.getWindow(), this->spritePanel);
    this->panelBars[0].setRessourcesText(tile.getResources());
    this->panelBars[0].displayRessourcesText(window, itemDrawer);
    this->displayInventory(data, tile);
}

void SceneGame::displayTileContent(std::vector<std::vector<gui::Tile>> &map, gui::Window &window, gui::ItemDrawer &itemDrawer, gui::Data &data)
{
    for (auto &row : map) {
        for (auto &tile : row) {
            if (tile.getIsSelected() == true) {
                this->displaySelected(window, data, itemDrawer, tile);
                break;
            }
        }
    }
}
