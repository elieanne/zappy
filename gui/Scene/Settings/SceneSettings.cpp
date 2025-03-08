/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneSettings
*/

#include <iostream>
#include "SceneManager.hpp"

void SceneSettings::loadScene(__attribute__((unused)) gui::SceneManager &manager, gui::Window &window,  __attribute__((unused)) gui::Data &data)
{
    this->camera = gui::Camera(1920, 1080);
    this->camera.setCenter(sf::Vector2f(1920 / 2, 1080 / 2));
    window.setBackground("./gui/Resources/settingsBackground.png");
}

void SceneSettings::display(gui::SceneManager &manager, gui::Window &window, __attribute__((unused)) gui::Data &data)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window.getWindow());
    window.setMousePos(window.getWindow().mapPixelToCoords(static_cast<sf::Vector2i>(pos), this->camera.getView()));
    window.getWindow().setView(this->camera.getView());
    window.getWindow().draw(window.getBackground());
    window.getWindow().draw(manager.getVolSprite());
    for (auto &button : manager.getButtons()) {
        if (button->getName() == "volume" || button->getName() == "return" || button->getName() == "skins" || button->getName() == "confirm" || button->getName() == "midSize"
        || button->getName() == "highSize" || button->getName() == "highFps" || button->getName() == "midFps" || button->getName() == "lowFps") {
            button->applyStateButton(manager.getSprite());
            button->displayButton(window, manager.getSprite());
        }
    }
    window.displayWindow();
    window.clearWindow();
}

void SceneSettings::checkEvents(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
{
    for (auto &button : manager.getButtons()) {
        button->hoverHandler(window.getMousePos());
        button->applyStateButton(manager.getSprite());
    }
    while (window.getWindow().pollEvent(window.getEvent())) {
        if (this->volumeChanged == true) {
            manager.getButton("volume").setPos(sf::Vector2f(window.getMousePos().x, manager.getButton("volume").getPos().y));
            if (manager.getButton("volume").getPos().x >= 900)
                manager.getButton("volume").setPos(sf::Vector2f(900, manager.getButton("volume").getPos().y));
            else if (manager.getButton("volume").getPos().x <= 230)
                manager.getButton("volume").setPos(sf::Vector2f(230, manager.getButton("volume").getPos().y));
            manager.setVolume((manager.getButton("volume").getPos().x - 230.0) * 100.0 / 670.0);
        }
        if (window.getEvent().type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            window.getWindow().close();
        if (window.getEvent().type == sf::Event::MouseButtonPressed) {
            for (auto &button : manager.getButtons()) {
                if (button->isButtonPressed(window.getMousePos())
                    && (button->getName() == "volume" || button->getName() == "return" ||
                    button->getName() == "skins" || button->getName() == "confirm" ||
                    button->getName() == "midSize" || button->getName() == "highSize" ||
                    button->getName() == "highFps" || button->getName() == "midFps" || button->getName() == "lowFps"))
                {
                    sf::Clock delayClock;
                    sf::Time delayTime = delayClock.getElapsedTime();
                    manager.getSoundBox().play("click");
                    button->setButtonState(BUTTON_CLICKED);
                    button->applyStateButton(manager.getSprite());
                    this->display(manager, window, data);
                    if (delayTime.asSeconds() < 0.2) {
                        delayTime = delayClock.getElapsedTime();
                        window.getWindow().pollEvent(window.getEvent());
                    }
                    delayClock.restart();
                    if (button->getName() == "volume" && this->volumeChanged == true)
                        this->volumeChanged = false;
                    else if (button->getName() == "volume" && this->volumeChanged == false)
                        this->volumeChanged = true;
                    if (button->getName() == "highSize") {
                        manager.getButton("midSize").setButtonState(BUTTON_IDLE);
                        window.getWindow().setSize(sf::Vector2u(1920, 1080));
                        button->setButtonState(BUTTON_LOCKED);
                    }
                    if (button->getName() == "midSize") {
                        manager.getButton("highSize").setButtonState(BUTTON_IDLE);
                        window.getWindow().setSize(sf::Vector2u(1280, 720));
                        button->setButtonState(BUTTON_LOCKED);
                    }
                    if (button->getName() == "exit")
                        window.getWindow().close();
                    if (button->getName() == "highFps") {
                        manager.getButton("midFps").setButtonState(BUTTON_IDLE);
                        manager.getButton("lowFps").setButtonState(BUTTON_IDLE);
                        window.getWindow().setFramerateLimit(220);
                        button->setButtonState(BUTTON_LOCKED);
                    }
                    if (button->getName() == "midFps") {
                        manager.getButton("highFps").setButtonState(BUTTON_IDLE);
                        manager.getButton("lowFps").setButtonState(BUTTON_IDLE);
                        window.getWindow().setFramerateLimit(120);
                        button->setButtonState(BUTTON_LOCKED);
                    }
                    if (button->getName() == "lowFps") {
                        manager.getButton("highFps").setButtonState(BUTTON_IDLE);
                        manager.getButton("midFps").setButtonState(BUTTON_IDLE);
                        window.getWindow().setFramerateLimit(60);
                        button->setButtonState(BUTTON_LOCKED);
                    }
                    if (button->getName() == "return") {
                        manager.setState(std::make_unique<SceneMenu>());
                        manager.loadScene(manager, window, data);
                    } else if (button->getName() == "skins") {
                        manager.setState(std::make_unique<SceneSkins>());
                        manager.loadScene(manager, window, data);
                    } else if (button->getName() == "confirm") {
                        manager.setState(std::make_unique<SceneMenu>());
                        manager.loadScene(manager, window, data);
                    }
                    return;
                }
            }
        }
    }
}
