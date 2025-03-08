/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneMenu
*/

#ifndef SCENEMENU_HPP_
#define SCENEMENU_HPP_
#include "IScene.hpp"
#include "Parallax.hpp"

/**
* @brief SceneMenu class
* @class SceneMenu
*/
class SceneMenu : public IScene {
    public:
        /**
        * @brief Construct a new Scene Menu object
        */
        SceneMenu() = default;
        /**
        * @brief Destroy the Scene Menu object
        */
        ~SceneMenu() noexcept override = default;
        /**
        * @brief Construct a new Scene Menu object by copy
        * @param other
        */
        SceneMenu(const SceneMenu &other) = delete;
        /**
        * @brief Assign a Scene Menu object by copy
        * @param other
        * @return SceneMenu&
        */
        SceneMenu &operator=(const SceneMenu &other) = delete;
        /**
        * @brief Construct a new Scene Menu object by move
        * @param other
        */
        SceneMenu(SceneMenu &&other) = default;
        /**
        * @brief Assign a Scene Menu object by move
        * @param other
        * @return SceneMenu&
        */
        SceneMenu &operator=(SceneMenu &&other) = default;
        /**
        * @brief Load the scene
        * @param window The window where the scene will be loaded
        * @param data The data of the game
        * @param manager The scene manager
        * @throw Error::ErrorTexture
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
        * @private @var gui::Parallax parallax
        */
        gui::Parallax parallax;
        /**
        * @private @var sf::Texture texture
        */
        sf::Texture texture;
        /**
        * @private @var sf::Sprite sprite
        */
        sf::Sprite connexionSprite;
        /**
        * @private @var sf::Texture textureLogo
        */
        sf::Texture textureLogo;
        /**
        * @private @var sf::Sprite sprite
        */
        sf::Sprite logo;
        /**
        * @private @var gui::Camera camera
        */
        gui::Camera camera{0, 0};
};

#endif /* !SCENEMENU_HPP_ */
