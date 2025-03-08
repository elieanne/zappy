/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_
    #include <vector>
    #include <memory>
    #include "IObjects.hpp"
    #include "ICharacters.hpp"
    #include "Map.hpp"
    #include "FactoryObjects.hpp"
    #include "FactoryPlayers.hpp"
    #include "myStruct.h"
    #include "Team.hpp"
    #include "TextBox.hpp"


namespace gui {
    /**
    * @brief Data class
    * @class Data
    */
    class Data {
        public:
            /**
            * @brief Construct a new Data object
            */
            Data() = default;
            /**
            * @brief Destroy the Data object
            */
            ~Data() noexcept = default;
            /**
            * @brief Construct a new Data object by move
            */
            Data(Data &&) = default;
            /**
            * @brief Assign a Data object by move
            * @return Data&
            */
            Data &operator=(Data &&) = default;
            /**
            * @brief Construct a new Data object by copy
            */
            Data(const Data &) = delete;
            /**
            * @brief Assign a Data object by copy
            * @return Data&
            */
            Data &operator=(const Data &) = delete;
            /**
            * @brief Get the Map object
            * @return Map&
            */
            [[nodiscard]] Map &getMap();
            /**
            * @brief Get the Characters
            * @return std::vector<std::unique_ptr<ICharacters>>&
            */
            [[nodiscard]] std::vector<std::unique_ptr<ICharacters>> &getCharacters();
            /**
            * @brief Get the Teams
            * @return std::vector<gui::Team>&
            */
            [[nodiscard]] std::vector<gui::Team> &getTeams();
            /**
            * @brief Get the Character By Id
            * @param id
            * @return ICharacters&
            * @throw Errors::ErrorCharacter
            */
            [[nodiscard]] ICharacters &getCharacterById(int id);
            /**
            * @brief Get the Team By Name
            * @param name
            * @return gui::Team&
            * @throw Errors::ErrorTeam
            */
            [[nodiscard]] gui::Team &getTeamByName(const std::string &name);
            /**
            * @brief Get the Team Name By Player Id
            * @param id
            * @return const std::string&
            * @throw Errors::ErrorTeam
            */
            [[nodiscard]] const std::string &getTeamNameByPlayerId(int id);
            /**
            * @brief Get the Factory Characters
            * @return FactoryPlayers&
            */
            [[nodiscard]] FactoryPlayers &getFactoryCharacters();
            /**
            * @brief Get the Text Box
            * @return TextBox&
            */
            [[nodiscard]] TextBox &getTextBox();
            /**
             * @brief Check if the player is in the game
             * @param id
             * @return true
             * @return false
             */
            bool isPlayer(int id);
            /**
            * @brief Check if the team is in the game
            * @param name
            * @return true
            * @return false
            */
            bool isTeam(const std::string &name);
            /**
            * @brief Set the Frequency
            * @param frequency
            */
            void setFrequency(int frequency);
            /**
            * @brief Get the Winning Team
            * @return std::string&
            */
            [[nodiscard]] const std::string &getWinningTeam();
            /**
            * @brief Set the Winning Team
            * @param team
            */
            void setWinningTeam(const std::string &team);
            /**
            * @brief Get the Frequency
            * @return int
            */
            [[nodiscard]] const int &getFrequency();
            /**
            * @brief Set the Map Frame
            * @param frame
            */
            void setMapFrame(int frame);
            /**
            * @brief Get the Map Frame
            * @return int
            */
            [[nodiscard]] const int &getMapFrame();
            /**
            * @brief Set the Tiles Rect
            * @param rect
            */
            void setTilesRect(int rect);
            /**
            * @brief Get the Tiles Rect
            * @return int
            */
            [[nodiscard]] const int &getTilesRect();
        private:
            /**
            * @private @var gui::Map map
            */
            gui::Map map;
            /**
            * @private @var std::vector<std::unique_ptr<ICharacters>> characters
            */
            std::vector<std::unique_ptr<ICharacters>> characters;
            /**
             * @private @var FactoryPlayers factoryCharacters
             */
            FactoryPlayers factoryCharacters;
            /**
            * @private @var std::vector<gui::Team> teams
            */
            std::vector<gui::Team> teams;
            /**
            * @private @var int timeUnit
            */
            int timeUnit;
            /**
            * @private @var int mapFrame
            */
            int mapFrame{0};
            /**
            * @private @var tilesRect
            */
            int tilesRect{0};
            /**
            * @private @var std::string winningTeam
            */
            std::string winningTeam{""};
            /**
            * @private @var TextBox textBox
            */
            TextBox textBox;
    };
}

#endif /* !DATA_HPP_ */
