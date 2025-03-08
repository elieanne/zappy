/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneGame
*/

#include "SceneManager.hpp"
#include <iostream>
#include "FactoryObjects.hpp"
#include "FactoryPlayers.hpp"
#include "Foods.hpp"
#include "Stones.hpp"
#include "PanelBar.hpp"
#include "Players.hpp"
#include "Eggs.hpp"
#include "Errors.hpp"

constexpr char PATH_GOLEM[] = "./gui/Resources/golem_spritesheet.png";
constexpr char PATH_PANEL[] = "./gui/Resources/inventory.png";

void SceneGame::loadScene(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
{
    this->createObject(data);
    manager.getSoundBox().stop("mainMenu");
    manager.getSoundBox().play("bowserGenerator");
    panelBars.push_back(gui::PanelBar(sf::Vector2f(data.getMap().getTiles()[0][0].getPosition().x - 480, 10)));
    panelBars.push_back(gui::PanelBar(sf::Vector2f(data.getMap().getTiles()[9][0].getPosition().x + 870, 10)));
    panelBars[0].getCamera().setView(window.getWindow());
    this->camera.setView(window.getWindow());
    window.setBackground("./gui/Resources/mapFrame.png");
    window.getBackground().setTextureRect(sf::IntRect(data.getMapFrame(), 0, 1920, 1080));
    window.setCursor(0.5);
    data.getMap().setTileSkin(data.getTilesRect());
}

void SceneGame::createObject(gui::Data &data)
{
    this->mapFrame = gui::Camera(1920, 1080);
    this->mapFrame.setZoom(0.7);
    this->mapFrame.setCenter(sf::Vector2f(960, 540));
    this->camera = gui::Camera(1920, 1080);
    this->camera.setZoom(0.7);
    this->camera.setCenter(sf::Vector2f(data.getMap().getTiles()[0][0].getPosition().x + (data.getMap().getTiles()[0].size() * TILE_SIZE) / 2, data.getMap().getTiles()[0][0].getPosition().y + (data.getMap().getTiles().size() * TILE_SIZE) / 2));
    if (!this->texturePanel.loadFromFile(std::string(PATH_PANEL)))
        throw Errors::ErrorTexture("Cannot load texture panel");
    this->spritePanel.setTexture(this->texturePanel);
    if (!this->texture.loadFromFile(std::string(PATH_SPRITE)))
        throw Errors::ErrorTexture("Cannot load texture");
    this->sprite.setTexture(this->texture);
    if (!this->textureCharacters.loadFromFile(std::string(PATH_GOLEM)))
        throw Errors::ErrorTexture("Cannot load texture");
    this->spriteCharacters.setTexture(this->textureCharacters);
    this->itemDrawer.setSprite(this->sprite);
}
