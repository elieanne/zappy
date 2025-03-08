/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Players
*/

#ifndef PLAYERS_HPP_
#define PLAYERS_HPP_
    #include "ICharacters.hpp"
    #include "Data.hpp"
    #include <unordered_map>

static std::unordered_map<std::string, sf::Color> broadcastColor = {
    {"red", sf::Color(242, 14, 27, 155)},
    {"yellow", sf::Color(242, 228, 24, 155)},
    {"green", sf::Color(34, 239, 23, 155)},
    {"blue", sf::Color(32, 173, 240, 155)},
    {"darkBlue", sf::Color(17, 21, 238, 155)},
    {"purple", sf::Color(183, 21, 243, 155)},
};

/**
* @brief Players class
* @class Players
*/
class Players : public ICharacters {
    public:
        /**
        * @brief Construct a new Players object
        * @param rect
        * @param pos
        */
        Players(sf::IntRect rect, sf::Vector2f pos);
        /**
        * @brief Construct a new Players object
        * @param pos
        * @param id
        * @param level
        * @param teamName
        * @param orientation
        * @param data
        * @param broadcastingParams
        */
        Players(sf::Vector2f pos, int id, int level, const std::string &teamName, Orientation orientation, gui::Data &data, bool broadcastingParams);
        /**
        * @brief Destroy the Players object
        */
        ~Players() noexcept override = default;
        /**
        * @brief Construct a new Players object by copy deleted
        * @param other
        */
        Players(const Players& other) = delete;
        /**
        * @brief Construct a new Players object by move
        * @param other
        */
        Players(Players&& other) = default;
        /**
        * @brief Assign a Players object by copy deleted
        * @param other
        * @return Players&
        */
        Players& operator=(const Players& other) = delete;
        /**
        * @brief Assign a Players object by move
        * @param other
        * @return Players&
        */
        Players& operator=(Players&& other) = default;
        /**
        * @brief Get the Type of the Characters
        * @return CharacterType
        */
        [[nodiscard]] CharacterType getType() const override;
        /**
        * @brief Get the Rect Left of the Player
        * @return const int&
        */
        [[nodiscard]] const int &getRectLeft() override;
        /**
         * @brief Display the Player
         * @param window
         * @param sprite
         * @param drawer
         * @param timeUnit
         * @param soundbox
         */
        void display(sf::RenderWindow &window, sf::Sprite &sprite, gui::ItemDrawer &drawer, int timeUnit, SoundBox &soundbox) override;
        /**
        * @brief Animate the Player
        * @param sprite
        */
        void animate(sf::Sprite &sprite) override;
        /**
        * @brief Get the Id of the Player
        * @return const int&
        */
        [[nodiscard]] const int &getId() override;
        /**
        * @brief Set the Pos of the Player
        * @param pos
        * @param orientation
        */
        void setPos(sf::Vector2f pos, Orientation orientation) override;
        /**
        * @brief Set the Level of the Player
        * @param level
        */
        void setLevel(int level) override;
        /**
        * @brief Get the Level of the Player
        * @return const int&
        */
        [[nodiscard]] const int &getLevel() override;
        /**
        * @brief Get the Team Name of the Player
        * @return const std::string&
        */
        [[nodiscard]] const std::string &getTeamName() override;
        /**
        * @brief Get the Color of the Player
        * @return const std::string&
        */
        [[nodiscard]] const std::string &getColor() override;
        /**
        * @brief Set the Inventory of the Player
        * @param res
        */
        void setInventory(const std::array<int, 7> &res) override;
       /**
       * @brief Get the Inventory of the Player
       * @return std::array<int, 7>&
       */
        [[nodiscard]] const std::array<int, 7> &getInventory() override;
        /**
         * @brief Check if the Player is Alive
         * @return true
         * @return false
         */
        [[nodiscard]] const bool &isAlive() override;
        /**
        * @brief Set the Alive boolean of the Player
        * @param alive
        */
        void setAlive(bool alive) override;
        /**
         * @brief Set the Laying boolean of the Player
         * @param laying
         */
        void setLaying(bool laying) override;
        /**
         * @brief Set the Elevating process of the Player
         * @param elevating
         */
        void setElevating(int elevating) override;
        /**
        * @brief Check if the Player is Broadcasting
        * @return true
        * @return false
        */
        [[nodiscard]] const bool &isBroadcasting() override;
        /**
        * @brief Set the Broadcasting boolean of the Player
        * @param broadcasting
        */
        void setBroadcasting(bool broadcasting) override;
        /**
        * @brief Get the Pos of the Player
        * @return sf::Vector2f
        */
        [[nodiscard]] const sf::Vector2f &getPos() override;
        /**
        * @brief Get a random color
        * @param data
        * @return std::string
        */
        std::string randomColor(gui::Data &data);
        /**
        * @brief Get the Orientation of the Player
        * @return const Orientation&
        */
        [[nodiscard]] const Orientation &getOrientation() override;
    private:
        /**
        * @private @var std::string color
        */
        std::string color;
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
        * @private @var sf::Clock clock
        */
        sf::Clock clock;
        /**
        * @private @var sf::Clock broadcastClock
        */
        sf::Clock broadcastClock;
        /**
        * @private @var sf::Clock elevateClock
        */
        sf::Clock elevateClock;
        /**
         * @private @var sf::Clock foodClock
         */
        sf::Clock foodClock;
        /**
        * @private @var sf::CircleShape circle
        */
        sf::CircleShape circle;
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
        * @private @var bool broadcasting
        */
        bool broadcasting;
        /**
        * @private @var int elevating
        */
        int elevating;
        /**
        * @private @var int soundRadius
        */
        int soundRadius;
        /**
        * @private @var std::string teamName
        */
        std::string teamName;
        /**
        * @private @var Orientation orientation
        */
        Orientation orientation;
        /**
        * @private @var std::array<int, 7> inventory
        */
        std::array<int, 7> inventory{0, 0, 0, 0, 0, 0, 0};
};

#endif /* !PLAYERS_HPP_ */
