/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneMenu
*/

#include "SceneManager.hpp"
#include <iostream>
#include "Errors.hpp"

void SceneMenu::loadScene(__attribute__((unused)) gui::SceneManager &manager, gui::Window &window, __attribute__((unused)) gui::Data &data)
{
    this->camera = gui::Camera(1920, 1080);
    this->camera.setCenter(sf::Vector2f(1920 / 2, 1080 / 2));
    manager.getSoundBox().play("mainMenu");
    if (!(this->texture.loadFromFile("./gui/Resources/spritesheet.png")))
        throw Errors::ErrorTexture("Can't load texture");
    this->connexionSprite.setTexture(this->texture);
    this->connexionSprite.setTextureRect(sf::IntRect(805, 645, 525, 590));
    this->connexionSprite.setPosition(250, 100);
    if (!(this->textureLogo.loadFromFile("./gui/Resources/mainMenuLogo.png")))
        throw Errors::ErrorTexture("Can't load texture");
    this->logo.setTexture(this->textureLogo);
    this->logo.setTextureRect(sf::IntRect(310, 390, 665, 600));
    this->logo.setPosition(1050, 20);
    window.getWindow().setMouseCursorVisible(false);
}

void SceneMenu::display(gui::SceneManager &manager, gui::Window &window, __attribute__((unused)) gui::Data &data)
{
    manager.getSoundBox().setVolume(manager.getVolume());
    sf::Vector2i pos = sf::Mouse::getPosition(window.getWindow());
    window.setMousePos(window.getWindow().mapPixelToCoords(static_cast<sf::Vector2i>(pos), this->camera.getView()));
    window.getWindow().setView(this->camera.getView());
    this->parallax.move();
    this->parallax.load();
    this->parallax.display(window);
    for (auto &button : manager.getButtons()) {
        if (button->getName() == "connect" || button->getName() == "settings" || button->getName() == "exit") {
            button->applyStateButton(manager.getSprite());
            button->displayButton(window, manager.getSprite());
        }
    }
    this->parallax.reset();
    window.getWindow().draw(this->connexionSprite);
    window.getWindow().draw(this->logo);
    window.displayHostPortText();
    window.displayWindow();
    window.clearWindow();

}

void SceneMenu::checkEvents(gui::SceneManager &manager, gui::Window &window, gui::Data &data)
{
    for (auto &button : manager.getButtons()) {
        button->hoverHandler(window.getMousePos());
        button->applyStateButton(manager.getSprite());
        button->displayButton(window, manager.getSprite());
    }
    while (window.getWindow().pollEvent(window.getEvent()))
    {
        if (window.getEvent().type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            window.getWindow().close();
        if (window.getEvent().type == sf::Event::MouseButtonPressed)
        {
            if (this->logo.getGlobalBounds().contains(window.getMousePos())) {
                int random = rand() % 4;
                if (random == 0)
                    manager.getSoundBox().play("bowling");
                else if (random == 1)
                    manager.getSoundBox().play("hihihou");
                else if (random == 2)
                    manager.getSoundBox().play("happybowler");
                else if (random == 3)
                    manager.getSoundBox().play("strike");
            }
            for (auto &button : manager.getButtons())
            {
                if (button->isButtonPressed(window.getMousePos()) && (button->getName() == "connect" || button->getName() == "settings" || button->getName() == "exit"))
                {
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
                    if (button->getName() == "exit")
                        window.getWindow().close();
                    if (button->getName() == "connect") {
                        manager.setState(std::make_unique<SceneGame>());
                        manager.loadScene(manager, window, data);
                    } else if (button->getName() == "settings") {
                        manager.setState(std::make_unique<SceneSettings>());
                        manager.loadScene(manager, window, data);
                    }
                    return;
                }
            }
        }
    }
}
