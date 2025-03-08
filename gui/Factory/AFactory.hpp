/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** AFactory
*/

#ifndef AFACTORY_HPP_
#define AFACTORY_HPP_

/**
* @brief AFactory class
* @class AFactory
*/
class AFactory {
    public:
        /**
        * @brief Construct a new AFactory object
        */
        AFactory() = default;
        /**
        * @brief Destroy the AFactory object
        */
        ~AFactory() noexcept = default;
        /**
        * @brief Construct a new AFactory object by copy = delete
        * @param other
        */
        AFactory(const AFactory &other) = delete;
        /**
        * @brief Construct a new AFactory object by move = default
        * @param other
        */
        AFactory(AFactory &&other) = default;
        /**
        * @brief Assign a AFactory object by copy = delete
        * @param other
        * @return AFactory&
        */
        AFactory &operator=(const AFactory &other) = delete;
        /**
        * @brief Assign a AFactory object by move = default
        * @param other
        * @return AFactory&
        */
        AFactory &operator=(AFactory &&other) = default;
};

#endif /* !AFACTORY_HPP_ */
