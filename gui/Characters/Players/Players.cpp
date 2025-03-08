/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Players
*/

#include "Players.hpp"
#include <algorithm>
#include <random>

constexpr char PATH_GOLEM[] = "./gui/Resources/golem_spritesheet.png";

int getRightRect(const std::string& color, Orientation orientation);

const int& Players::getId()
{
    return this->id;
}

const sf::Vector2f &Players::getPos()
{
    return this->pos;
}

const bool &Players::isAlive()
{
    return this->alive;
}

void Players::setAlive(bool aliveParams)
{
    this->alive = aliveParams;
}

void Players::setLaying(bool layingParams)
{
    this->laying = layingParams;
}

const bool &Players::isBroadcasting()
{
    return this->broadcasting;
}

void Players::setBroadcasting(bool broadcastingParams)
{
    this->broadcasting = broadcastingParams;
    this->soundRadius = 0;
}

std::string Players::randomColor(gui::Data& data)
{
    std::vector<std::string> teamsNames;
    for (auto& team : data.getTeams())
        teamsNames.push_back(team.getName());
    std::vector<std::string> colors = {"red", "blue", "yellow", "green", "darkBlue", "purple"};
    std::vector<std::string>::iterator itr = std::find(teamsNames.begin(), teamsNames.end(), this->teamName);
    int teamIndex = std::distance(teamsNames.begin(), itr);

    return colors[teamIndex % colors.size()];
}

const std::string& Players::getColor()
{
    return this->color;
}

Players::Players(sf::Vector2f posParams, int idParams, int levelParams, const std::string& path, Orientation orientationParams, gui::Data& data, bool broadcastingParams)
{
    this->orientation = orientationParams;
    this->pos = sf::Vector2f(posParams.x, posParams.y);
    this->id = idParams;
    this->level = levelParams;
    this->inventory = { 10, 0, 0, 0, 0, 0, 0 };
    this->teamName = path;
    this->color = randomColor(data);
    this->rect = sf::IntRect(50, getRightRect(this->color, this->orientation), 240, 240);
    this->initial = this->rect;
    this->alive = true;
    this->laying = false;
    this->clock.restart();
    this->soundRadius = 0;
    this->broadcasting = broadcastingParams;
    this->elevating = 0;
    this->elevateClock.restart();
    this->broadcastClock.restart();
    this->elevateClock.restart();
    this->foodClock.restart();
    this->circle.setFillColor(sf::Color::Transparent);
    this->circle.setOutlineColor(broadcastColor[this->color]);
    this->circle.setOutlineThickness(5);
}

Players::Players(sf::IntRect rectParams, sf::Vector2f posParams)
{
    this->rect = rectParams;
    this->pos = sf::Vector2f(posParams.x, posParams.y);
    this->initial = this->rect;
    this->alive = true;
    this->laying = false;
    this->teamName = "";
    this->inventory = { 10, 0, 0, 0, 0, 0, 0 };
    this->orientation = Orientation::North;
    this->soundRadius = 0;
    this->broadcasting = false;
    this->level = 1;
    this->clock.restart();
    this->broadcastClock.restart();
    this->elevateClock.restart();
    this->foodClock.restart();
    this->circle.setFillColor(sf::Color::Transparent);
    this->circle.setOutlineColor(broadcastColor[this->color]);
    this->circle.setOutlineThickness(5);
}

void Players::animate(sf::Sprite& sprite)

{
    sf::Time time = this->clock.getElapsedTime();
    sf::Time broadcastTime = this->broadcastClock.getElapsedTime();

    if (this->soundRadius == 2500) {
        this->broadcasting = false;
        this->soundRadius = 0;
    }
    if (broadcasting == true && broadcastTime.asSeconds() >= 0.01) {
        this->soundRadius += 10;
        this->broadcastClock.restart();
    }

    if (alive) {
        if (time.asSeconds() >= 0.3) {
            this->rect.left += this->initial.width;
            if (this->rect.left >= this->initial.left + (this->initial.width * 4))
                this->rect.left = this->initial.left;
            sprite.setTextureRect(this->rect);
            this->clock.restart();
        }
    } else {
        if (time.asSeconds() >= 0.3) {
            this->rect.left += this->initial.width;
            if (this->rect.left >= this->initial.left + (this->initial.width * 7))
                this->rect.left = (this->initial.left + (this->initial.width * 7));
            sprite.setTextureRect(this->rect);
            this->clock.restart();
        }
    }
}

const int& Players::getRectLeft()
{
    return this->rect.left;
}

CharacterType Players::getType() const
{
    return CharacterType::Player;
}

void Players::display(sf::RenderWindow& window, sf::Sprite& sprite, gui::ItemDrawer &drawer, int timeUnit, SoundBox &soundBox)
{
    int posX = (this->pos.x * TILE_SIZE);
    int posY = (this->pos.y * TILE_SIZE);

    if (elevating == 1) {
        this->elevateClock.restart();
        this->elevating = 2;
    }

    sprite.setTextureRect(this->rect);
    sprite.setPosition(sf::Vector2f(posX + 15, posY + 15));
    sprite.setScale(sf::Vector2f(0.25, 0.25));
    sprite.setOrigin(sf::Vector2f(50, 50));
    window.draw(sprite);
    if (this->broadcasting == true) {
        this->circle.setRadius(this->soundRadius);
        this->circle.setOrigin(sf::Vector2f(this->soundRadius, this->soundRadius));
        this->circle.setPosition(posX + (TILE_SIZE / 2), posY + (TILE_SIZE / 2));
        window.draw(this->circle);
    }

    if (this->elevateClock.getElapsedTime().asSeconds() <= (300 / timeUnit) && this->elevating == 2) {
        drawer.drawLevel(window, this->level, posX + (TILE_SIZE / 2) - 17, posY + TILE_SIZE - 26, 0.2);
    }
    if (this->elevateClock.getElapsedTime().asSeconds() >= (300 / timeUnit) && this->elevating == 2) {
        soundBox.play("elevate");
        this->elevating = 0;
        this->elevateClock.restart();
    }

    if (this->foodClock.getElapsedTime().asSeconds() >= (static_cast<float>(126) / static_cast<float>(timeUnit))) {
        if (this->inventory[0] > 0)
            this->inventory[0] -= 1;
        this->foodClock.restart();
    }
}

void Players::setPos(sf::Vector2f posParams, Orientation orientationParams)
{
    this->orientation = orientationParams;
    this->pos = sf::Vector2f(posParams.x, posParams.y);
    this->rect.top = getRightRect(this->color, this->orientation);
}

void Players::setLevel(int levelParams)
{
    this->level = levelParams;
}

const int& Players::getLevel()
{
    return this->level;
}

const std::string& Players::getTeamName()
{
    return this->teamName;
}

void Players::setInventory(const std::array<int, 7>& res)
{
    this->inventory = res;
}

const std::array<int, 7>& Players::getInventory()
{
    return this->inventory;
}

const Orientation &Players::getOrientation()
{
    return this->orientation;
}
void Players::setElevating(int elevating)
{
    this->elevating = elevating;
}
