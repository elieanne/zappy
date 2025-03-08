/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "Button.hpp"
#include "Map.hpp"
#include "IObjects.hpp"
#include "ICharacters.hpp"
#include "Data.hpp"

namespace gui
{
    class SceneManager; // Forward declaration
}

class IScene
{
public:
    virtual ~IScene() noexcept = default;
    /*
     * @brief Load the scene
     */
    virtual void loadScene(gui::SceneManager &manager, gui::Window &window, gui::Data &data) = 0;
    /*
     * @brief Display the scene
     * @param window The window where the scene will be displayed
     */
    virtual void display(gui::SceneManager &manager, gui::Window &window, gui::Data &data) = 0;
    /*
     * @brief Check the events of the scene
     * @param window The window where the events will be checked
     */
    virtual void checkEvents(gui::SceneManager &manager, gui::Window &window, gui::Data &data) = 0;
    /*
     * @brief Create the objects of the scene
     */
    virtual void createObject(gui::Data &data) = 0;
};

#endif /* !ISCENE_HPP_ */
