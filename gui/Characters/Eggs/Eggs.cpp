/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Eggs
*/

#include "Eggs.hpp"
#include "Map.hpp"
#include "Errors.hpp"

static std::vector<sf::IntRect> rectEggs = {
    sf::IntRect(95, 6599, 105, 83), // TypeEggs::POURPRE
    sf::IntRect(95, 6682, 105, 83), // TypeEggs::BLUE
    sf::IntRect(95, 6765, 105, 83), // TypeEggs::YELLOW
    sf::IntRect(95, 6848, 105, 83), // TypeEggs::ICE
    sf::IntRect(95, 6931, 105, 83), // TypeEggs::PURPLE
    sf::IntRect(95, 7014, 105, 83), // TypeEggs::GREEN
    sf::IntRect(95, 7097, 105, 83) // TypeEggs::WHITE
};

const sf::Vector2f &Eggs::getPos()
{
    return this->pos;
}

void Eggs::setLaying(bool layingParams)
{
    this->laying = layingParams;
}

const bool &Eggs::isAlive()
{
    return this->alive;
}

void Eggs::setAlive(bool aliveParams)
{
    this->alive = aliveParams;
}

void Eggs::setLevel(int levelParams)
{
    this->level = levelParams;
}

const int &Eggs::getLevel()
{
    return this->level;
}

const std::string &Eggs::getTeamName()
{
    return this->teamName;
}

const bool &Eggs::isBroadcasting()
{
    return this->broadcasting;
}

void Eggs::setBroadcasting(bool broadcastingParams)
{
    this->broadcasting = broadcastingParams;
    this->soundRadius = 0;
}

void Eggs::setInventory(__attribute__((unused)) const std::array<int, 7> &res)
{
}

void Eggs::setPos(sf::Vector2f posParams, __attribute__((unused)) Orientation orientation)
{
    this->pos = posParams;
}

static sf::IntRect findRectEggs(TypeEggs typeParams)
{
    return rectEggs[static_cast<int>(typeParams)];
}

const int &Eggs::getId()
{
    return this->id;
}

TypeEggs Eggs::randomColor(gui::Data &data)
{
    std::vector<std::string> teamsNames;
    for (auto &team : data.getTeams())
        teamsNames.push_back(team.getName());
    std::vector<TypeEggs> colors = {TypeEggs::POURPRE, TypeEggs::ICE, TypeEggs::YELLOW, TypeEggs::GREEN, TypeEggs::BLUE, TypeEggs::PURPLE};
    std::vector<std::string>::iterator itr = std::find(teamsNames.begin(), teamsNames.end(), this->teamName);
    int teamIndex = std::distance(teamsNames.begin(), itr);

    return colors[teamIndex % colors.size()];
}


Eggs::Eggs(sf::Vector2f posParams, int idParams, std::string teamNameParams, gui::Data &data, Orientation orientationParams)
{
    this->teamName = teamNameParams;
    this->type = randomColor(data);
    this->pos = posParams;
    this->id = idParams;
    this->rect = findRectEggs(this->type);
    this->initial = this->rect;
    this->level = 0;
    this->alive = true;
    this->laying = false;
    this->clock.restart();
    this->orientation = orientationParams;
    this->broadcasting = false;
    this->soundRadius = 0;
}

void Eggs::display(sf::RenderWindow &window, sf::Sprite &sprite, __attribute__((unused)) gui::ItemDrawer &drawer, __attribute__((unused)) int timeUnit, SoundBox &soundBox)
{
    int posX = (this->pos.x * TILE_SIZE) + TILE_SIZE / 2;
    int posY = (this->pos.y * TILE_SIZE) + TILE_SIZE / 2;
    sprite.setTextureRect(this->rect);
    sprite.setPosition(sf::Vector2f(posX, posY));
    sprite.setOrigin(sf::Vector2f(50, 50));
    sprite.setScale(sf::Vector2f(0.5, 0.5));
    soundBox.play("spawn");
    window.draw(sprite);
}

CharacterType Eggs::getType() const
{
    return CharacterType::Egg;
}

const int &Eggs::getRectLeft()
{
    return this->rect.left;
}

void Eggs::animate(sf::Sprite &sprite)
{
    sf::Time time = this->clock.getElapsedTime();

    if (this->alive) {
        if (time.asSeconds() >= 0.9) {
            this->rect.left += this->initial.width;
            if (this->rect.left >= this->initial.left + (this->initial.width * 4))
                this->rect.left = this->initial.left;
            sprite.setTextureRect(this->rect);
            this->clock.restart();
        }
    } else {
        if (time.asSeconds() >= 0.2) {
            this->rect.left += this->initial.width;
            if (this->rect.left >= this->initial.left + (this->initial.width * 7))
                this->rect.left = (this->initial.left + (this->initial.width * 7));
            sprite.setTextureRect(this->rect);
            this->clock.restart();
        }
    }
}

const Orientation &Eggs::getOrientation()
{
    return this->orientation;
}

void Eggs::setElevating(int __attribute__((unused))elevating)
{
    return;
}

const std::string &Eggs::getColor()
{
    throw Errors::ErrorColor("Eggs have no color");
}

const std::array<int, 7> &Eggs::getInventory()
{
    throw Errors::ErrorInventory("Eggs have no inventory");
}
