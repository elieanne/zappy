/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneWin
*/

#ifndef SCENEWIN_HPP_
#define SCENEWIN_HPP_

#include "IScene.hpp"

class SceneWin : public IScene {
    public:
        /**
        * @brief Construct a new Scene Win object
        */
        SceneWin() = default;
        /**
        * @brief Destroy the Scene Win object
        */
        ~SceneWin() noexcept override = default;
        /**
        * @brief Construct a new Scene Win object by copy
        * @param other
        */
        SceneWin(const SceneWin &other) = delete;
        /**
        * @brief Assign a Scene Win object by copy
        * @param other
        * @return SceneWin&
        */
        SceneWin &operator=(const SceneWin &other) = delete;
        /**
        * @brief Construct a new Scene Win object by move
        * @param other
        */
        SceneWin(SceneWin &&other) = default;
        /**
        * @brief Assign a Scene Win object by move
        * @param other
        * @return SceneWin&
        */
        SceneWin &operator=(SceneWin &&other) = default;
        /**
        * @brief Load the scene
        * @param window The window where the scene will be loaded
        * @param data The data of the game
        * @param manager The scene manager
        * @throw Errors::ErrorFont
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
        */
        void createObject(__attribute__((unused)) gui::Data &data) override{};

    private:
        sf::SoundBuffer buffer;
        sf::Sound sound;
        gui::Camera camera{0, 0};
        sf::Text winText;
        sf::Text haswonText;
        sf::Font font;
};

#endif /* !SCENEWIN_HPP_ */
