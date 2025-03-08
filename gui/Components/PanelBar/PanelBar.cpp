/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** PanelBar
*/

#include "PanelBar.hpp"
#include "Errors.hpp"

int getFacingRectByColor(const std::string &color);

gui::PanelBar::PanelBar(sf::Vector2f posParams)
{
    this->pos = posParams;
    if (!(this->font.loadFromFile("./gui/Resources/RationalInteger.ttf")))
        throw Errors::ErrorTexture("Error: could not load font");
}

void gui::PanelBar::display(sf::RenderWindow &window, sf::Sprite &sprite)
{
    sprite.setTextureRect(sf::IntRect(0, 10, 600, 780));
    sprite.setScale(1, 1);
    sprite.setPosition(this->pos);
    window.draw(sprite);
}

gui::Camera &gui::PanelBar::getCamera()
{
    return this->camera;
}

sf::Text gui::PanelBar::createText(const std::string &value, const sf::Vector2f &pos)
{
    sf::Text text;
    text.setString(value);
    text.setFont(this->font);
    text.setFillColor(sf::Color::White);
    text.setPosition(pos);
    return text;
}

void gui::PanelBar::setRessourcesText(std::vector<infos> &resources)
{
    std::array<std::string, 7> resText = {"Food: x", "Linemate: x", "Deraumere: x", "Sibur: x", "Mendiane: x", "Phiras: x", "Thystame: x"};
    this->resourcesText.clear();
    for (int i = 0; i < 7; i++)
        this->resourcesText.push_back(createText(resText[i] + std::to_string(resources[i].obj), sf::Vector2f(-320, 160 + i * 70)));
}

void gui::PanelBar::setInventoryText(ICharacters &character)
{
    this->resourcesInvText.clear();
    for (int i = 0; i < 7; i++) {
        sf::Text text;
        text.setString("x" + std::to_string(character.getInventory()[i]));
        text.setFont(this->font);
        text.setFillColor(sf::Color::White);
        if (i == 0)
            text.setPosition(sf::Vector2f(1175, 500));
        if (i >= 1 && i <= 3)
            text.setPosition(sf::Vector2f(1065 + (i - 1) * 110, 560));
        if (i >= 4 && i <= 6)
            text.setPosition(sf::Vector2f(1065 + (i - 4) * 110, 620));
        this->resourcesInvText.push_back(text);
    }
    this->facingRectColor = getFacingRectByColor(character.getColor());
    this->resourcesInvText.push_back(createText("Team: " + character.getTeamName(), sf::Vector2f(1085, 400)));
    this->resourcesInvText.push_back(createText("Id: " + std::to_string(character.getId()), sf::Vector2f(1135, 450)));
    this->playerLevel = character.getLevel();
}

void gui::PanelBar::displayRessourcesText(gui::Window &window, gui::ItemDrawer &drawer)
{
    int idx = 0;

    for (auto &text : this->resourcesText) {
        window.getWindow().draw(text);
        drawer.drawItem(window.getWindow(), idx, text.getPosition().x + 200, text.getPosition().y - 10, 0.6);
        idx++;
    }
}

void gui::PanelBar::displayInventoryText(gui::Window &window, gui::ItemDrawer &drawer, sf::Sprite &sprite)
{
    int idx = 0;

    sprite.setTextureRect(sf::IntRect(50, this->facingRectColor, 240, 240));
    sprite.setScale(0.7, 0.7);
    sprite.setPosition(sf::Vector2f(1115, 170));
    window.getWindow().draw(sprite);
    displayRessourcesText(window, drawer);
    drawer.drawLevel(window.getWindow(), this->playerLevel - 1, 1115, 300, 0.6);
    for (auto &text : this->resourcesInvText) {
        window.getWindow().draw(text);
        if (text.getString().toAnsiString().find("Team") != std::string::npos || text.getString().toAnsiString().find("Id") != std::string::npos)
            continue;
        drawer.drawItem(window.getWindow(), idx, text.getPosition().x - 50, text.getPosition().y - 10, 0.6);
        idx++;
    }
}
