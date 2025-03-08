/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** FactoryObjects
*/

#ifndef FACTORYPLAYERS_HPP_
#define FACTORYPLAYERS_HPP_
    #include "AFactory.hpp"

/**
* @brief FactoryPlayers class
* @class FactoryPlayers
*/
class FactoryPlayers : public AFactory {
    public:
        /**
        * @brief Construct a new Factory Players object
        */
        FactoryPlayers() = default;
        /**
        * @brief Destroy the Factory Players object
        */
        ~FactoryPlayers() noexcept = default;
        /**
        * @brief Construct a new Factory Players object by copy = delete
        * @param other
        */
        FactoryPlayers(const FactoryPlayers& other) = delete;
        /**
        * @brief Construct a new Factory Players object by move
        * @param other
        */
        FactoryPlayers(FactoryPlayers&& other) = default;
        /**
        * @brief Assign a Factory Players object by copy = delete
        * @param other
        * @return FactoryPlayers&
        */
        FactoryPlayers& operator=(const FactoryPlayers& other) = delete;
        /**
        * @brief Assign a Factory Players object by move
        * @param other
        * @return FactoryPlayers&
        */
        FactoryPlayers& operator=(FactoryPlayers&& other) = default;
        /**
        * @brief Create a Characters object
        * @tparam T
        * @tparam Args
        * @param args
        * @return std::unique_ptr<T>
        */
        template <typename T, typename... Args>
        std::unique_ptr<T> createPlayers(Args&&... args)
        {
            return std::make_unique<T>(std::forward<Args>(args)...);
        }
    };

#endif /* !FACTORYPLAYERS_HPP_ */
