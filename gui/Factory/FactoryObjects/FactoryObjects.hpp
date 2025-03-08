/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** FactoryObjects
*/

#ifndef FACTORYOBJECTS_HPP_
#define FACTORYOBJECTS_HPP_
    #include "AFactory.hpp"

class FactoryObjects : public AFactory {
    public:
        FactoryObjects() = default;
        ~FactoryObjects() noexcept = default;
        FactoryObjects(const FactoryObjects& other) = delete;
        FactoryObjects(FactoryObjects&& other) = default;
        FactoryObjects& operator=(const FactoryObjects& other) = delete;
        FactoryObjects& operator=(FactoryObjects&& other) = default;
};

#endif /* !FACTORYOBJECTS_HPP_ */
