/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneManager
*/

#include "SceneManager.hpp"
#include <iostream>
#include "Errors.hpp"

gui::SceneManager::SceneManager()
{
    if (!(this->texture.loadFromFile("./gui/Resources/spritesheet.png")))
        throw Errors::ErrorTexture("Error: could not load spritesheet texture");
    this->sprite = sf::Sprite(this->texture);
    this->volSprite = sf::Sprite(this->texture);
    this->volSprite.setTextureRect(sf::IntRect(55, 1480, 730, 80));
    this->volSprite.setPosition(200, 170);
    this->mapFrameTexture.loadFromFile("./gui/Resources/mapFrame.png");
    this->mapFrameSprite = sf::Sprite(this->mapFrameTexture);
    this->mapFrameSprite.setPosition(310, 490);
    this->mapFrameSprite.setScale(0.2, 0.2);
    this->mapFrameSprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    if (!(this->tileTexture.loadFromFile("./gui/Resources/tiles.png")))
        throw Errors::ErrorTexture("Error: could not load tile texture");
    this->tileSprite = sf::Sprite(this->tileTexture);
    this->tileSprite.setPosition(1320, 520);
    this->tileSprite.setScale(2.5, 2.5);
    this->tileSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    this->createButtons();
    this->createSounds();
}

void gui::SceneManager::createButtons()
{
    this->buttons.push_back(std::make_unique<gui::Button>("main", sf::IntRect(55, 650, 345, 110), sf::Vector2f(1400, 690)));
    this->buttons.push_back(std::make_unique<gui::Button>("return", sf::IntRect(425, 1200, 345, 110), sf::Vector2f(500, 890)));
    this->buttons.push_back(std::make_unique<gui::Button>("confirm", sf::IntRect(55, 1200, 345, 110), sf::Vector2f(1400, 890)));
    this->buttons.push_back(std::make_unique<gui::Button>("connect", sf::IntRect(425, 790, 340, 110), sf::Vector2f(500, 800)));
    this->buttons.push_back(std::make_unique<gui::Button>("exit", sf::IntRect(425, 650, 345, 110), sf::Vector2f(1400, 890)));
    this->buttons.push_back(std::make_unique<gui::Button>("skins", sf::IntRect(55, 920, 345, 115), sf::Vector2f(1400, 600)));
    this->buttons.push_back(std::make_unique<gui::Button>("tiles", sf::IntRect(425, 925, 345, 110), sf::Vector2f(1400, 250)));
    this->buttons.push_back(std::make_unique<gui::Button>("mapframe", sf::IntRect(425, 1060, 345, 110), sf::Vector2f(500, 250)));
    this->buttons.push_back(std::make_unique<gui::Button>("midSize", sf::IntRect(55, 1335, 345, 110), sf::Vector2f(770, 400)));
    this->buttons.push_back(std::make_unique<gui::Button>("highSize", sf::IntRect(425, 1335, 345, 110), sf::Vector2f(230, 400)));
    this->buttons.push_back(std::make_unique<gui::Button>("highFps", sf::IntRect(830, 1245, 190, 110), sf::Vector2f(1250, 200)));
    this->buttons.push_back(std::make_unique<gui::Button>("midFps", sf::IntRect(1045, 1245, 190, 110), sf::Vector2f(1550, 200)));
    this->buttons.push_back(std::make_unique<gui::Button>("lowFps", sf::IntRect(830, 1370, 190, 110), sf::Vector2f(1400, 400)));
    this->buttons.push_back(std::make_unique<gui::Button>("settings", sf::IntRect(60, 785, 340, 110), sf::Vector2f(1400, 690)));
    this->buttons.push_back(std::make_unique<gui::Button>("left", sf::IntRect(1095, 1480, 65, 85), sf::Vector2f(-1360, 750)));
    this->buttons.push_back(std::make_unique<gui::Button>("right", sf::IntRect(1190, 1480, 65, 85), sf::Vector2f(-1490, 750)));
    this->buttons.push_back(std::make_unique<gui::Button>("volume", sf::IntRect(1275, 1265, 45, 70), sf::Vector2f(430, 200)));
}

void gui::SceneManager::createSounds()
{
    this->soundbox.initSong("mainMenu", "./gui/Resources/Musics/journey.ogg", true);
    this->soundbox.initSong("win", "./gui/Resources/Musics/skyStation.ogg", true);
    this->soundbox.initSong("bowserGenerator", "./gui/Resources/Musics/bowserGenerator.ogg", true);
    this->soundbox.initSong("lose", "./gui/Resources/Musics/rosalinaLullaby.ogg", true);
    this->soundbox.initSong("click", "./gui/Resources/Sounds/button.wav", false);
    this->soundbox.initSong("elevate", "./gui/Resources/Sounds/elevate.ogg", false);
    this->soundbox.initSong("death", "./gui/Resources/Sounds/death.wav", false);
    this->soundbox.initSong("tile", "./gui/Resources/Sounds/tile.ogg", false);
    this->soundbox.initSong("broadcast", "./gui/Resources/Sounds/broadcast.wav", false);
    this->soundbox.initSong("spawn", "./gui/Resources/Sounds/spawn.wav", false);
    this->soundbox.initSong("bowling", "./gui/Resources/Sounds/bowling.wav", false);
    this->soundbox.initSong("strike", "./gui/Resources/Sounds/strike.wav", false);
    this->soundbox.initSong("happybowler", "./gui/Resources/Sounds/happybowler.wav", false);
    this->soundbox.initSong("hihihou", "./gui/Resources/Sounds/hihihou.wav", false);
}

void gui::SceneManager::setState(std::unique_ptr<IScene> state)
{
    currentState = std::move(state);
}

void gui::SceneManager::loadScene(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
{
    if (currentState != nullptr)
        currentState->loadScene(manager, window, data);
}

void gui::SceneManager::display(gui::Window &window, gui::Data &data)
{
    if (currentState != nullptr)
        currentState->display(*this, window, data);
}

void gui::SceneManager::update(gui::Window &window, gui::Data &data)
{
    if (currentState != nullptr) {
        currentState->checkEvents(*this, window, data);
    }
}

std::vector<std::unique_ptr<gui::Button>> &gui::SceneManager::getButtons()
{
    return this->buttons;
}

gui::Button &gui::SceneManager::getButton(std::string name)
{
    for (auto &button : this->buttons) {
        if (button->getName() == name)
            return *button;
    }
    throw Errors::ErrorButton("Button not found");
}

sf::Sprite &gui::SceneManager::getSprite()
{
    return this->sprite;
}

sf::Sprite &gui::SceneManager::getVolSprite()
{
    return this->volSprite;
}

void gui::SceneManager::setMapFrameSprite(int rect)
{
    this->mapFrameSprite.setTextureRect(sf::IntRect(rect, 0, 1920, 1080));
}

sf::Sprite &gui::SceneManager::getMapFrameSprite()
{
    return this->mapFrameSprite;
}

void gui::SceneManager::setTileSprite(int rect)
{
    this->tileSprite.setTextureRect(sf::IntRect(rect, 0, 64, 64));
}

const sf::Sprite &gui::SceneManager::getTileSprite()
{
    return this->tileSprite;
}

int gui::SceneManager::getVolume()
{
    return this->soundbox.getVolume();
}

void gui::SceneManager::setVolume(float volume)
{
    this->soundbox.setVolume(volume);
}

SoundBox &gui::SceneManager::getSoundBox()
{
    return this->soundbox;
}
