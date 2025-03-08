/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneSkins
*/

#include <iostream>
#include "SceneManager.hpp"

void SceneSkins::loadScene(__attribute__((unused)) gui::SceneManager &manager, gui::Window &window, __attribute__((unused)) gui::Data &data)
{
    this->camera = gui::Camera(1920, 1080);
    this->camera.setCenter(sf::Vector2f(1920 / 2, 1080 / 2));
    window.setBackground("./gui/Resources/settingsBackground.png");
}

void SceneSkins::display(gui::SceneManager &manager, gui::Window &window, __attribute__((unused)) gui::Data &data)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window.getWindow());
    window.setMousePos(window.getWindow().mapPixelToCoords(static_cast<sf::Vector2i>(pos), this->camera.getView()));
    window.getWindow().setView(this->camera.getView());
    window.getWindow().draw(window.getBackground());
    for (auto &button : manager.getButtons()) {
        if (button->getName() == "confirm" || button->getName() == "return" || button->getName() == "tiles"
            || button->getName() == "mapframe" || button->getName() == "left" || button->getName() == "right") {
            button->applyStateButton(manager.getSprite());
            button->displayButton(window, manager.getSprite());

        }
    }
    window.getWindow().draw(manager.getMapFrameSprite());
    window.getWindow().draw(manager.getTileSprite());
    window.displayWindow();
    window.clearWindow();
}

void SceneSkins::checkEvents(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
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
                if (button->isButtonPressed(window.getMousePos())) {
                    sf::Clock delayClock;
                    sf::Time delayTime = delayClock.getElapsedTime();
                    manager.getSoundBox().play("click");
                    if (delayTime.asSeconds() < 0.2) {
                        delayTime = delayClock.getElapsedTime();
                        window.getWindow().pollEvent(window.getEvent());
                    }
                    button->setButtonState(BUTTON_CLICKED);
                    button->applyStateButton(manager.getSprite());
                    this->display(manager, window, data);
                    delayClock.restart();
                    this->directionnalButtons(manager, *button, data, window);
                    if (button->getName() == "tiles")
                    {
                        manager.getButton("left").setPos(sf::Vector2f(1150, 600));
                        manager.getButton("right").setPos(sf::Vector2f(1650, 600));
                        manager.getButton("mapframe").setButtonState(BUTTON_IDLE);
                        button->setButtonState(BUTTON_LOCKED);
                    }
                    if (button->getName() == "mapframe")
                    {
                        manager.getButton("left").setPos(sf::Vector2f(200, 600));
                        manager.getButton("right").setPos(sf::Vector2f(800, 600));
                        manager.getButton("tiles").setButtonState(BUTTON_IDLE);
                        button->setButtonState(BUTTON_LOCKED);
                    }
                    if (button->getName() == "confirm") {
                        manager.getButton("left").setPos(sf::Vector2f(1360, 750));
                        manager.getButton("right").setPos(sf::Vector2f(1490, 750));
                        manager.setState(std::make_unique<SceneMenu>());
                        manager.loadScene(manager, window, data);
                    } else if (button->getName() == "return"){
                        manager.getButton("left").setPos(sf::Vector2f(1360, 750));
                        manager.getButton("right").setPos(sf::Vector2f(1490, 750));
                        manager.setState(std::make_unique<SceneSettings>());
                        manager.loadScene(manager, window, data);
                    }
                    return;
                }
            }
        }
    }
}

void SceneSkins::directionnalButtons(gui::SceneManager &manager, gui::Button &button, gui::Data &data, gui::Window &window)
{
    if (button.getName() == "left" && manager.getButton("tiles").getButtonState() == BUTTON_LOCKED) {
        data.setTilesRect(data.getTilesRect() - 64);
        if (data.getTilesRect() < 0)
            data.setTilesRect(128);
    }
    if (button.getName() == "right" && manager.getButton("tiles").getButtonState() == BUTTON_LOCKED) {
        data.setTilesRect(data.getTilesRect() + 64);
        if (data.getTilesRect() >= 192)
            data.setTilesRect(0);
    }
    if (button.getName() == "left" && manager.getButton("mapframe").getButtonState() == BUTTON_LOCKED) {
        data.setMapFrame(data.getMapFrame() - 1920);
        if (data.getMapFrame() < 0)
            data.setMapFrame(3840);
    }
    if (button.getName() == "right" && manager.getButton("mapframe").getButtonState() == BUTTON_LOCKED) {
        data.setMapFrame(data.getMapFrame() + 1920);
        if (data.getMapFrame() >= 5760)
            data.setMapFrame(0);
    }
    if (data.getMapFrame() == 0)
        window.setClearColor(sf::Color(16, 16, 114));
    if (data.getMapFrame() == 1920)
        window.setClearColor(sf::Color(250, 187, 123));
    if (data.getMapFrame() == 3840)
        window.setClearColor(sf::Color(13, 72, 110));
    manager.setTileSprite(data.getTilesRect());
    manager.setMapFrameSprite(data.getMapFrame());
}
