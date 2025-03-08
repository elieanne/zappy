/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Window
*/

#include "Window.hpp"
#include <iostream>
#include "Errors.hpp"

void gui::Window::createWindow(const std::string &title, int width, int height, int portParams, const std::string &host)
{
    this->hostname = host;
    this->port = portParams;
    this->window.create(sf::VideoMode(width, height), title, sf::Style::Default);
    this->window.setFramerateLimit(60);
    if (!(this->texture.loadFromFile("./gui/Resources/mapFrame.png")))
        throw Errors::ErrorTexture("Error: cannot load texture" + std::string("./gui/Resources/mapFrame.png"));
    this->sprite.setTexture(this->texture);
    if (!(this->cursorTexture.loadFromFile("./gui/Resources/spritesheet.png")))
        throw Errors::ErrorTexture("Error: cannot load texture" + std::string("./gui/Resources/spritesheet.png"));
    this->cursorSprite.setTexture(cursorTexture);
    this->cursorSprite.setTextureRect(sf::IntRect(1230, 445, 60, 60));

    if (!(this->font.loadFromFile("./gui/Resources/RationalInteger.ttf")))
        throw Errors::ErrorFont("Error: cannot load font" + std::string("./gui/Resources/RationalInteger.ttf"));
    this->hostText.setString(this->hostname);
    this->hostText.setFont(this->font);
    this->hostText.setFillColor(sf::Color::White);
    this->hostText.setPosition(350, 270);
    this->portText.setString(std::to_string(this->port));
    this->portText.setFont(this->font);
    this->portText.setFillColor(sf::Color::White);
    this->portText.setPosition(350, 400);
    this->setClearColor(sf::Color(16, 16, 114));
}

void gui::Window::setClearColor(sf::Color clearColor)
{
    this->clearColor = clearColor;
}

void gui::Window::clearWindow()
{
    this->window.clear(this->clearColor);
}

void gui::Window::setBackground(const std::string &path)
{
    if (!(this->texture.loadFromFile(path)))
        throw Errors::ErrorTexture("Error: cannot load texture" + path);
    this->sprite.setTexture(this->texture);
}

sf::Sprite &gui::Window::getBackground()
{
    return this->sprite;
}

void gui::Window::displayWindow()
{
    this->window.draw(this->cursorSprite);
    this->window.display();
}

void gui::Window::displayHostPortText()
{
    this->window.draw(this->hostText);
    this->window.draw(this->portText);
}

bool gui::Window::isOpenWindow()
{
    return this->window.isOpen();
}

void gui::Window::setMousePos(sf::Vector2f mousePosParams)
{
    this->mousePos = mousePosParams;
    this->cursorSprite.setPosition(this->mousePos);
}

const sf::Vector2f &gui::Window::getMousePos() const
{
    return this->mousePos;
}

sf::Event &gui::Window::getEvent()
{
    return this->event;
}

sf::RenderWindow &gui::Window::getWindow()
{
    return this->window;
}

void gui::Window::setCursor(float size)
{
    this->cursorSprite.setScale(size, size);
}

void gui::Window::setCursorPos(sf::Vector2f pos)
{
    this->cursorSprite.setPosition(pos);
}
