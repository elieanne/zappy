/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Eggs
*/

#ifndef EGGS_HPP_
#define EGGS_HPP_
    #include "ICharacters.hpp"
    #include "Data.hpp"

/**
* @brief TypesEggs enum class
* @enum TypeEggs
*/
enum class TypeEggs {
    POURPRE,
    BLUE,
    YELLOW,
    ICE,
    PURPLE,
    GREEN,
    WHITE
};

/**
* @brief Eggs class
* @class Eggs
*/
class Eggs : public ICharacters {
    public:
        /**
        * @brief Construct a new Eggs object
        * @param pos
        * @param id
        * @param teamName
        * @param data
        * @param orientation
        */
        Eggs(sf::Vector2f pos, int id, std::string teamName, gui::Data &data, Orientation orientation);
        /**
        * @brief Destroy the Eggs object
        */
        ~Eggs() noexcept override = default;
        /**
        * @brief Construct a new Eggs object by copy deleted
        * @param other
        */
        Eggs(const Eggs& other) = delete;
        /**
        * @brief Construct a new Eggs object by move
        * @param other
        */
        Eggs(Eggs&& other) = default;
        /**
        * @brief Assign a Eggs object by copy deleted
        * @param other
        * @return Eggs&
        */
        Eggs& operator=(const Eggs& other) = delete;
        /**
        * @brief Assign a Eggs object by move
        * @param other
        * @return Eggs&
        */
        Eggs& operator=(Eggs&& other) = default;
        /**
        * @brief Get the Type of the ICharacters
        * @return CharacterType
        */
        [[nodiscard]] CharacterType getType() const override;
        /**
        * @brief Get the Rect Left of the Eggs
        * @return const int&
        */
        [[nodiscard]] const int &getRectLeft() override;
        /**
         * @brief Display the Eggs
         * @param window
         * @param sprite
         * @param drawer
         * @param timeUnit
         * @param soundbox
         */
        void display(sf::RenderWindow &window, sf::Sprite &sprite, gui::ItemDrawer &drawer, int timeUnit, SoundBox &soundBox) override;
        /**
        * @brief Animate the Eggs
        * @param sprite
        */
        void animate(sf::Sprite &sprite) override;
        /**
        * @brief Get the Id of the Eggs
        * @return const int&
        */
        [[nodiscard]] const int &getId() override;
        /**
        * @brief Set the Pos of the Eggs
        * @param pos
        * @param orientation
        */
        void setPos(sf::Vector2f pos, Orientation orientation) override;
        /**
        * @brief Set the Level of the Eggs
        * @param level
        */
        void setLevel(int level) override;
        /**
        * @brief Get the Level of the Eggs
        * @return const int&
        */
        [[nodiscard]] const int &getLevel() override;
        /**
        * @brief Choose a random color for the Eggs
        * @param data
        * @return TypeEggs
        */
        TypeEggs randomColor(gui::Data &data);
        /**
        * @brief Get the Color of the Eggs
        * @return const std::string&
        * @throw Errors::ErrorColor
        */
        [[nodiscard]] const std::string &getColor() override;
        /**
        * @brief Get the Team Name of the Eggs
        * @return const std::string&
        */
        [[nodiscard]] const std::string &getTeamName() override;
        /**
        * @brief Set the Inventory of the Eggs
        * @param res
        */
        void setInventory(const std::array<int, 7> &res) override;
        /**
        * @brief Get the Inventory of the Eggs
        * @return std::array<int, 7>&
        * @throw Errors::ErrorInventory
        */
        [[nodiscard]] const std::array<int, 7> &getInventory() override;
        /**
         * @brief Check if the Eggs is alive
         * @return true
         * @return false
         */
        [[nodiscard]] const bool &isAlive() override;
        /**
        * @brief Set the Alive boolean of the Eggs
        * @param alive
        */
        void setAlive(bool alive) override;
        /**
         * @brief Set the Laying boolean of the Eggs
         * @param laying
         */
        void setLaying(bool laying) override;
        /**
        * @brief Check if the Eggs is broadcasting
        * @return true
        * @return false
        */
        [[nodiscard]] const bool &isBroadcasting() override;
        /**
        * @brief Set the Broadcasting boolean of the Eggs
        * @param broadcasting
        */
        void setBroadcasting(bool broadcastingParams) override;
        /**
         * @brief Set the Elevating process of the Eggs
         * @param elevating
         * @throw Errors::ErrorElevate
         */
        void setElevating(int elevating) override;
        /**
        * @brief Get the Pos of the Eggs
        * @return sf::Vector2f
        */
        [[nodiscard]] const sf::Vector2f &getPos() override;
        /**
        * @brief Get the Orientation of the Eggs
        * @return const Orientation&
        */
        [[nodiscard]] const Orientation &getOrientation() override;
    private:
        /**
        * @private @var sf::IntRect rect
        */
        sf::IntRect rect;
        /**
        * @private @var sf::IntRect initial
        */
        sf::IntRect initial;
        /**
        * @private @var sf::Vector2f pos
        */
        sf::Vector2f pos;
        /**
        * @private @var TypeEggs type
        */
        TypeEggs type;
        /**
        * @private @var sf::Clock clock
        */
        sf::Clock clock;
        /**
        * @private @var int id
        */
        int id;
        /**
        * @private @var int level
        */
        int level;
        /**
        * @private @var bool alive
        */
        bool alive;
        /**
        * @private @var bool laying
        */
        bool laying;
        /**
        * @private @var std::string teamName
        */
        std::string teamName;
        /**
        * @private @var Orientation orientation
        */
        Orientation orientation;
        /**
        * @private @var bool broadcasting
        */
        bool broadcasting;
        /**
        * @private @var int soundRadius
        */
        int soundRadius;
};

#endif /* !EGGS_HPP_ */
