/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneSettings
*/

#ifndef SCENESETTINGS_HPP_
#define SCENESETTINGS_HPP_
#include "IScene.hpp"

/**
* @brief Settings scene class
* @class SceneSettings
*/
class SceneSettings : public IScene {
    public:
        /**
        * @brief Construct a new Scene Settings object
        */
        SceneSettings() = default;
        /**
        * @brief Destroy the Scene Settings object
        */
        ~SceneSettings() noexcept override = default;
        /**
        * @brief Construct a new Scene Settings object by copy
        * @param other
        */
        SceneSettings(const SceneSettings &other) = delete;
        /**
        * @brief Assign a Scene Settings object by copy
        * @param other
        * @return SceneSettings&
        */
        SceneSettings &operator=(const SceneSettings &other) = delete;
        /**
        * @brief Construct a new Scene Settings object by move
        * @param other
        */
        SceneSettings(SceneSettings &&other) = default;
        /**
        * @brief Assign a Scene Settings object by move
        * @param other
        * @return SceneSettings&
        */
        SceneSettings &operator=(SceneSettings &&other) = default;
        /**
        * @brief Load the scene
        * @param window The window where the scene will be loaded
        * @param data The data of the game
        * @param manager The scene manager
        */
        void loadScene(gui::SceneManager &manager, gui::Window &window, gui::Data &data) override;
        /**
        * @brief Display the scene
        * @param window The window where the scene will be displayed
        * @param data The data of the game
        * @param manager The scene manager
        */
        void display(gui::SceneManager &manager, gui::Window &window, gui::Data &data) override;
        /**
        * @brief Check the events of the scene
        * @param window The window where the events will be checked
        * @param data The data of the game
        * @param manager The scene manager
        */
        void checkEvents(gui::SceneManager &manager, gui::Window &window, gui::Data &data) override;
        /**
        * @brief Create the objects of the scene
        * @param data The data of the game
        */
        void createObject(__attribute__((unused)) gui::Data &data) override{};

    private:
        /**
        * @private @var gui::Camera camera
        */
        gui::Camera camera{0, 0};
        /**
        * @private @var bool volumeChanged
        */
        bool volumeChanged {false};
};

#endif /* !SCENESETTINGS_HPP_ */
