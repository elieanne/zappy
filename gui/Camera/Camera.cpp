/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Camera
*/

#include "Camera.hpp"

gui::Camera::Camera(unsigned int width, unsigned int height)
{
    this->view = sf::View();
    this->view.setSize(width, height);
}

void gui::Camera::setCenter(sf::Vector2f pos)
{
    this->view.setCenter(pos);
}

sf::Vector2f gui::Camera::getCenter()
{
    return this->view.getCenter();
}

void gui::Camera::setZoom(float zoom)
{
    this->zoomFactor = zoom;
    this->view.zoom(this->zoomFactor);
}

void gui::Camera::setView(sf::RenderWindow &window)
{
    window.setView(this->view);
}

sf::View &gui::Camera::getView()
{
    return this->view;
}
