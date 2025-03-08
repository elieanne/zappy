/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneSkins
*/

#ifndef SCENESKINS_HPP_
#define SCENESKINS_HPP_
#include "IScene.hpp"

/**
* @brief Skins scene class
* @class SceneSkins
*/
class SceneSkins : public IScene {
    public:
        /**
        * @brief Construct a new Scene Skins object
        */
        SceneSkins() = default;
        /**
        * @brief Destroy the Scene Skins object
        */
        ~SceneSkins() noexcept override = default;
        /**
        * @brief Construct a new Scene Skins
        * @param other
        */
        SceneSkins(const SceneSkins &other) = delete;
        /**
        * @brief Assign a Scene Skins object by copy
        * @param other
        * @return SceneSkins&
        */
        SceneSkins &operator=(const SceneSkins &other) = delete;
        /**
        * @brief Construct a new Scene Skins object by move
        * @param other
        */
        SceneSkins(SceneSkins &&other) = default;
        /**
        * @brief Assign a Scene Skins object by move
        * @param other
        * @return SceneSkins&
        */
        SceneSkins &operator=(SceneSkins &&other) = default;
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
        * @brief Set Directionnal Buttons object
        * @param manager
        * @param button
        * @param data
        */
        void directionnalButtons(gui::SceneManager &manager, gui::Button &button, gui::Data &dat, gui::Window &window);
        /**
        * @private @var sf::SoundBuffer buffer
        */
        sf::SoundBuffer buffer;
        /**
        * @private @var sf::Sound sound
        */
        sf::Sound sound;
        /**
        * @private @var gui::Camera camera
        */
        gui::Camera camera{0, 0};
};

#endif /* !SCENESKINS_HPP_ */
