/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneWin
*/

#include <iostream>
#include "SceneManager.hpp"
#include "Errors.hpp"

void SceneWin::loadScene(gui::SceneManager &manager, gui::Window &window, __attribute__((unused)) gui::Data &data)
{
    if (!(this->font.loadFromFile("./gui/Resources/RationalInteger.ttf")))
        throw Errors::ErrorFont("Error: can't load font");
    this->winText.setFont(this->font);
    this->winText.setFillColor(sf::Color::White);
    this->winText.setCharacterSize(90);
    if (data.getWinningTeam() == "NULL") {
        window.setBackground("./gui/Resources/loseBackground.png");
        manager.getSoundBox().play("lose");
        this->winText.setString("No one");
        this->winText.setPosition(sf::Vector2f(1270, 300));
        this->haswonText.setString("has won :(");
    } else {
        window.setBackground("./gui/Resources/winBackground.png");
        manager.getSoundBox().play("win");
        this->winText.setString("Team " + data.getWinningTeam());
        this->winText.setPosition(sf::Vector2f(1170, 300));
        this->haswonText.setString("has won !!");
    }
    this->haswonText.setFont(this->font);
    this->haswonText.setFillColor(sf::Color::White);
    this->haswonText.setCharacterSize(90);
    this->haswonText.setPosition(sf::Vector2f(1220, 380));
    this->camera = gui::Camera(1920, 1080);
    this->camera.setCenter(sf::Vector2f(1920 / 2, 1080 / 2));
    manager.getSoundBox().stop("bowserGenerator");
}

void SceneWin::display(gui::SceneManager &manager, gui::Window &window, __attribute__((unused)) gui::Data &data)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window.getWindow());
    window.setMousePos(window.getWindow().mapPixelToCoords(static_cast<sf::Vector2i>(pos), this->camera.getView()));
    window.getWindow().setView(this->camera.getView());
    window.getWindow().draw(window.getBackground());
    for (auto &button : manager.getButtons()) {
        if (button->getName() == "exit" || button->getName() == "main") {
            button->applyStateButton(manager.getSprite());
            button->displayButton(window, manager.getSprite());
        }
    }
    window.getWindow().draw(this->winText);
    window.getWindow().draw(this->haswonText);
    window.displayWindow();
    window.clearWindow();
}

void SceneWin::checkEvents(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
{
    for (auto &button : manager.getButtons()) {
        button->hoverHandler(window.getMousePos());
        button->applyStateButton(manager.getSprite());
        button->displayButton(window, manager.getSprite());
    }
    while (window.getWindow().pollEvent(window.getEvent())) {
        if (window.getEvent().type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            window.getWindow().close();
        if (window.getEvent().type == sf::Event::MouseButtonPressed) {
            for (auto &button : manager.getButtons()) {
                if (button->isButtonPressed(window.getMousePos()) && (button->getName() == "main" || button->getName() == "exit")) {
                    sf::Clock delayClock;
                    sf::Time delayTime = delayClock.getElapsedTime();
                    manager.getSoundBox().play("click");
                    button->setButtonState(BUTTON_CLICKED);
                    button->applyStateButton(manager.getSprite());
                    button->displayButton(window, manager.getSprite());
                    this->display(manager, window, data);
                    while (delayTime.asSeconds() < 0.2) {
                        delayTime = delayClock.getElapsedTime();
                        window.getWindow().pollEvent(window.getEvent());
                    }
                    delayClock.restart();
                    if (data.getWinningTeam() != "NULL")
                        manager.getSoundBox().stop("win");
                    else
                        manager.getSoundBox().play("lose");
                    if (button->getName() == "exit")
                        window.getWindow().close();
                    if (button->getName() == "main") {
                        manager.setState(std::make_unique<SceneMenu>());
                        data.setWinningTeam("");
                        manager.loadScene(manager, window, data);
                    }
                    return;
                }
            }
        }
    }
}
