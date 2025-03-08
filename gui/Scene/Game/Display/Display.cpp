/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Display
*/

#include "SceneManager.hpp"
#include <iostream>

void SceneGame::displayPanel(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
{
    manager.getButton("left").setPos(sf::Vector2f(1360, 750));
    manager.getButton("right").setPos(sf::Vector2f(1490, 750));
    for (auto &row: data.getMap().getTiles()) {
        for (auto &tile: row)
            this->displayInventory(data, tile);
    }
    if (this->panelBarVisible == true) {
        window.getWindow().setView(panelBars[0].getCamera().getView());
        this->displayTileContent(data.getMap().getTiles(), window, this->itemDrawer, data);
    }
    window.getWindow().setView(this->mapFrame.getView());
    if (showInventory) {
        window.getWindow().setView(panelBars[0].getCamera().getView());
        this->panelBars[1].display(window.getWindow(), this->spritePanel);
        this->panelBars[1].displayInventoryText(window, itemDrawer, this->spriteCharacters);
        window.getWindow().setView(this->mapFrame.getView());
        for (auto &button : manager.getButtons()) {
            if ((button->getName() == "left" || button->getName() == "right") && this->showInventory) {
                button->applyStateButton(manager.getSprite());
                button->displayButton(window, manager.getSprite());
            }
        }
    }
}

void SceneGame::displayCharacter(gui::Window &window, gui::Data &data, gui::SceneManager &manager)
{
    sf::Clock clock;
    sf::Time startTime = clock.getElapsedTime();

    auto &characters = data.getCharacters();
    for (auto it = characters.rbegin(); it != characters.rend(); ++it) {
        auto &character = *it;
        if (character->isBroadcasting() && startTime.asSeconds() < 1 && manager.getSoundBox().getSoundStatus("broadcast") == sf::SoundSource::Status::Stopped) {
            manager.getSoundBox().play("broadcast");
            startTime = clock.getElapsedTime();
        }
        character->animate(this->spriteCharacters);
        character->display(window.getWindow(), this->spriteCharacters, this->itemDrawer, data.getFrequency(), manager.getSoundBox());
    }
}

void SceneGame::removeCharacter(gui::SceneManager &manager, gui::Data &data)
{
    std::erase_if(data.getCharacters(), [this, &manager](const std::unique_ptr<ICharacters> &character) {
        if (character->getType() == CharacterType::Player && !character->isAlive() && character->getRectLeft() >= 1680) {
            this->showInventory = false;
            manager.getSoundBox().play("death");
            return true;
        } else if (character->getType() == CharacterType::Egg && !character->isAlive()) {
            return true;
        }
        return false;
    });
}

void SceneGame::display(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window.getWindow());

    window.setMousePos(window.getWindow().mapPixelToCoords(pos, this->camera.getView()));
    window.getWindow().setView(this->camera.getView());
    data.getMap().display(window.getWindow(), this->itemDrawer);
    this->displayCharacter(window, data, manager);
    window.getWindow().setView(this->mapFrame.getView());
    window.setMousePos(window.getWindow().mapPixelToCoords(pos, this->mapFrame.getView()));
    window.setCursorPos(window.getWindow().mapPixelToCoords(pos, this->camera.getView()));
    window.getWindow().draw(window.getBackground());
    this->displayPanel(manager, window, data);
    data.getTextBox().setString(std::to_string(data.getFrequency()));
    data.getTextBox().draw(window.getWindow(), this->sprite);
    window.getWindow().setView(this->camera.getView());
    window.displayWindow();
    window.clearWindow();
    this->removeCharacter(manager, data);
}
