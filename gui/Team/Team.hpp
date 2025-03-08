/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Team
*/

#ifndef TEAM_HPP_
#define TEAM_HPP_
    #include <string>
    #include <vector>
    #include "ICharacters.hpp"

namespace gui {
    /**
    * @brief Team class
    * @class Team
    */
    class Team {
        public:
            /**
            * @brief Construct a new Team object
            */
            Team() = default;
            /**
            * @brief Construct a new Team object
            * @param name
            */
            explicit Team(const std::string &name) : name(name) {};
            /**
            * @brief Construct a new Team object by copy
            * @param other
            */
            Team(const Team &other) = delete;
            /**
            * @brief Assign a Team object by copy
            * @param other
            * @return Team&
            */
            Team &operator=(const Team &other) = delete;
            /**
            * @brief Construct a new Team object by move
            * @param other
            */
            Team(Team &&other) = default;
            /**
            * @brief Assign a Team object by move
            * @param other
            * @return Team&
            */
            Team &operator=(Team &&other) = default;
            /**
            * @brief Destroy the Team object
            */
            ~Team() noexcept = default;
            /**
            * @brief Get the Name
            * @return const std::string&
            */
            [[nodiscard]] const std::string &getName() const;
            /**
             * @brief Add a character to the team
             * @param id
             */
            void addCharacter(const int &id);

          private:
            /**
            * @private @var std::string name
            */
            std::string name{""};
            /**
            * @private @var std::vector<int> characters
            */
            std::vector<int> characters;
    };
}

#endif /* !TEAM_HPP_ */
