/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** TextBox
*/

#include "TextBox.hpp"
#include <iostream>

void TextBox::initTextBox(const sf::Font &font, unsigned int characterSize, sf::Vector2f size, sf::Vector2f pos)
{
    this->text = sf::Text("", font, characterSize);
    this->descriptionText = sf::Text("Time unit (1/f secs)", font, characterSize);
    this->box = sf::RectangleShape(size);
    this->box.setPosition(sf::Vector2f(pos.x, pos.y));
    this->box.setFillColor(sf::Color::Transparent);
    this->box.setOutlineThickness(2);
    this->text.setFillColor(sf::Color::White);
    this->descriptionText.setFillColor(sf::Color::White);
    this->text.setPosition(box.getPosition().x + 10, box.getPosition().y + 20);
    this->descriptionText.setPosition(box.getPosition().x, box.getPosition().y - 25);
    this->inputMode = false;
    this->finished = false;
    this->rect = sf::IntRect(842, 1492, 156, 62);
}

bool TextBox::isPressed(sf::Vector2f mousePos)
{
    sf::FloatRect rectButton = this->box.getGlobalBounds();

    if (rectButton.contains(mousePos.x, mousePos.y))
        return true;
    return false;
}

void TextBox::draw(sf::RenderWindow &window, sf::Sprite &sprite)
{
    this->box.setOutlineColor(sf::Color::Transparent);
    if (inputMode)
        this->box.setOutlineColor(sf::Color::White);
    this->box.setPosition(sf::Vector2f(408, 761));
    sprite.setPosition(sf::Vector2f(400, 750));
    sprite.setTextureRect(this->rect);
    window.draw(sprite);
    window.draw(this->box);
    window.draw(text);
    window.draw(this->descriptionText);
}

const sf::String &TextBox::getString()
{
    return inputText;
}

void TextBox::setString(const sf::String &str)
{
    if (!this->inputMode) {
        this->text.setString(str);
    }
}

void TextBox::activate(bool mode)
{
    this->inputMode = mode;
}

void TextBox::clear()
{
    this->finished = false;
    this->text.setString(this->inputText);
}

const bool &TextBox::isFinished()
{
    return this->finished;
}

const bool &TextBox::isInputMode()
{
    return this->inputMode;
}

int TextBox::textEvent(sf::Event event)
{
    if (!inputMode)
        return 1;
    if (event.type == sf::Event::TextEntered) {
        inputText = this->text.getString();
        if (event.text.unicode == '\b')
            inputText = inputText.substring(0, inputText.getSize() - 1);
        else if (event.text.unicode == '\r') {
            this->finished = true;
            return 0;
        } else {
            if (event.text.unicode >= 48 && event.text.unicode <= 57)
                inputText += event.text.unicode;
        }
        text.setString(inputText);
        return 1;
    }
    return 1;
}

sf::Vector2f TextBox::getPosition()
{
    return this->box.getPosition();
}
