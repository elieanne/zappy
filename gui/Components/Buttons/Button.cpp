/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Button
*/

#include "Button.hpp"
#include <exception>
#include <iostream>
#include "Errors.hpp"

gui::Button::Button(const std::string &name, sf::IntRect rectButtonParams, sf::Vector2f position)
{
    this->posButton = position;
    this->rectButton = rectButtonParams;
    this->shapeButton = sf::RectangleShape(sf::Vector2f(rectButton.width, rectButton.height));
    this->shapeButton.setPosition(position);
    this->shape = this->shapeButton.getSize();
    this->shapeButton.getPosition();
    this->shapeButton.setOrigin(this->shapeButton.getSize().x / 2, this->shapeButton.getSize().y / 2);
    this->shapeButton.setFillColor(sf::Color(255, 255, 255, 120));
    this->buttonState = BUTTON_IDLE;
    this->nameButton = name;
}

void gui::Button::displayButton(Window &window, sf::Sprite &sprite)
{
    sprite.setOrigin(this->rectButton.width / 2, this->rectButton.height / 2);
    sprite.setPosition(this->posButton);
    window.getWindow().draw(sprite);
}

const std::string &gui::Button::getName()
{
    return this->nameButton;
}

bool gui::Button::isButtonPressed(sf::Vector2f mousePos)
{
    sf::FloatRect rectButton = this->shapeButton.getGlobalBounds();

    if (rectButton.contains(mousePos.x, mousePos.y))
        return true;
    return false;
}

void gui::Button::hoverHandler(sf::Vector2f mousePos)
{
    sf::FloatRect rectButton = this->shapeButton.getGlobalBounds();

    if (this->buttonState == BUTTON_LOCKED)
        return;
    if (rectButton.contains(mousePos.x, mousePos.y))
        this->buttonState = BUTTON_HOVER;
    else
        this->buttonState = BUTTON_IDLE;
}

void gui::Button::setButtonState(ButtonState state)
{
    this->buttonState = state;
}

const ButtonState &gui::Button::getButtonState()
{
    return this->buttonState;
}

void gui::Button::applyStateButton(sf::Sprite &sprite)
{
    switch (this->buttonState) {
    case BUTTON_IDLE:
        sprite.setScale(1, 1);
        sprite.setTextureRect(sf::IntRect(this->rectButton.left, this->rectButton.top, this->rectButton.width, this->rectButton.height));
        break;
    case BUTTON_HOVER:
        sprite.setScale(1.1, 1.1);
        sprite.setTextureRect(sf::IntRect(this->rectButton.left, this->rectButton.top, this->rectButton.width, this->rectButton.height));
        break;
    case BUTTON_CLICKED:
        sprite.setScale(0.9, 0.9);
        sprite.setTextureRect(sf::IntRect(this->rectButton.left + 1322, this->rectButton.top, this->rectButton.width, this->rectButton.height));
        break;
    case BUTTON_LOCKED:
        sprite.setScale(1, 1);
        sprite.setTextureRect(sf::IntRect(this->rectButton.left + 1322, this->rectButton.top, this->rectButton.width, this->rectButton.height));
        break;
    }
}

void gui::Button::setPos(sf::Vector2f pos)
{
    this->posButton = pos;
    this->shapeButton.setPosition(pos);
}

sf::Vector2f &gui::Button::getPos()
{
    return this->posButton;
}
