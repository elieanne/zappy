/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Event
*/

#include "SceneManager.hpp"

void SceneGame::buttonsHover(gui::SceneManager &manager, gui::Window &window)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window.getWindow());

    window.getWindow().setView(this->mapFrame.getView());
    window.setMousePos(window.getWindow().mapPixelToCoords(pos, this->mapFrame.getView()));
    window.setCursorPos(window.getWindow().mapPixelToCoords(pos, this->camera.getView()));
    for (auto &button : manager.getButtons()) {
        if ((button->getName() == "left" || button->getName() == "right") && this->showInventory) {
            button->hoverHandler(window.getMousePos());
            button->applyStateButton(manager.getSprite());
            button->displayButton(window, manager.getSprite());
        }
    }
}

void SceneGame::closeEvent(gui::Window &window, gui::Data &data)
{
    if (window.getEvent().type == sf::Event::Closed)
        window.getWindow().close();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !data.getTextBox().isInputMode())
        window.getWindow().close();
}

void SceneGame::checkName(const std::unique_ptr<gui::Button> &button, gui::Data &data)
{
    if (button->getName() == "left") {
        this->currentPlayerIndex--;
        if (this->currentPlayerIndex < 0)
            this->currentPlayerIndex = data.getCharacters().size() - 1;
    } else if (button->getName() == "right") {
        this->currentPlayerIndex++;
        if (this->currentPlayerIndex >= static_cast<int>(data.getCharacters().size()))
            this->currentPlayerIndex = 0;
    }
}

void SceneGame::buttonsPressed(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window.getWindow());

    window.getWindow().setView(this->mapFrame.getView());
    if (data.getTextBox().isPressed(window.getMousePos())) {
        if (data.getTextBox().isInputMode())
            data.getTextBox().activate(false);
        else
            data.getTextBox().activate(true);
    }
    window.setMousePos(window.getWindow().mapPixelToCoords(pos, this->mapFrame.getView()));
    window.setCursorPos(window.getWindow().mapPixelToCoords(pos, this->camera.getView()));
    for (auto &button : manager.getButtons()) {
        if (button->isButtonPressed(window.getMousePos()) && (button->getName() == "left" || button->getName() == "right")) {
            sf::Clock delayClock;
            sf::Time delayTime = delayClock.getElapsedTime();
            button->setButtonState(BUTTON_CLICKED);
            button->applyStateButton(manager.getSprite());
            button->displayButton(window, manager.getSprite());
            this->display(manager, window, data);
            while (delayTime.asSeconds() < 0.1) {
                delayTime = delayClock.getElapsedTime();
                window.getWindow().pollEvent(window.getEvent());
            }
            delayClock.restart();
            this->checkName(button, data);
            return;
        }
    }
}

void SceneGame::checkEvents(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
{
    this->buttonsHover(manager, window);
    while (window.getWindow().pollEvent(window.getEvent())) {
        this->closeEvent(window, data);
        this->mapMove(window, data);
        if (window.getEvent().type == sf::Event::MouseButtonPressed && window.getEvent().mouseButton.button == sf::Mouse::Left) {
            manager.getSoundBox().play("tile");
            sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window.getWindow()));
            sf::Vector2f GameMousePos = window.getWindow().mapPixelToCoords(static_cast<sf::Vector2i>(mousePos), this->camera.getView());
            this->buttonsPressed(manager, window, data);
            this->selected(data.getMap().getTiles(), GameMousePos);
        }
        if (window.getEvent().type == sf::Event::KeyPressed && window.getEvent().key.code == sf::Keyboard::Z && this->camera.getView().getSize().x <= 4100 && this->camera.getView().getSize().x >= 755) {
            this->camera.setZoom(0.9);
            if (this->camera.getView().getSize().x > 4100)
                this->camera.getView().setSize(4100, 2300);
            if (this->camera.getView().getSize().x < 755)
                this->camera.getView().setSize(755, 420);
        }
        if (window.getEvent().type == sf::Event::KeyPressed && window.getEvent().key.code == sf::Keyboard::S && this->camera.getView().getSize().y <= 2300 && this->camera.getView().getSize().y >= 420) {
            this->camera.setZoom(1.1);
            if (this->camera.getView().getSize().y > 2300)
                this->camera.getView().setSize(4100, 2300);
            if (this->camera.getView().getSize().y < 420)
                this->camera.getView().setSize(755, 420);
        }
        if (data.getTextBox().textEvent(window.getEvent()) == 0)
            data.getTextBox().activate(false);
    }
    if (data.getWinningTeam() != "") {
        manager.setState(std::make_unique<SceneWin>());
        manager.loadScene(manager, window, data);
    }
}
